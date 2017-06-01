#include <stdio.h>
#include <memory.h>
#include <assert.h>

/* ntohl(), htonl() */
#include <winsock2.h>
#include <fstream> 
#include <iostream> 
#include <stdio.h>
#include "owen_protocol.h"

/* расчет контрольной суммы */
unsigned short owenCRC16(unsigned char* packet, size_t length)
{
	size_t i, j;
	unsigned short crc;

	assert(packet);

	crc = 0;
	for (i = 0; i < length; ++i)
	{
		unsigned char b = packet[i];
		for (j = 0; j < 8; ++j, b <<= 1)
		{
			if ((b ^ (crc >> 8)) & 0x80)
			{
				crc <<= 1;
				crc ^= 0x8F57;
			}
			else
				crc <<= 1;
		}
	}
	return crc;
}

/* Быстрый алгоритм расчета контрольной суммы
	с использованием таблицы.
*/

/* таблица */
unsigned short fastCRC16Table[256];

/* инициализация таблицы*/
void initFastCRC16Table()
{
	unsigned short i, j;
	unsigned short crc;

	for (i = 0; i < 256; ++i)
	{
		unsigned short b = i;
		crc = 0;
		for (j = 0; j < 8; ++j, b <<= 1)
		{
			if ((b ^ (crc >> 8)) & 0x80)
			{
				crc <<= 1;
				crc ^= 0x8F57;
			}
			else
				crc <<= 1;
		}
		fastCRC16Table[i] = crc;
	}
}

/* быстрый расчет контрольной суммы */
unsigned short owenFastCRC16(unsigned char* packet, size_t length)
{
	size_t i;
	unsigned short crc;

	assert(packet);

	crc = 0;
    for (i = 0; i < length; ++i)
    {
        crc = (crc << 8) ^ fastCRC16Table[(crc >> 8) ^ packet[i]];
    }
   
	return crc;
}

void packFrameToAscii(unsigned char* frame, size_t frameSize, unsigned char frameAscii[maxAsciiFrameSize], size_t frameAsciiSize)
{
	size_t i, j;

	assert(frame && frameAscii);
	assert(frameAsciiSize >= frameSize*2+2+1);

	frameAscii[0] = '#';
	for (i = 0, j = 1; i < frameSize; ++i, j += 2)
	{
		frameAscii[j] = 'G' + ((frame[i] >> 4) & 0x0f);
		frameAscii[j + 1] = 'G' + (frame[i] & 0x0f);
	}
	frameAscii[frameSize*2+1] = '\xD';
	frameAscii[frameSize*2+2] = '\0';
	//std::ofstream logFile("frameAscii.txt",std::ios::out); 	
	//logFile<<frameAscii<<std::endl;
	//logFile.close();

}

void unpackAsciiFrame(char* frameAscii, size_t frameAsciiSize, unsigned char* frame, size_t frameSize)
{
	size_t i, j;

	assert(frameAscii && frame);
	assert(frameAscii[0] == '#' && frameAscii[frameAsciiSize - 1] == '\xD');
	assert((frameAsciiSize & 1) == 0);
	assert(frameSize >= (frameAsciiSize - 2)/2);

	for (i = 1, j = 0; i < frameAsciiSize-2;  i += 2, ++j)
	{
		assert('G' <= frameAscii[i]&&frameAscii[i] <= 'V');
		assert('G' <= frameAscii[i+1]&&frameAscii[i+1] <= 'V');

		frame[j] = (frameAscii[i] - 'G') << 4 | (frameAscii[i+1] - 'G');
	}
}

void appendIndexAndTime(OwenProtocolFrame* pf, short index, short time)
{
	assert(pf);
	assert((index != -1 && time != -1 && pf->dataSize <= 11) ||((index != -1 || time != -1) && pf->dataSize <= 13));

	if (time != -1)
	{
		pf->data[pf->dataSize++] = (time >> 8) & 0x0f;
		pf->data[pf->dataSize++] = time & 0x0f;
	}
	if (index != -1)
	{
		pf->data[pf->dataSize++] = (index >> 8) & 0x0f;
		pf->data[pf->dataSize++] = index & 0x0f;
	}
}

