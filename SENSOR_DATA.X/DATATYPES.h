#ifndef DATATYPES_H
#define	DATATYPES_H

//Ascii Numbers
#define CHAR_X 0x58
#define CHAR_Y 0x59
#define CHAR_Z 0x5A
#define COLON 0x3A
typedef unsigned char BYTE;

struct DATA_PACKET
{
    BYTE X0;
    BYTE X1;
    BYTE Y0;
    BYTE Y1;
    BYTE Z0;
    BYTE Z1;
};
#endif	/*DATATYPES_H*/