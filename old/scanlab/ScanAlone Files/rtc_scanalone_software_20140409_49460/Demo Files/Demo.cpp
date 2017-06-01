//  Abstract
//
//      This file demonstrates how the SCANalone could be used for text
//      printing. For that purpose, the SCANalone is loaded with the
//      complete set of printable ASCII characters.


#include <stdio.h>
#include "SCANalone4impl.h" // Required for SCANalone's function prototyping.


static long Ch[128];        // Array of the ASCII character's start positions
                            // in the SCANalone list.

void SetCharFont(short k)
//  Writes ASCII characters 32..127 to the SCANalone list and loads array Ch
//  with the corresponding start positions.
//  Notice that the first character is stored at the current list position.
//
//  By means of parameter k you specify the font size and width of the space
//  and the number characters
//  where
//                      (font size) = k * 21
//  and
//                      (space and number character's width) = k * 12
//
//  in bits of SCANalone's 16-bit scale.
{
    // Space Character
    Ch[32] = get_input_pointer(); // ' '
    jump_rel(12*k,0);
    list_return();

    // Replace the non-printable characters with the Space Character.
    for(int i = 0; i < 32; i++) Ch[i] = Ch[32];

    Ch[33] = get_input_pointer();  // !
    jump_rel(k,21*k);
    mark_rel(0,-14*k);
    jump_rel(0,-5*k);
    mark_rel(-k,-k);
    mark_rel(k,-k);
    mark_rel(k,k);
    mark_rel(-k,k);
    jump_rel(5*k,-2*k);
    list_return();

    Ch[34] = get_input_pointer();  // "
    jump_rel(k,21*k);
    mark_rel(-k,-k);
    mark_rel(0,-6*k);
    jump_rel(k,6*k);
    mark_rel(-k,-6*k);
    jump_rel(k,7*k);
    mark_rel(k,-k);
    mark_rel(-2*k,-6*k);
    jump_rel(10*k,7*k);
    mark_rel(-k,-k);
    mark_rel(0,-6*k);
    jump_rel(k,6*k);
    mark_rel(-k,-6*k);
    jump_rel(k,7*k);
    mark_rel(k,-k);
    mark_rel(-2*k,-6*k);
    jump_rel(5*k,-14*k);
    list_return();

    Ch[35] = get_input_pointer();  // #
    jump_rel(8*k,21*k);
    mark_rel(-7*k,-28*k);
    jump_rel(13*k,28*k);
    mark_rel(-7*k,-28*k);
    jump_rel(-6*k,17*k);
    mark_rel(14*k,0);
    jump_rel(-15*k,-6*k);
    mark_rel(14*k,0);
    jump_rel(4*k,-4*k);
    list_return();

    Ch[36] = get_input_pointer();  // $
    jump_rel(5*k,25*k);
    mark_rel(0,-29*k);
    jump_rel(4*k,29*k);
    mark_rel(0,-29*k);
    jump_rel(4*k,22*k);
    mark_rel(-k,-k);
    mark_rel(k,-k);
    mark_rel(k,k);
    mark_rel(0,k);
    mark_rel(-2*k,2*k);
    mark_rel(-3*k,k);
    mark_rel(-4*k,0);
    mark_rel(-3*k,-k);
    mark_rel(-2*k,-2*k);
    mark_rel(0,-2*k);
    mark_rel(k,-2*k);
    mark_rel(k,-k);
    mark_rel(2*k,-k);
    mark_rel(6*k,-2*k);
    mark_rel(2*k,-k);
    mark_rel(2*k,-2*k);
    jump_rel(-14*k,9*k);
    mark_rel(2*k,-2*k);
    mark_rel(2*k,-k);
    mark_rel(6*k,-2*k);
    mark_rel(2*k,-k);
    mark_rel(k,-k);
    mark_rel(k,-2*k);
    mark_rel(0,-4*k);
    mark_rel(-2*k,-2*k);
    mark_rel(-3*k,-k);
    mark_rel(-4*k,0);
    mark_rel(-3*k,k);
    mark_rel(-2*k,2*k);
    mark_rel(0,k);
    mark_rel(k,k);
    mark_rel(k,-k);
    mark_rel(-k,-k);
    jump_rel(16*k,-3*k);
    list_return();

    Ch[37] = get_input_pointer();  // %
    jump_rel(18*k,21*k);
    mark_rel(-18*k,-21*k);
    jump_rel(5*k,21*k);
    mark_rel(2*k,-2*k);
    mark_rel(0,-2*k);
    mark_rel(-k,-2*k);
    mark_rel(-2*k,-k);
    mark_rel(-2*k,0);
    mark_rel(-2*k,2*k);
    mark_rel(0,2*k);
    mark_rel(k,2*k);
    mark_rel(2*k,k);
    mark_rel(2*k,0);
    mark_rel(2*k,-k);
    mark_rel(3*k,-k);
    mark_rel(3*k,0);
    mark_rel(3*k,k);
    mark_rel(2*k,k);
    jump_rel(-4*k,-14*k);
    mark_rel(-2*k,-k);
    mark_rel(-k,-2*k);
    mark_rel(0,-2*k);
    mark_rel(2*k,-2*k);
    mark_rel(2*k,0);
    mark_rel(2*k,k);
    mark_rel(k,2*k);
    mark_rel(0,2*k);
    mark_rel(-2*k,2*k);
    mark_rel(-2*k,0);
    jump_rel(7*k,-7*k);
    list_return();

    Ch[38] = get_input_pointer();  // &
    jump_rel(18*k,13*k);
    mark_rel(-k,-k);
    mark_rel(k,-k);
    mark_rel(k,k);
    mark_rel(0,k);
    mark_rel(-k,k);
    mark_rel(-k,0);
    mark_rel(-k,-k);
    mark_rel(-k,-2*k);
    mark_rel(-2*k,-5*k);
    mark_rel(-2*k,-3*k);
    mark_rel(-2*k,-2*k);
    mark_rel(-2*k,-k);
    mark_rel(-3*k,0);
    mark_rel(-3*k,k);
    mark_rel(-k,2*k);
    mark_rel(0,3*k);
    mark_rel(k,2*k);
    mark_rel(6*k,4*k);
    mark_rel(2*k,2*k);
    mark_rel(k,2*k);
    mark_rel(0,2*k);
    mark_rel(-k,2*k);
    mark_rel(-2*k,k);
    mark_rel(-2*k,-k);
    mark_rel(-k,-2*k);
    mark_rel(0,-2*k);
    mark_rel(k,-3*k);
    mark_rel(2*k,-3*k);
    mark_rel(5*k,-7*k);
    mark_rel(2*k,-2*k);
    mark_rel(3*k,-k);
    mark_rel(k,0);
    mark_rel(k,k);
    mark_rel(0,k);
    jump_rel(-15*k,-2*k);
    mark_rel(-2*k,k);
    mark_rel(-k,2*k);
    mark_rel(0,3*k);
    mark_rel(k,2*k);
    mark_rel(2*k,2*k);
    jump_rel(0,6*k);
    mark_rel(k,-2*k);
    mark_rel(8*k,-11*k);
    mark_rel(2*k,-2*k);
    mark_rel(2*k,-k);
    jump_rel(5*k,0);
    list_return();

    Ch[39] = get_input_pointer();  // '
    jump_rel(k,19*k);
    mark_rel(-k,k);
    mark_rel(k,k);
    mark_rel(k,-k);
    mark_rel(0,-2*k);
    mark_rel(-k,-2*k);
    mark_rel(-k,-k);
    jump_rel(6*k,-15*k);
    list_return();

    Ch[40] = get_input_pointer();  // (
    jump_rel(7*k,25*k);
    mark_rel(-2*k,-2*k);
    mark_rel(-2*k,-3*k);
    mark_rel(-2*k,-4*k);
    mark_rel(-k,-5*k);
    mark_rel(0,-4*k);
    mark_rel(k,-5*k);
    mark_rel(2*k,-4*k);
    mark_rel(2*k,-3*k);
    mark_rel(2*k,-2*k);
    jump_rel(-2*k,30*k);
    mark_rel(-2*k,-4*k);
    mark_rel(-k,-3*k);
    mark_rel(-k,-5*k);
    mark_rel(0,-4*k);
    mark_rel(k,-5*k);
    mark_rel(k,-3*k);
    mark_rel(2*k,-4*k);
    jump_rel(5*k,5*k);
    list_return();

    Ch[41] = get_input_pointer();  // )
    jump_rel(0,25*k);
    mark_rel(2*k,-2*k);
    mark_rel(2*k,-3*k);
    mark_rel(2*k,-4*k);
    mark_rel(k,-5*k);
    mark_rel(0,-4*k);
    mark_rel(-k,-5*k);
    mark_rel(-2*k,-4*k);
    mark_rel(-2*k,-3*k);
    mark_rel(-2*k,-2*k);
    jump_rel(2*k,30*k);
    mark_rel(2*k,-4*k);
    mark_rel(k,-3*k);
    mark_rel(k,-5*k);
    mark_rel(0,-4*k);
    mark_rel(-k,-5*k);
    mark_rel(-k,-3*k);
    mark_rel(-2*k,-4*k);
    jump_rel(9*k,5*k);
    list_return();

    Ch[42] = get_input_pointer();  // *
    jump_rel(5*k,21*k);
    mark_rel(0,-12*k);
    jump_rel(-5*k,9*k);
    mark_rel(10*k,-6*k);
    jump_rel(0,6*k);
    mark_rel(-10*k,-6*k);
    jump_rel(13*k,-12*k);
    list_return();

    Ch[43] = get_input_pointer();  // +
    jump_rel(9*k,18*k);
    mark_rel(0,-18*k);
    jump_rel(-9*k,9*k);
    mark_rel(18*k,0);
    jump_rel(4*k,-9*k);
    list_return();

    Ch[44] = get_input_pointer();  // ,
    jump_rel(2*k,k);
    mark_rel(-k,-k);
    mark_rel(-k,k);
    mark_rel(k,k);
    mark_rel(k,-k);
    mark_rel(0,-2*k);
    mark_rel(-k,-2*k);
    mark_rel(-k,-k);
    jump_rel(22*k,4*k);
    list_return();

    Ch[45] = get_input_pointer();  // -
    jump_rel(0,9*k);
    mark_rel(18*k,0);
    jump_rel(4*k,-9*k);
    list_return();

    Ch[46] = get_input_pointer();  // .
    jump_rel(k,2*k);
    mark_rel(-k,-k);
    mark_rel(k,-k);
    mark_rel(k,k);
    mark_rel(-k,k);
    jump_rel(8*k,-2*k);
    list_return();

    Ch[47] = get_input_pointer();  // /
    jump_rel(0,-3*k);
    mark_rel(14*k,24*k);
    jump_rel(0,-21*k);
    list_return();

    Ch[48] = get_input_pointer();  // 0
    jump_rel(6*k,21*k);
    mark_rel(-3*k,-k);
    mark_rel(-2*k,-3*k);
    mark_rel(-k,-5*k);
    mark_rel(0,-3*k);
    mark_rel(k,-5*k);
    mark_rel(2*k,-3*k);
    mark_rel(3*k,-k);
    mark_rel(2*k,0);
    mark_rel(3*k,k);
    mark_rel(2*k,3*k);
    mark_rel(k,5*k);
    mark_rel(0,3*k);
    mark_rel(-k,5*k);
    mark_rel(-2*k,3*k);
    mark_rel(-3*k,k);
    mark_rel(-2*k,0);
    jump_rel(16*k,-21*k);
    list_return();

    Ch[49] = get_input_pointer();  // 1
    jump_rel(4*k,17*k);
    mark_rel(2*k,k);
    mark_rel(3*k,3*k);
    mark_rel(0,-21*k);
    jump_rel(11*k,0);
    jump_rel(2*k,0);
    list_return();

    Ch[50] = get_input_pointer();  // 2
    jump_rel(k,16*k);
    mark_rel(0,k);
    mark_rel(k,2*k);
    mark_rel(k,k);
    mark_rel(2*k,k);
    mark_rel(4*k,0);
    mark_rel(2*k,-k);
    mark_rel(k,-k);
    mark_rel(k,-2*k);
    mark_rel(0,-2*k);
    mark_rel(-k,-2*k);
    mark_rel(-2*k,-3*k);
    mark_rel(-10*k,-10*k);
    mark_rel(14*k,0);
    jump_rel(8*k,0);
    list_return();

    Ch[51] = get_input_pointer();  // 3
    jump_rel(2*k,21*k);
    mark_rel(11*k,0);
    mark_rel(-6*k,-8*k);
    mark_rel(3*k,0);
    mark_rel(2*k,-k);
    mark_rel(k,-k);
    mark_rel(k,-3*k);
    mark_rel(0,-2*k);
    mark_rel(-k,-3*k);
    mark_rel(-2*k,-2*k);
    mark_rel(-3*k,-k);
    mark_rel(-3*k,0);
    mark_rel(-3*k,k);
    mark_rel(-k,k);
    mark_rel(-k,2*k);
    jump_rel(22*k,-4*k);
    list_return();

    Ch[52] = get_input_pointer();  // 4
    jump_rel(10*k,0);
    mark_rel(0,21*k);
    mark_rel(-10*k,-14*k);
    mark_rel(15*k,0);
    jump_rel(7*k,-7*k);
    list_return();

    Ch[53] = get_input_pointer();  // 5
    jump_rel(12*k,21*k);
    mark_rel(-10*k,0);
    mark_rel(-k,-9*k);
    mark_rel(k,k);
    mark_rel(3*k,k);
    mark_rel(3*k,0);
    mark_rel(3*k,-k);
    mark_rel(2*k,-2*k);
    mark_rel(k,-3*k);
    mark_rel(0,-2*k);
    mark_rel(-k,-3*k);
    mark_rel(-2*k,-2*k);
    mark_rel(-3*k,-k);
    mark_rel(-3*k,0);
    mark_rel(-3*k,k);
    mark_rel(-k,k);
    mark_rel(-k,2*k);
    jump_rel(22*k,-4*k);
    list_return();

    Ch[54] = get_input_pointer();  // 6
    jump_rel(12*k,18*k);
    mark_rel(-k,2*k);
    mark_rel(-3*k,k);
    mark_rel(-2*k,0);
    mark_rel(-3*k,-k);
    mark_rel(-2*k,-3*k);
    mark_rel(-k,-5*k);
    mark_rel(0,-5*k);
    mark_rel(k,-4*k);
    mark_rel(2*k,-2*k);
    mark_rel(3*k,-k);
    mark_rel(k,0);
    mark_rel(3*k,k);
    mark_rel(2*k,2*k);
    mark_rel(k,3*k);
    mark_rel(0,k);
    mark_rel(-k,3*k);
    mark_rel(-2*k,2*k);
    mark_rel(-3*k,k);
    mark_rel(-k,0);
    mark_rel(-3*k,-k);
    mark_rel(-2*k,-2*k);
    mark_rel(-k,-3*k);
    jump_rel(22*k,-7*k);
    list_return();

    Ch[55] = get_input_pointer();  // 7
    jump_rel(0,21*k);
    mark_rel(14*k,0);
    mark_rel(-10*k,-21*k);
    jump_rel(18*k,0);
    list_return();

    Ch[56] = get_input_pointer();  // 8
    jump_rel(5*k,21*k);
    mark_rel(-3*k,-k);
    mark_rel(-k,-2*k);
    mark_rel(0,-2*k);
    mark_rel(k,-2*k);
    mark_rel(2*k,-k);
    mark_rel(4*k,-k);
    mark_rel(3*k,-k);
    mark_rel(2*k,-2*k);
    mark_rel(k,-2*k);
    mark_rel(0,-3*k);
    mark_rel(-k,-2*k);
    mark_rel(-k,-k);
    mark_rel(-3*k,-k);
    mark_rel(-4*k,0);
    mark_rel(-3*k,k);
    mark_rel(-k,k);
    mark_rel(-k,2*k);
    mark_rel(0,3*k);
    mark_rel(k,2*k);
    mark_rel(2*k,2*k);
    mark_rel(3*k,k);
    mark_rel(4*k,k);
    mark_rel(2*k,k);
    mark_rel(k,2*k);
    mark_rel(0,2*k);
    mark_rel(-k,2*k);
    mark_rel(-3*k,k);
    mark_rel(-4*k,0);
    jump_rel(17*k,-21*k);
    list_return();

    Ch[57] = get_input_pointer();  // 9
    jump_rel(13*k,14*k);
    mark_rel(-k,-3*k);
    mark_rel(-2*k,-2*k);
    mark_rel(-3*k,-k);
    mark_rel(-k,0);
    mark_rel(-3*k,k);
    mark_rel(-2*k,2*k);
    mark_rel(-k,3*k);
    mark_rel(0,k);
    mark_rel(k,3*k);
    mark_rel(2*k,2*k);
    mark_rel(3*k,k);
    mark_rel(k,0);
    mark_rel(3*k,-k);
    mark_rel(2*k,-2*k);
    mark_rel(k,-4*k);
    mark_rel(0,-5*k);
    mark_rel(-k,-5*k);
    mark_rel(-2*k,-3*k);
    mark_rel(-3*k,-k);
    mark_rel(-2*k,0);
    mark_rel(-3*k,k);
    mark_rel(-k,2*k);
    jump_rel(21*k,-3*k);
    list_return();

    Ch[58] = get_input_pointer();  // :
    jump_rel(k,14*k);
    mark_rel(-k,-k);
    mark_rel(k,-k);
    mark_rel(k,k);
    mark_rel(-k,k);
    jump_rel(0,-12*k);
    mark_rel(-k,-k);
    mark_rel(k,-k);
    mark_rel(k,k);
    mark_rel(-k,k);
    jump_rel(5*k,-2*k);
    list_return();

    Ch[59] = get_input_pointer();  // ;
    jump_rel(k,14*k);
    mark_rel(-k,-k);
    mark_rel(k,-k);
    mark_rel(k,k);
    mark_rel(-k,k);
    jump_rel(k,-13*k);
    mark_rel(-k,-k);
    mark_rel(-k,k);
    mark_rel(k,k);
    mark_rel(k,-k);
    mark_rel(0,-2*k);
    mark_rel(-k,-2*k);
    mark_rel(-k,-k);
    jump_rel(6*k,4*k);
    list_return();

    Ch[60] = get_input_pointer();  // <
    jump_rel(16*k,18*k);
    mark_rel(-16*k,-9*k);
    mark_rel(16*k,-9*k);
    jump_rel(4*k,0);
    list_return();

    Ch[61] = get_input_pointer();  // =
    jump_rel(0,12*k);
    mark_rel(18*k,0);
    jump_rel(-18*k,-6*k);
    mark_rel(18*k,0);
    jump_rel(4*k,-6*k);
    list_return();

    Ch[62] = get_input_pointer();  // >
    jump_rel(0,18*k);
    mark_rel(16*k,-9*k);
    mark_rel(-16*k,-9*k);
    jump_rel(20*k,0);
    list_return();

    Ch[63] = get_input_pointer();  // ?
    jump_rel(0,16*k);
    mark_rel(0,k);
    mark_rel(k,2*k);
    mark_rel(k,k);
    mark_rel(2*k,k);
    mark_rel(4*k,0);
    mark_rel(2*k,-k);
    mark_rel(k,-k);
    mark_rel(k,-2*k);
    mark_rel(0,-2*k);
    mark_rel(-k,-2*k);
    mark_rel(-k,-k);
    mark_rel(-4*k,-2*k);
    mark_rel(0,-3*k);
    jump_rel(0,-5*k);
    mark_rel(-k,-k);
    mark_rel(k,-k);
    mark_rel(k,k);
    mark_rel(-k,k);
    jump_rel(9*k,-2*k);
    list_return();

    Ch[64] = get_input_pointer();  // @
    jump_rel(15*k,13*k);
    mark_rel(-k,2*k);
    mark_rel(-2*k,k);
    mark_rel(-3*k,0);
    mark_rel(-2*k,-k);
    mark_rel(-k,-k);
    mark_rel(-k,-3*k);
    mark_rel(0,-3*k);
    mark_rel(k,-2*k);
    mark_rel(2*k,-k);
    mark_rel(3*k,0);
    mark_rel(2*k,k);
    mark_rel(k,2*k);
    jump_rel(-5*k,8*k);
    mark_rel(-2*k,-2*k);
    mark_rel(-k,-3*k);
    mark_rel(0,-3*k);
    mark_rel(k,-2*k);
    mark_rel(k,-k);
    jump_rel(7*k,11*k);
    mark_rel(-k,-8*k);
    mark_rel(0,-2*k);
    mark_rel(2*k,-k);
    mark_rel(2*k,0);
    mark_rel(2*k,2*k);
    mark_rel(k,3*k);
    mark_rel(0,2*k);
    mark_rel(-k,3*k);
    mark_rel(-k,2*k);
    mark_rel(-2*k,2*k);
    mark_rel(-2*k,k);
    mark_rel(-3*k,k);
    mark_rel(-3*k,0);
    mark_rel(-3*k,-k);
    mark_rel(-2*k,-k);
    mark_rel(-2*k,-2*k);
    mark_rel(-k,-2*k);
    mark_rel(-k,-3*k);
    mark_rel(0,-3*k);
    mark_rel(k,-3*k);
    mark_rel(k,-2*k);
    mark_rel(2*k,-2*k);
    mark_rel(2*k,-k);
    mark_rel(3*k,-k);
    mark_rel(3*k,0);
    mark_rel(3*k,k);
    mark_rel(2*k,k);
    mark_rel(k,k);
    jump_rel(-2*k,13*k);
    mark_rel(-k,-8*k);
    mark_rel(0,-2*k);
    mark_rel(k,-k);
    jump_rel(8*k,-5*k);
    list_return();

    Ch[65] = get_input_pointer();  // A
    jump_rel(16*k,0);
    mark_rel(-8*k,21*k);
    mark_rel(-8*k,-21*k);
    jump_rel(3*k,7*k);
    mark_rel(10*k,0);
    jump_rel(6*k,-7*k);
    list_return();

    Ch[66] = get_input_pointer();  // B
    jump_rel(0,21*k);
    mark_rel(0,-21*k);
    jump_rel(0,21*k);
    mark_rel(9*k,0);
    mark_rel(3*k,-k);
    mark_rel(k,-k);
    mark_rel(k,-2*k);
    mark_rel(0,-2*k);
    mark_rel(-k,-2*k);
    mark_rel(-k,-k);
    mark_rel(-3*k,-k);
    jump_rel(-9*k,0);
    mark_rel(9*k,0);
    mark_rel(3*k,-k);
    mark_rel(k,-k);
    mark_rel(k,-2*k);
    mark_rel(0,-3*k);
    mark_rel(-k,-2*k);
    mark_rel(-k,-k);
    mark_rel(-3*k,-k);
    mark_rel(-9*k,0);
    jump_rel(17*k,0);
    list_return();

    Ch[67] = get_input_pointer();  // C
    jump_rel(15*k,16*k);
    mark_rel(-k,2*k);
    mark_rel(-2*k,2*k);
    mark_rel(-2*k,k);
    mark_rel(-4*k,0);
    mark_rel(-2*k,-k);
    mark_rel(-2*k,-2*k);
    mark_rel(-k,-2*k);
    mark_rel(-k,-3*k);
    mark_rel(0,-5*k);
    mark_rel(k,-3*k);
    mark_rel(k,-2*k);
    mark_rel(2*k,-2*k);
    mark_rel(2*k,-k);
    mark_rel(4*k,0);
    mark_rel(2*k,k);
    mark_rel(2*k,2*k);
    mark_rel(k,2*k);
    jump_rel(4*k,-5*k);
    list_return();

    Ch[68] = get_input_pointer();  // D
    jump_rel(0,21*k);
    mark_rel(0,-21*k);
    jump_rel(0,21*k);
    mark_rel(7*k,0);
    mark_rel(3*k,-k);
    mark_rel(2*k,-2*k);
    mark_rel(k,-2*k);
    mark_rel(k,-3*k);
    mark_rel(0,-5*k);
    mark_rel(-k,-3*k);
    mark_rel(-k,-2*k);
    mark_rel(-2*k,-2*k);
    mark_rel(-3*k,-k);
    mark_rel(-7*k,0);
    jump_rel(17*k,0);
    list_return();

    Ch[69] = get_input_pointer();  // E
    jump_rel(13*k,21*k);
    mark_rel(-13*k,0);
    mark_rel(0,-21*k);
    mark_rel(13*k,0);
    jump_rel(-13*k,11*k);
    mark_rel(8*k,0);
    jump_rel(7*k,-11*k);
    list_return();

    Ch[70] = get_input_pointer();  // F
    jump_rel(0,21*k);
    mark_rel(0,-21*k);
    jump_rel(0,21*k);
    mark_rel(13*k,0);
    jump_rel(-13*k,-10*k);
    mark_rel(8*k,0);
    jump_rel(6*k,-11*k);
    list_return();

    Ch[71] = get_input_pointer();  // G
    jump_rel(15*k,16*k);
    mark_rel(-k,2*k);
    mark_rel(-2*k,2*k);
    mark_rel(-2*k,k);
    mark_rel(-4*k,0);
    mark_rel(-2*k,-k);
    mark_rel(-2*k,-2*k);
    mark_rel(-k,-2*k);
    mark_rel(-k,-3*k);
    mark_rel(0,-5*k);
    mark_rel(k,-3*k);
    mark_rel(k,-2*k);
    mark_rel(2*k,-2*k);
    mark_rel(2*k,-k);
    mark_rel(4*k,0);
    mark_rel(2*k,k);
    mark_rel(2*k,2*k);
    mark_rel(k,2*k);
    mark_rel(0,3*k);
    jump_rel(-5*k,0);
    mark_rel(5*k,0);
    jump_rel(3*k,-8*k);
    list_return();

    Ch[72] = get_input_pointer();  // H
    jump_rel(0,21*k);
    mark_rel(0,-21*k);
    jump_rel(14*k,21*k);
    mark_rel(0,-21*k);
    jump_rel(-14*k,11*k);
    mark_rel(14*k,0);
    jump_rel(4*k,-11*k);
    list_return();

    Ch[73] = get_input_pointer();  // I
    jump_rel(0,21*k);
    mark_rel(0,-21*k);
    jump_rel(4*k,0);
    list_return();

    Ch[74] = get_input_pointer();  // J
    jump_rel(10*k,21*k);
    mark_rel(0,-16*k);
    mark_rel(-k,-3*k);
    mark_rel(-k,-k);
    mark_rel(-2*k,-k);
    mark_rel(-2*k,0);
    mark_rel(-2*k,k);
    mark_rel(-k,k);
    mark_rel(-k,3*k);
    mark_rel(0,2*k);
    jump_rel(14*k,-7*k);
    list_return();

    Ch[75] = get_input_pointer();  // K
    jump_rel(0,21*k);
    mark_rel(0,-21*k);
    jump_rel(14*k,21*k);
    mark_rel(-14*k,-14*k);
    jump_rel(5*k,5*k);
    mark_rel(9*k,-12*k);
    jump_rel(3*k,0);
    list_return();

    Ch[76] = get_input_pointer();  // L
    jump_rel(0,21*k);
    mark_rel(0,-21*k);
    jump_rel(0,0);
    mark_rel(12*k,0);
    jump_rel(k,0);
    list_return();

    Ch[77] = get_input_pointer();  // M
    jump_rel(0,21*k);
    mark_rel(0,-21*k);
    jump_rel(0,21*k);
    mark_rel(8*k,-21*k);
    jump_rel(8*k,21*k);
    mark_rel(-8*k,-21*k);
    jump_rel(8*k,21*k);
    mark_rel(0,-21*k);
    jump_rel(4*k,0);
    list_return();

    Ch[78] = get_input_pointer();  // N
    jump_rel(0,21*k);
    mark_rel(0,-21*k);
    jump_rel(0,21*k);
    mark_rel(14*k,-21*k);
    jump_rel(0,21*k);
    mark_rel(0,-21*k);
    jump_rel(4*k,0);
    list_return();

    Ch[79] = get_input_pointer();  // O
    jump_rel(6*k,21*k);
    mark_rel(-2*k,-k);
    mark_rel(-2*k,-2*k);
    mark_rel(-k,-2*k);
    mark_rel(-k,-3*k);
    mark_rel(0,-5*k);
    mark_rel(k,-3*k);
    mark_rel(k,-2*k);
    mark_rel(2*k,-2*k);
    mark_rel(2*k,-k);
    mark_rel(4*k,0);
    mark_rel(2*k,k);
    mark_rel(2*k,2*k);
    mark_rel(k,2*k);
    mark_rel(k,3*k);
    mark_rel(0,5*k);
    mark_rel(-k,3*k);
    mark_rel(-k,2*k);
    mark_rel(-2*k,2*k);
    mark_rel(-2*k,k);
    mark_rel(-4*k,0);
    jump_rel(13*k,-21*k);
    list_return();

    Ch[80] = get_input_pointer();  // P
    jump_rel(0,10*k);
    mark_rel(9*k,0);
    mark_rel(3*k,k);
    mark_rel(k,k);
    mark_rel(k,2*k);
    mark_rel(0,3*k);
    mark_rel(-k,2*k);
    mark_rel(-k,k);
    mark_rel(-3*k,k);
    mark_rel(-9*k,0);
    mark_rel(0,-21*k);
    jump_rel(17*k,0);
    list_return();

    Ch[81] = get_input_pointer();  // Q
    jump_rel(6*k,21*k);
    mark_rel(-2*k,-k);
    mark_rel(-2*k,-2*k);
    mark_rel(-k,-2*k);
    mark_rel(-k,-3*k);
    mark_rel(0,-5*k);
    mark_rel(k,-3*k);
    mark_rel(k,-2*k);
    mark_rel(2*k,-2*k);
    mark_rel(2*k,-k);
    mark_rel(4*k,0);
    mark_rel(2*k,k);
    mark_rel(2*k,2*k);
    mark_rel(k,2*k);
    mark_rel(k,3*k);
    mark_rel(0,5*k);
    mark_rel(-k,3*k);
    mark_rel(-k,2*k);
    mark_rel(-2*k,2*k);
    mark_rel(-2*k,k);
    mark_rel(-4*k,0);
    jump_rel(3*k,-17*k);
    mark_rel(6*k,-6*k);
    jump_rel(4*k,2*k);
    list_return();

    Ch[82] = get_input_pointer();  // R
    jump_rel(0,21*k);
    mark_rel(0,-21*k);
    jump_rel(0,21*k);
    mark_rel(9*k,0);
    mark_rel(3*k,-k);
    mark_rel(k,-k);
    mark_rel(k,-2*k);
    mark_rel(0,-2*k);
    mark_rel(-k,-2*k);
    mark_rel(-k,-k);
    mark_rel(-3*k,-k);
    mark_rel(-9*k,0);
    jump_rel(7*k,0);
    mark_rel(7*k,-11*k);
    jump_rel(3*k,0);
    list_return();

    Ch[83] = get_input_pointer();  // S
    jump_rel(14*k,18*k);
    mark_rel(-2*k,2*k);
    mark_rel(-3*k,k);
    mark_rel(-4*k,0);
    mark_rel(-3*k,-k);
    mark_rel(-2*k,-2*k);
    mark_rel(0,-2*k);
    mark_rel(k,-2*k);
    mark_rel(k,-k);
    mark_rel(2*k,-k);
    mark_rel(6*k,-2*k);
    mark_rel(2*k,-k);
    mark_rel(k,-k);
    mark_rel(k,-2*k);
    mark_rel(0,-3*k);
    mark_rel(-2*k,-2*k);
    mark_rel(-3*k,-k);
    mark_rel(-4*k,0);
    mark_rel(-3*k,k);
    mark_rel(-2*k,2*k);
    jump_rel(17*k,-3*k);
    list_return();

    Ch[84] = get_input_pointer();  // T
    jump_rel(7*k,21*k);
    mark_rel(0,-21*k);
    jump_rel(-7*k,21*k);
    mark_rel(14*k,0);
    jump_rel(k,-21*k);
    list_return();

    Ch[85] = get_input_pointer();  // U
    jump_rel(0,21*k);
    mark_rel(0,-15*k);
    mark_rel(k,-3*k);
    mark_rel(2*k,-2*k);
    mark_rel(3*k,-k);
    mark_rel(2*k,0);
    mark_rel(3*k,k);
    mark_rel(2*k,2*k);
    mark_rel(k,3*k);
    mark_rel(0,15*k);
    jump_rel(4*k,-21*k);
    list_return();

    Ch[86] = get_input_pointer();  // V
    jump_rel(0,21*k);
    mark_rel(8*k,-21*k);
    jump_rel(8*k,21*k);
    mark_rel(-8*k,-21*k);
    jump_rel(9*k,0);
    list_return();

    Ch[87] = get_input_pointer();  // W
    jump_rel(0,21*k);
    mark_rel(5*k,-21*k);
    jump_rel(5*k,21*k);
    mark_rel(-5*k,-21*k);
    jump_rel(5*k,21*k);
    mark_rel(5*k,-21*k);
    jump_rel(5*k,21*k);
    mark_rel(-5*k,-21*k);
    jump_rel(7*k,0);
    list_return();

    Ch[88] = get_input_pointer();  // X
    jump_rel(0,21*k);
    mark_rel(14*k,-21*k);
    jump_rel(0,21*k);
    mark_rel(-14*k,-21*k);
    jump_rel(17*k,0);
    list_return();

    Ch[89] = get_input_pointer();  // Y
    jump_rel(0,21*k);
    mark_rel(8*k,-10*k);
    mark_rel(0,-11*k);
    jump_rel(8*k,21*k);
    mark_rel(-8*k,-10*k);
    jump_rel(9*k,-11*k);
    list_return();

    Ch[90] = get_input_pointer();  // Z
    jump_rel(14*k,21*k);
    mark_rel(-14*k,-21*k);
    jump_rel(0,21*k);
    mark_rel(14*k,0);
    jump_rel(-14*k,-21*k);
    mark_rel(14*k,0);
    jump_rel(3*k,0);
    list_return();

    Ch[91] = get_input_pointer();  // [
    jump_rel(0,19*k);
    mark_rel(0,-20*k);
    jump_rel(k,20*k);
    mark_rel(0,-20*k);
    jump_rel(-k,20*k);
    mark_rel(5*k,0);
    jump_rel(-5*k,-20*k);
    mark_rel(5*k,0);
    jump_rel(2*k,k);
    list_return();

    Ch[92] = get_input_pointer();  // '\'
    jump_rel(0,21*k);
    mark_rel(14*k,-24*k);
    jump_rel(0,3*k);
    list_return();

    Ch[93] = get_input_pointer();  // ]
    jump_rel(4*k,19*k);
    mark_rel(0,-20*k);
    jump_rel(k,20*k);
    mark_rel(0,-20*k);
    jump_rel(-5*k,20*k);
    mark_rel(5*k,0);
    jump_rel(-5*k,-20*k);
    mark_rel(5*k,0);
    jump_rel(3*k,k);
    list_return();

    Ch[94] = get_input_pointer();  // ^
    jump_rel(8*k,18*k);
    mark_rel(-5*k,-4*k);
    mark_rel(5*k,5*k);
    mark_rel(5*k,-5*k);
    mark_rel(-5*k,4*k);
    mark_rel(0,0);
    jump_rel(11*k,-18*k);
    list_return();

    Ch[95] = get_input_pointer();  // _
    jump_rel(0,-7*k);
    mark_rel(16*k,0);
    jump_rel(k,7*k);
    list_return();

    Ch[96] = get_input_pointer();  // `
    jump_rel(2*k,21*k);
    mark_rel(-k,-k);
    mark_rel(-k,-2*k);
    mark_rel(0,-2*k);
    mark_rel(k,-k);
    mark_rel(k,k);
    mark_rel(-k,k);
    jump_rel(5*k,-17*k);
    list_return();

    Ch[97] = get_input_pointer();  // a
    jump_rel(12*k,14*k);
    mark_rel(0,-14*k);
    jump_rel(0,11*k);
    mark_rel(-2*k,2*k);
    mark_rel(-2*k,k);
    mark_rel(-3*k,0);
    mark_rel(-2*k,-k);
    mark_rel(-2*k,-2*k);
    mark_rel(-k,-3*k);
    mark_rel(0,-2*k);
    mark_rel(k,-3*k);
    mark_rel(2*k,-2*k);
    mark_rel(2*k,-k);
    mark_rel(3*k,0);
    mark_rel(2*k,k);
    mark_rel(2*k,2*k);
    jump_rel(4*k,-3*k);
    list_return();

    Ch[98] = get_input_pointer();  // b
    jump_rel(0,21*k);
    mark_rel(0,-21*k);
    jump_rel(0,11*k);
    mark_rel(2*k,2*k);
    mark_rel(2*k,k);
    mark_rel(3*k,0);
    mark_rel(2*k,-k);
    mark_rel(2*k,-2*k);
    mark_rel(k,-3*k);
    mark_rel(0,-2*k);
    mark_rel(-k,-3*k);
    mark_rel(-2*k,-2*k);
    mark_rel(-2*k,-k);
    mark_rel(-3*k,0);
    mark_rel(-2*k,k);
    mark_rel(-2*k,2*k);
    jump_rel(15*k,-3*k);
    list_return();

    Ch[99] = get_input_pointer();  // c
    jump_rel(12*k,11*k);
    mark_rel(-2*k,2*k);
    mark_rel(-2*k,k);
    mark_rel(-3*k,0);
    mark_rel(-2*k,-k);
    mark_rel(-2*k,-2*k);
    mark_rel(-k,-3*k);
    mark_rel(0,-2*k);
    mark_rel(k,-3*k);
    mark_rel(2*k,-2*k);
    mark_rel(2*k,-k);
    mark_rel(3*k,0);
    mark_rel(2*k,k);
    mark_rel(2*k,2*k);
    jump_rel(3*k,-3*k);
    list_return();

    Ch[100] = get_input_pointer();  // d
    jump_rel(12*k,21*k);
    mark_rel(0,-21*k);
    jump_rel(0,11*k);
    mark_rel(-2*k,2*k);
    mark_rel(-2*k,k);
    mark_rel(-3*k,0);
    mark_rel(-2*k,-k);
    mark_rel(-2*k,-2*k);
    mark_rel(-k,-3*k);
    mark_rel(0,-2*k);
    mark_rel(k,-3*k);
    mark_rel(2*k,-2*k);
    mark_rel(2*k,-k);
    mark_rel(3*k,0);
    mark_rel(2*k,k);
    mark_rel(2*k,2*k);
    jump_rel(4*k,-3*k);
    list_return();

    Ch[101] = get_input_pointer();  // e
    jump_rel(0,8*k);
    mark_rel(12*k,0);
    mark_rel(0,2*k);
    mark_rel(-k,2*k);
    mark_rel(-k,k);
    mark_rel(-2*k,k);
    mark_rel(-3*k,0);
    mark_rel(-2*k,-k);
    mark_rel(-2*k,-2*k);
    mark_rel(-k,-3*k);
    mark_rel(0,-2*k);
    mark_rel(k,-3*k);
    mark_rel(2*k,-2*k);
    mark_rel(2*k,-k);
    mark_rel(3*k,0);
    mark_rel(2*k,k);
    mark_rel(2*k,2*k);
    jump_rel(3*k,-3*k);
    list_return();

    Ch[102] = get_input_pointer();  // f
    jump_rel(8*k,21*k);
    mark_rel(-2*k,0);
    mark_rel(-2*k,-k);
    mark_rel(-k,-3*k);
    mark_rel(0,-17*k);
    jump_rel(-3*k,14*k);
    mark_rel(7*k,0);
    jump_rel(3*k,-14*k);
    list_return();

    Ch[103] = get_input_pointer();  // g
    jump_rel(12*k,14*k);
    mark_rel(0,-16*k);
    mark_rel(-k,-3*k);
    mark_rel(-k,-k);
    mark_rel(-2*k,-k);
    mark_rel(-3*k,0);
    mark_rel(-2*k,k);
    jump_rel(9*k,17*k);
    mark_rel(-2*k,2*k);
    mark_rel(-2*k,k);
    mark_rel(-3*k,0);
    mark_rel(-2*k,-k);
    mark_rel(-2*k,-2*k);
    mark_rel(-k,-3*k);
    mark_rel(0,-2*k);
    mark_rel(k,-3*k);
    mark_rel(2*k,-2*k);
    mark_rel(2*k,-k);
    mark_rel(3*k,0);
    mark_rel(2*k,k);
    mark_rel(2*k,2*k);
    jump_rel(4*k,-3*k);
    list_return();

    Ch[104] = get_input_pointer();  // h
    jump_rel(0,21*k);
    mark_rel(0,-21*k);
    jump_rel(0,10*k);
    mark_rel(3*k,3*k);
    mark_rel(2*k,k);
    mark_rel(3*k,0);
    mark_rel(2*k,-k);
    mark_rel(k,-3*k);
    mark_rel(0,-10*k);
    jump_rel(4*k,0);
    list_return();

    Ch[105] = get_input_pointer();  // i
    jump_rel(2*k,21*k);
    mark_rel(k,-k);
    mark_rel(k,k);
    mark_rel(-k,k);
    mark_rel(-k,-k);
    jump_rel(k,-7*k);
    mark_rel(0,-14*k);
    jump_rel(4*k,0);
    list_return();

    Ch[106] = get_input_pointer();  // j
    jump_rel(4*k,21*k);
    mark_rel(k,-k);
    mark_rel(k,k);
    mark_rel(-k,k);
    mark_rel(-k,-k);
    jump_rel(k,-7*k);
    mark_rel(0,-17*k);
    mark_rel(-k,-3*k);
    mark_rel(-2*k,-k);
    mark_rel(-2*k,0);
    jump_rel(9*k,7*k);
    list_return();

    Ch[107] = get_input_pointer();  // k
    jump_rel(0,21*k);
    mark_rel(0,-21*k);
    jump_rel(10*k,14*k);
    mark_rel(-10*k,-10*k);
    jump_rel(4*k,4*k);
    mark_rel(7*k,-8*k);
    jump_rel(2*k,0);
    list_return();

    Ch[108] = get_input_pointer();  // l
    jump_rel(0,21*k);
    mark_rel(0,-21*k);
    jump_rel(4*k,0);
    list_return();

    Ch[109] = get_input_pointer();  // m
    jump_rel(0,14*k);
    mark_rel(0,-14*k);
    jump_rel(0,10*k);
    mark_rel(3*k,3*k);
    mark_rel(2*k,k);
    mark_rel(3*k,0);
    mark_rel(2*k,-k);
    mark_rel(k,-3*k);
    mark_rel(0,-10*k);
    jump_rel(0,10*k);
    mark_rel(3*k,3*k);
    mark_rel(2*k,k);
    mark_rel(3*k,0);
    mark_rel(2*k,-k);
    mark_rel(k,-3*k);
    mark_rel(0,-10*k);
    jump_rel(4*k,0);
    list_return();

    Ch[110] = get_input_pointer();  // n
    jump_rel(0,14*k);
    mark_rel(0,-14*k);
    jump_rel(0,10*k);
    mark_rel(3*k,3*k);
    mark_rel(2*k,k);
    mark_rel(3*k,0);
    mark_rel(2*k,-k);
    mark_rel(k,-3*k);
    mark_rel(0,-10*k);
    jump_rel(4*k,0);
    list_return();

    Ch[111] = get_input_pointer();  // o
    jump_rel(5*k,14*k);
    mark_rel(-2*k,-k);
    mark_rel(-2*k,-2*k);
    mark_rel(-k,-3*k);
    mark_rel(0,-2*k);
    mark_rel(k,-3*k);
    mark_rel(2*k,-2*k);
    mark_rel(2*k,-k);
    mark_rel(3*k,0);
    mark_rel(2*k,k);
    mark_rel(2*k,2*k);
    mark_rel(k,3*k);
    mark_rel(0,2*k);
    mark_rel(-k,3*k);
    mark_rel(-2*k,2*k);
    mark_rel(-2*k,k);
    mark_rel(-3*k,0);
    jump_rel(11*k,-14*k);
    list_return();

    Ch[112] = get_input_pointer();  // p
    jump_rel(0,14*k);
    mark_rel(0,-21*k);
    jump_rel(0,18*k);
    mark_rel(2*k,2*k);
    mark_rel(2*k,k);
    mark_rel(3*k,0);
    mark_rel(2*k,-k);
    mark_rel(2*k,-2*k);
    mark_rel(k,-3*k);
    mark_rel(0,-2*k);
    mark_rel(-k,-3*k);
    mark_rel(-2*k,-2*k);
    mark_rel(-2*k,-k);
    mark_rel(-3*k,0);
    mark_rel(-2*k,k);
    mark_rel(-2*k,2*k);
    jump_rel(15*k,-3*k);
    list_return();

    Ch[113] = get_input_pointer();  // q
    jump_rel(12*k,14*k);
    mark_rel(0,-21*k);
    jump_rel(0,18*k);
    mark_rel(-2*k,2*k);
    mark_rel(-2*k,k);
    mark_rel(-3*k,0);
    mark_rel(-2*k,-k);
    mark_rel(-2*k,-2*k);
    mark_rel(-k,-3*k);
    mark_rel(0,-2*k);
    mark_rel(k,-3*k);
    mark_rel(2*k,-2*k);
    mark_rel(2*k,-k);
    mark_rel(3*k,0);
    mark_rel(2*k,k);
    mark_rel(2*k,2*k);
    jump_rel(4*k,-3*k);
    list_return();

    Ch[114] = get_input_pointer();  // r
    jump_rel(0,14*k);
    mark_rel(0,-14*k);
    jump_rel(0,8*k);
    mark_rel(k,3*k);
    mark_rel(2*k,2*k);
    mark_rel(2*k,k);
    mark_rel(3*k,0);
    jump_rel(k,-14*k);
    list_return();

    Ch[115] = get_input_pointer();  // s
    jump_rel(11*k,11*k);
    mark_rel(-k,2*k);
    mark_rel(-3*k,k);
    mark_rel(-3*k,0);
    mark_rel(-3*k,-k);
    mark_rel(-k,-2*k);
    mark_rel(k,-2*k);
    mark_rel(2*k,-k);
    mark_rel(5*k,-k);
    mark_rel(2*k,-k);
    mark_rel(k,-2*k);
    mark_rel(0,-k);
    mark_rel(-k,-2*k);
    mark_rel(-3*k,-k);
    mark_rel(-3*k,0);
    mark_rel(-3*k,k);
    mark_rel(-k,2*k);
    jump_rel(14*k,-3*k);
    list_return();

    Ch[116] = get_input_pointer();  // t
    jump_rel(3*k,21*k);
    mark_rel(0,-17*k);
    mark_rel(k,-3*k);
    mark_rel(2*k,-k);
    mark_rel(2*k,0);
    jump_rel(-8*k,14*k);
    mark_rel(7*k,0);
    jump_rel(3*k,-14*k);
    list_return();

    Ch[117] = get_input_pointer();  // u
    jump_rel(0,14*k);
    mark_rel(0,-10*k);
    mark_rel(k,-3*k);
    mark_rel(2*k,-k);
    mark_rel(3*k,0);
    mark_rel(2*k,k);
    mark_rel(3*k,3*k);
    jump_rel(0,10*k);
    mark_rel(0,-14*k);
    jump_rel(4*k,0);
    list_return();

    Ch[118] = get_input_pointer();  // v
    jump_rel(0,14*k);
    mark_rel(6*k,-14*k);
    jump_rel(6*k,14*k);
    mark_rel(-6*k,-14*k);
    jump_rel(8*k,0);
    list_return();

    Ch[119] = get_input_pointer();  // w
    jump_rel(0,14*k);
    mark_rel(4*k,-14*k);
    jump_rel(4*k,14*k);
    mark_rel(-4*k,-14*k);
    jump_rel(4*k,14*k);
    mark_rel(4*k,-14*k);
    jump_rel(4*k,14*k);
    mark_rel(-4*k,-14*k);
    jump_rel(7*k,0);
    list_return();

    Ch[120] = get_input_pointer();  // x
    jump_rel(0,14*k);
    mark_rel(11*k,-14*k);
    jump_rel(0,14*k);
    mark_rel(-11*k,-14*k);
    jump_rel(14*k,0);
    list_return();

    Ch[121] = get_input_pointer();  // y
    jump_rel(k,14*k);
    mark_rel(6*k,-14*k);
    jump_rel(6*k,14*k);
    mark_rel(-6*k,-14*k);
    mark_rel(-2*k,-4*k);
    mark_rel(-2*k,-2*k);
    mark_rel(-2*k,-k);
    mark_rel(-k,0);
    jump_rel(15*k,7*k);
    list_return();

    Ch[122] = get_input_pointer();  // z
    jump_rel(11*k,14*k);
    mark_rel(-11*k,-14*k);
    jump_rel(0,14*k);
    mark_rel(11*k,0);
    jump_rel(-11*k,-14*k);
    mark_rel(11*k,0);
    jump_rel(3*k,0);
    list_return();

    Ch[123] = get_input_pointer();  // {
    jump_rel(5*k,25*k);
    mark_rel(-2*k,-k);
    mark_rel(-k,-k);
    mark_rel(-k,-2*k);
    mark_rel(0,-2*k);
    mark_rel(k,-2*k);
    mark_rel(k,-k);
    mark_rel(k,-2*k);
    mark_rel(0,-2*k);
    mark_rel(-2*k,-2*k);
    jump_rel(k,14*k);
    mark_rel(-k,-2*k);
    mark_rel(0,-2*k);
    mark_rel(k,-2*k);
    mark_rel(k,-k);
    mark_rel(k,-2*k);
    mark_rel(0,-2*k);
    mark_rel(-k,-2*k);
    mark_rel(-4*k,-2*k);
    mark_rel(4*k,-2*k);
    mark_rel(k,-2*k);
    mark_rel(0,-2*k);
    mark_rel(-k,-2*k);
    mark_rel(-k,-k);
    mark_rel(-k,-2*k);
    mark_rel(0,-2*k);
    mark_rel(k,-2*k);
    jump_rel(-k,14*k);
    mark_rel(2*k,-2*k);
    mark_rel(0,-2*k);
    mark_rel(-k,-2*k);
    mark_rel(-k,-k);
    mark_rel(-k,-2*k);
    mark_rel(0,-2*k);
    mark_rel(k,-2*k);
    mark_rel(k,-k);
    mark_rel(2*k,-k);
    jump_rel(5*k,7*k);
    list_return();

    Ch[124] = get_input_pointer();  // |
    jump_rel(0,21*k);
    mark_rel(0,-21*k);
    jump_rel(4*k,0);
    list_return();

    Ch[125] = get_input_pointer();  // }
    jump_rel(0,25*k);
    mark_rel(2*k,-k);
    mark_rel(k,-k);
    mark_rel(k,-2*k);
    mark_rel(0,-2*k);
    mark_rel(-k,-2*k);
    mark_rel(-k,-k);
    mark_rel(-k,-2*k);
    mark_rel(0,-2*k);
    mark_rel(2*k,-2*k);
    jump_rel(-k,14*k);
    mark_rel(k,-2*k);
    mark_rel(0,-2*k);
    mark_rel(-k,-2*k);
    mark_rel(-k,-k);
    mark_rel(-k,-2*k);
    mark_rel(0,-2*k);
    mark_rel(k,-2*k);
    mark_rel(4*k,-2*k);
    mark_rel(-4*k,-2*k);
    mark_rel(-k,-2*k);
    mark_rel(0,-2*k);
    mark_rel(k,-2*k);
    mark_rel(k,-k);
    mark_rel(k,-2*k);
    mark_rel(0,-2*k);
    mark_rel(-k,-2*k);
    jump_rel(k,14*k);
    mark_rel(-2*k,-2*k);
    mark_rel(0,-2*k);
    mark_rel(k,-2*k);
    mark_rel(k,-k);
    mark_rel(k,-2*k);
    mark_rel(0,-2*k);
    mark_rel(-k,-2*k);
    mark_rel(-k,-k);
    mark_rel(-2*k,-k);
    jump_rel(9*k,7*k);
    list_return();

    Ch[126] = get_input_pointer();  // ~
    jump_rel(0,16*k);
    mark_rel(5*k,3*k);
    mark_rel(4*k,-3*k);
    mark_rel(4*k,2*k);
    jump_rel(k,-18*k);
    list_return();

    // Replace the DEL character with the Space Character.
    Ch[127] = Ch[32];
}


