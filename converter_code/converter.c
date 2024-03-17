#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "converter.h"

// Takes in decimal (base 10) number, 
// returns number translated to oct 
int dec_to_oct(int decimal);

// Does bit shift operations to change decimal to oct
// Only works on unsigned to avoid weird errors
unsigned uns_dec_to_oct(unsigned decimal);

// Rases unsigned integer to power. Only works for positive exponents.
unsigned upow(unsigned base, unsigned exp);

int main(int argc, char *argv[]) {

    int number = 0;
    int oct_number = 0;

    for (int i = 1; i < argc; i++) {
        number = atoi(argv[i]);
        oct_number = dec_to_oct(number);
        printf("=========================\n");
        printf("Decimal Number: %d\n", number);
        printf("Octal Number: %d\n", oct_number);
        printf("=========================\n");
    }

    printf("Conversion Complete.\n");
    return 0;
}

int dec_to_oct(int decimal) {
    int oct_num = 0;
    
    if (decimal < 0) {
        decimal *= -1;
        unsigned positive_oct = uns_dec_to_oct((unsigned)decimal);
        oct_num = ((int)positive_oct) * -1;      
    } else {
        oct_num = (int)uns_dec_to_oct((unsigned)decimal);
    }

    return oct_num;
}

unsigned uns_dec_to_oct(unsigned decimal) {
    unsigned oct_num = 0;

    for (int i = 0; i < sizeof(unsigned int) * 8 / 4; i++){
        
        unsigned remainder = decimal & 0b111;
        //printf("Remainder: %d\n", remainder);

        remainder *= upow(10, i);
        
        
        oct_num += remainder;

        decimal = decimal >> 3;
        if ( decimal == 0) {
            break;
        }
    }

    return oct_num;
}

unsigned upow(unsigned base, unsigned exp) {
    unsigned res = 1;
    for (;;) {
        if (exp & 1)
            res *= base;
        
        exp>>= 1;
        
        if (!exp)
            break;

        base *= base;
    }

    return res;
}