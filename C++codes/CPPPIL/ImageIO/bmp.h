#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define BM 19778

typedef struct BITMAPheader
{
    unsigned short bfType;//'BM'(0-1)
    unsigned int bfSize;//file bytes (2 - 5)
    unsigned int bfRsrv;//reserved word == 0, (6 - 9)
    unsigned int bfOffset;//pixel data offset(10 - 13)
    unsigned int infoSize;//(14 - 17)
    int width;//(18 -21)
    int height;//(22 -25)
    unsigned short plane;//=1
    unsigned short bitCount;//1,4,8,24
    unsigned int compress;//0:non, 1:BI_RLE8, 2:BI_RLE4
    unsigned int pixelSize;
    int xPixelPM;
    int yPixelPM;
    unsigned int usedColor;//0:all colors,(46-49)
    unsigned int importantColor;//(50-53)
}bmpHeader;

typedef struct BGRSquad
{
    unsigned char rgbBlue;
    unsigned char rgbGreen;
    unsigned char rgbRed;
    unsigned char rgbRsrv;
    /* data */
}pixelInfo;


int read(int flag, FILE *fp, int start, int offset);