void String2List(const char* PtrStr)
//  Writes a string to the current list position
//  by using list calls of the character font that is
//  loaded with a previous call of the function SetCharFont.
{
    char Index;
    for(; *PtrStr != '\0'; PtrStr++) {
        Index = *PtrStr;
        // Print the characters in the range 33 ... 127 and
        // replace the characters in the range -128 ... 32
        // with the space character.
        if(Index > 32)
            list_call(Ch[Index]);
        else
            list_call(Ch[32]);
    }
}




//  Font Size
//
//      By means of CHAR_SIZE you specify the font size where
//
//                      (font size) = CHAR_SIZE * 21
//
//                                      in bits of SCANalone's 16-bit scale.
#define CHAR_SIZE       120


void main(void)
{
    short           ErrorCode;
    long            Position, StartPos;
    unsigned short  Busy, i;


    // Initialize
    ErrorCode = load_cor("cor_1to1.ctb");   // load a correction file
                                            // to the SCANalone
    if(ErrorCode)
    {
        printf("Correction file loading error #%d\n", ErrorCode);
        return;
    }

    set_laser_mode(0);              // select CO2 mode
    set_delay_mode(1,0,65000,0,0);  // use the variable polygon delay

    // Timing, delay and speed preset
    set_start_list(1);          // open list 1 for input  
        set_standby_list(100*8, // half of the laser standby pulse period
                                //  [1/8us]
                         1*8);  // standby pulse width [1/8us]
        set_laser_timing(50,    // half of the laser signal period
                         40,    // pulse widths of signal LASER1
                         40,    // pulse widths of signal LASER2
                         0);    // time base; 0 corresponds to 1 microsecond;
                                // otherwise the time base is 1/8 microseconds
        set_scanner_delays(50,  // jump delay [10us]
                           20,  // mark delay [10us]
                           10); // polygon delay [10us]
        set_laser_delays(100,   // laser on delay [us]
                         100);  // laser off delay [us]
        set_jump_speed(2500.0); // jump speed [bits/ms]
        set_mark_speed(250.0);  // marking speed [bits/ms]
    set_end_of_list();          // close the list
    execute_list(1);            // execute list 1

    // wait until the execution is finished
    do{
        get_status(&Busy, &Position);
    } while(Busy);



    set_serial(98);             // start marking serial numbers with 98
    set_max_counts(5);          // after 5 external starts, the external
                                // trigger is disabled

    time_update();              // synchronize the SCANalone time and date
                                // with the PC

    clear_list();               // clear the SCANalone list (useful for
                                // storing on MMC)

    set_input_pointer(1);       // set the list input pointer to one!!!
    SetCharFont(CHAR_SIZE);     // load the character font to the SCANalone


    // define numerals 0..9
    //
    for(i=0; i<10; i++)
        set_char_table(i, Ch['0'+i]);


    // define months
    //
    set_char_table(10, get_input_pointer());
    String2List("Jan.");
    list_return();

    set_char_table(11, get_input_pointer());
    String2List("Feb.");
    list_return();

    set_char_table(12, get_input_pointer());
    String2List("Mar.");
    list_return();

    set_char_table(13, get_input_pointer());
    String2List("Apr.");
    list_return();

    set_char_table(14, get_input_pointer());
    String2List("Mai.");
    list_return();

    set_char_table(15, get_input_pointer());
    String2List("Jun.");
    list_return();

    set_char_table(16, get_input_pointer());
    String2List("Jul.");
    list_return();

    set_char_table(17, get_input_pointer());
    String2List("Aug.");
    list_return();

    set_char_table(18, get_input_pointer());
    String2List("Sep.");
    list_return();

    set_char_table(19, get_input_pointer());
    String2List("Oct.");
    list_return();

    set_char_table(20, get_input_pointer());
    String2List("Nov.");
    list_return();

    set_char_table(21, get_input_pointer());
    String2List("Dec.");
    list_return();


    // define weekdays
    //
    set_char_table(22, get_input_pointer());
    String2List("Sunday");
    list_return();

    set_char_table(23, get_input_pointer());
    String2List("Monday");
    list_return();

    set_char_table(24, get_input_pointer());
    String2List("Tuesday");
    list_return();

    set_char_table(25, get_input_pointer());
    String2List("Wednesday");
    list_return();

    set_char_table(26, get_input_pointer());
    String2List("Thursday");
    list_return();

    set_char_table(27, get_input_pointer());
    String2List("Friday");
    list_return();

    set_char_table(28, get_input_pointer());
    String2List("Saturday");
    list_return();

    // define space for serial no
    //
    set_char_table(29, Ch[' ']);

    // define numerals 0..9 for serial no
    //
    for(i=0; i<10; i++)
        set_char_table(30+i, Ch['0'+i]);



    StartPos = get_input_pointer(); // now mark time, date and serial
        time_fix();             // fix actual time and date for marking

        jump_abs(-10000,+7500); // jump to start point
        mark_date(3,0);         // mark day of week

        jump_abs(-10000,+2500); // mark date
        mark_date(2,0);         // mark day of month, suppress leading zero
        list_call(Ch['.']);     // mark a point
        mark_date(1,0);         // mark month
        list_call(Ch['2']);     // mark '20'
        list_call(Ch['0']);
        mark_date(0,0);         // mark year with 2 digits

        jump_abs(-10000,-2500); // mark time
        mark_time(0,1);         // mark hour with 2 digits
        list_call(Ch[':']);     // mark ':'
        mark_time(1,1);         // mark min with 2 digits
        list_call(Ch[':']);     // mark ':'
        mark_time(2,1);         // mark sec with 2 digits


        jump_abs(-10000,-7500);
        String2List("Serial No: ");    // mark 'Serial No: XXX'
        mark_serial(2,3);              // mark serial number with 3 digits
                                // mode = 2 (replace leading zeros with space)


        set_io_cond_list(0,0, 2);   // generate a 100us pulse on bit 1 of the
                                    // 16bit output port
        long_delay(10);             // all other pins of the port are unchanged
        clear_io_cond_list(0,0, 2); // this may be useful for a handling system

    set_end_of_list();              // stop list execution at this point


    set_extstartpos(StartPos);      // set the start position in the list for
                                    // an external trigger

    set_control_mode(9);            // enable the external trigger and set the
                                    // external start counter to zero

    write_io_port(1);               // set bit 0 to 1 and clear all other bits
                                    // of the 16bit output port
                                    // the digital output ports are in tri-
                                    // state mode until the first write command


    
    ErrorCode = store_on_mmc();     // store the current state on the multi-
                                    // media card
    if(ErrorCode)
    {
        printf("Unable writing on MMC!");
        return;
    }

    // Uncomment the following, if you want to start by software.
//    execute_at_pointer(StartPos);    // start execution by software

    printf("SCANalone is ready!\n");
}
