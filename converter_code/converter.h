#ifndef CONVERTER
#define CONVERTER
// Takes in decimal (base 10) number, 
// returns number translated to oct 
int dec_to_oct(int decimal);

// Does bit shift operations to change decimal to oct
// Only works on unsigned to avoid weird errors
unsigned uns_dec_to_oct(unsigned decimal);

#endif