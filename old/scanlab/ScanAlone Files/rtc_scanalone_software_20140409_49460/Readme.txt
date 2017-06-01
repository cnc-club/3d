SCANLAB RTC SCANalone Software Readme

***************************************************************************

The RTC SCANalone standalone board in combination with the software driver
is designed to provide real-time control of scan systems and lasers
without requiring a PC.

The software drivers are designed for the Microsoft operating systems
WINDOWS 8 / 7 / Vista / XP / 2000 / ME or WINDOWS 98.

Files of the RTC SCANalone software package are listed below.
Additionally the procedure for installing the drivers and the correspondent
DLL files is described in detail in this Readme file. Further instructions
for a successful operation of the RTC SCANalone board are given in the
RTC SCANalone manual.

***************************************************************************

Manufacturer
        SCANLAB AG
        Siemensstr. 2a 
        82178 Puchheim
        Germany

        Tel.    + 49 (89) 800 746-0
        Fax:    + 49 (89) 800 746-199

        info@scanlab.de
        www.scanlab.de

***************************************************************************

Package Description

The RTC SCANalone software contains the following files:

1. Package and Installation Description Files
   Readme.txt           this file
   Liesmich.txt         Description in German language 

2. Correction Files
   cor_1to1.ctb         1:1 correction file (no field correction)
   D2_n.ctb             (optional) 2D correction file
                        n:      number of the correction file
                        -----------------------------------------------
                        Earlier 2D correction files were called
                                XXYYYZZZ.ctb with
                        XX:     aperture in [mm]
                        YYY:    focal length of the objective in [mm]
                        ZZZ:    calibration factor K in [Bits per mm]
                                (in the image field)
                        -----------------------------------------------
   D2_n_ReadMe.txt      (otional) ReadMe file as description of the
                        corresponding correction file including the
                        calibration factor K in [Bits per mm]
   D3_n.ctb             (optional) 3D correction file
                        n:      number of the correction file
   D3_n_ReadMe.txt      (otional) ReadMe file as description of the
                        corresponding correction file including the
                        calibration factor K in [Bits per mm]

3. Demo Files
   Demo.cpp             RTC SCANalone demo program for Visual C++

4. WINDOWS Drivers for WINDOWS 2000 / ME and WINDOWS 98 and for
                        32-bit WINDOWS 8 / 7 / Vista / XP
   SCANalone4.inf       driver installation file
   SLusb98.SYS          driver file for WINDOWS 98
   SLusbWDM.SYS         32-bit driver file for WINDOWS 8 / 7 / Vista /
                        XP / 2000 / ME

5. WINDOWS Drivers for 64-bit WINDOWS 8 / 7 / Vista / XP
   slusbdrvx64.cat      signed catalog file
   SLUSBDRVx64.inf      driver installation file
   SLUSBDRVx64.sys      signed 64-bit driver file

   Notice that the name of the signer of the signed files is:
   "SCANLAB AG".

6. HPGL Converter Program
   HPGL demo application (needs the DLL in the same directory!)

7. SCANalone Files
   SCANalone4.DLL       RTC SCANalone dynamic link library

8. Utility Files 

 - for C:  
   SCANalone4.lib       Visual C++ import library for implicit linking
                        of the DLL
   SCANalone4expl.cpp   C functions of the DLL handling for explicit
                        linking
   SCANalone4expl.h     C function prototypes of the RTC SCANalone for
                        explicit linking of the DLL
   SCANalone4impl.h     C function prototypes of the RTC SCANalone for 
                        implicit linking of the DLL

 - for Basic:
   SCANalone4Import.bas import declarations for Visual Basic

 - for Visual Basic .NET:
   SCANalone4Import.vb import declarations for Visual Basic .NET

 - for Delphi:
   SCANalone4Import.pas import declarations for Delphi

***************************************************************************

Installation Description


WINDOWS 8 Installation

For Microsoft's WINDOWS 8 operating system you need to perform the
following to get the RTC SCANalone installed.

1. Connect the RTC SCANalone to the PC's USB port.
2. Start the computer.
3. Explicitly call WINDOWS' Device Manager. Find entry 'SCANalone RTC'
   in the device tree the Device Manager displays and update its driver
   by specifying the directory which includes the RTC SCANalone driver
   for the corresponding 32-bit or 64-bit WINDOWS version.
4. Copy the DLL file SCANalone4.DLL to the directory in which the
   application software will be started, or to the WINDOWS directory.
5. Copy the correction file(s) (*.CTB) to the harddsik of your PC
   (existing correction files can still be used; do not overwrite
   customized correction files!). SCANLAB recommends storing these files
   in the directory in which the application software will be started.


WINDOWS 7 / Vista / XP / 2000 / ME and WINDOWS 98 Installation

Microsoft's WINDOWS 7 / Vista / XP / 2000 / ME and WINDOWS 98 operating
systems recognize the RTC SCANalone as a new device. First-time connection
of the RTC SCANalone to the PC's USB port automatically causes the WINDOWS
installation program to start.
 
1. Connect the RTC SCANalone to the PC's USB port.
2. Start the computer.
3. Follow the instructions given by the WINDOWS installation program.
   Thereby specify the directory which includes the RTC SCANalone drivers
   for the particular 32-bit or 64-bit WINDOWS version.
4. Copy the DLL file SCANalone4.DLL to the directory in which the
   application software will be started, or to the WINDOWS directory.
5. Copy the correction file(s) (*.CTB) to the harddsik of your PC
   (existing correction files can still be used; do not overwrite
   customized correction files!). SCANLAB recommends storing these files
   in the directory in which the application software will be started.

***************************************************************************

Further instructions for a successful operation of the RTC SCANalone board
are given in the RTC SCANalone manual.

***************************************************************************