size_t packFrame(OwenProtocolFrame* pf, unsigned char* frame, size_t frameSize)
{
	unsigned short crc;

	assert(pf && frame);
	assert(frameSize >= 6);

	if (pf->addrLen == 8)
	{
		frame[0] = pf->address & 0xff;
		frame[1] = 0;
	}
	else
	{
		frame[0] = (pf->address >> 3)  & 0xff;
		frame[1] = (pf->address & 0x07) << 5;
	}

	if (pf->request)
		frame[1] |= 0x10;

	assert(pf->dataSize <= 15);
	frame[1] |= pf->dataSize;

	frame[2] = (pf->hash >> 8) & 0xff;
	frame[3] = pf->hash & 0xff;

	if (pf->dataSize)
	{
		memcpy(frame+4, pf->data, pf->dataSize);
	}
	crc = owenCRC16(frame, 4 + pf->dataSize);
	pf->crc = crc;
	pf->crc_ok = 1;

	frame[4 + pf->dataSize] = (crc >> 8) & 0xff;
	frame[5 + pf->dataSize] = crc & 0xff;

	return 6 + pf->dataSize;
}

void unpackFrame(unsigned char* frame, size_t frameSize, OwenProtocolFrame* pf)
{
	size_t dataSize;

	assert(frame && pf);
	assert(frameSize >= 6);

	/* ВНИМАНИЕ: невозможно отличить 11-битые адреса кратные 8 от 8-битных */
	if (frame[1] & 0xe0)
	{
		pf->address = (frame[0] << 3) | (frame[1] >> 5);
		pf->addrLen = 11;
	}
	else
	{
		pf->address = frame[0];
		pf->addrLen = 8;
	}

	pf->request = (frame[1] & 0x10) != 0;
	pf->hash = (frame[2] << 8) | frame[3];
	dataSize = frame[1] & 0x0F;

	if (dataSize)
	{
		assert(dataSize == frameSize - 6);

		pf->dataSize = dataSize;
		memcpy(pf->data, frame + 4, dataSize);
	}
	else
	{
		pf->dataSize = 0;
	}
	pf->crc = (frame[frameSize-2] << 8) | frame[frameSize-1];
	pf->crc_ok = pf->crc == owenCRC16(frame, frameSize-2);
}

void unpackFloat24(unsigned char* data, size_t dataSize, float* value)
{
	unsigned long t;

	assert(data);
	assert(dataSize == 3);
	assert(value);

	t = 0;
	memcpy (&t, data, 3);

	*(unsigned long*)value = ntohl(t);
}

void unpackIEEE32(unsigned char* data, size_t dataSize, float* value, int *time)
{
	assert(value && time);
	assert(dataSize == 4 || dataSize == 6);

	*(unsigned long*)value = ntohl(*(unsigned long*)data);

	/* если есть время измерения */
	if (dataSize == 6)
	{
		*time = (((data[4] & 0xff)<< 8) | (data[5] & 0xff)) & 0xffff;
	}
	else
	{
		*time = -1;
	}
}

/* unpackBCD()

	Разбор поля данных для параметров DCNT и DSPD прибора СИ8.

		value - значение счетчика
		point - позиция десятичной точки (задается параметром F в приборе)

*/
void unpackBCD(unsigned char* data, size_t dataSize, int* value, int *point)
{
	size_t i = 0;
	int val, sign;
	
	assert(value && point);
	assert(dataSize == 4);

	sign = data[0] & 0x80 ? -1 : 1;
	*point = (data[0] & 0x70) >> 4;

	val = data[0] & 0x0F;
	for (i = 1; i < dataSize ; ++i)
	{
		val *= 10;
		val += ((data[i] & 0xF0) >> 4);
		val *= 10;
		val += data[i] & 0x0F;
	}
	*value = sign*val;
}

/* преобразование локального идентификатора в двоичный вид 

		name - локальный идентификатор
		length - длина идентификатора

		id - идентификатор в двоичном виде
*/
void name2id(char* name, size_t length, unsigned char id[4])
{
	size_t i, j;

	assert(name);
	assert(length);

	for (i = 0, j = 0; i < length && j <= 4; ++i)
	{
		unsigned char b;
		char c = name[i];

		if ('0' <= c && c <= '9')
		{
			b = c - '0';
		}
		else if ('a' <= c && c <= 'z')
		{
			b = 10 + c - 'a';
		}
		else if ('A' <= c && c <= 'Z')
		{
			b = 10 + c - 'A';
		}
		else if ('-' == c)
		{
			b = 10 + 26 + 0;
		}
		else if ('_' == c)
		{
			b = 10 + 26 + 1;
		}
		else if ('/' == c)
		{
			b = 10 + 26 + 2;
		}
		else if ('.' == c)
		{
			assert(i > 0); /* модификатор не может быть первым символом */
			assert(name[i-1] != '.'); /* не может быть двух модификаторов подряд */

			++id[j - 1];

			continue;
		}
		else if (' ' == c)
		{
			break; /* пробел может находиться только в конце имени */
		}
		else
			assert(0); /* недопустимый символ */

		id[j++] = b*2;
	}

	if (j == 4)
	{
		/* заполнены все байты идентификатора */
		assert(i == length); /* обработаны все символы имени */
	}
	else
	{
		/* встречен первый пробел или обработаны все символы имени */
		for (; i < length; ++i)
		{
			assert(name[i] == ' '); /* после пробела могут находиться только пробелы */
			assert(j < 4);

			id[j++] = 78;
		}

		/* дополняем пробелами до четырех символов */
		for (; j < 4; ++j)
			id[j] = 78;
	}
}

/* свертка локального идентификатора */
unsigned short id2hash(unsigned char id[4])
{
	size_t i, j;
	unsigned short hash;

	hash = 0;
	for (i = 0; i < 4; ++i)
	{
		unsigned char b = id[i];
		b <<= 1; /* используются только младшие 7 бит */
		for (j = 0; j < 7; ++j, b <<= 1)
		{
			if ((b ^ (hash >> 8)) & 0x80)
			{
				hash <<= 1;
				hash ^= 0x8F57;
			}
			else
				hash <<= 1;
		}
	}
	return hash;
}

int qmain(int argc, char* argv[])
{
	unsigned char frame[maxFrameSize];
	unsigned char frameAscii[maxAsciiFrameSize];
	size_t frameSize;

	OwenProtocolFrame pf;

	/* вычисление hash-кода */
	unsigned char id[4];
	unsigned short rEAd;
	name2id("rEAd", 4, id);
	rEAd = id2hash(id);

	/* создание запроса для параметра rEAd */
	pf.address = 24;
	pf.addrLen = 8;
	pf.dataSize = 0;
	pf.hash = 0x8784; // rEAd
	pf.request = 1;

	frameSize = packFrame(&pf, frame, maxFrameSize);

	packFrameToAscii(frame, frameSize, frameAscii, maxAsciiFrameSize);
	/* в буфере frameAscii находится готовый запрос */

	/* ... */

	{/* разбор ответа */
		
		char frameAsciiRecv[] = {"#HOGMONOKSIKNVVQNGVUHTRGK\xD"}; 	/* примерный ответ прибора */
		
		size_t frameAsciiRecvSize = sizeof(frameAsciiRecv)/sizeof(*frameAsciiRecv) - 1;
		
		float value;
		int time;
		
		unpackAsciiFrame(frameAsciiRecv, frameAsciiRecvSize, frame, maxFrameSize);
		unpackFrame(frame, (frameAsciiRecvSize - 2)/2, &pf);

		unpackIEEE32(pf.data, pf.dataSize, &value, &time);
	}

	return 0;
}
