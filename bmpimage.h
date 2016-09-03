#ifndef BMPIMAGE_H
#define BMPIMAGE_H

#include <iostream>

using namespace::std;

class BmpImage{
private:
    //FILEHEADER
    unsigned char FILE_HEADER[14];
    // DATI DEL FILE HEADER
    unsigned short type = 16973;
    unsigned int fileSize;
    unsigned int reserved = 0;
    unsigned int offBytes = 1078;


    // INFOHEADER
    unsigned char INFO_HEADER[40];
    // DATI DEL INFO HEADER
    unsigned int infoSize = 40;
    unsigned int width;
    unsigned int height;
    unsigned short planes = 1;
    unsigned short bit_X_pixel;
    unsigned int compression = 0;
    unsigned int imageSize;
    unsigned int xResolution = 0;
    unsigned int yResolution = 0;
    unsigned int usedColor = 0;
    unsigned int importantColor = 0;

    // PALETTE
    unsigned char PALETTE[1024];

    // MAPPA DEI PIXEL
    unsigned char *bitmap;

public:
    BmpImage();

    BmpImage(const char* Path);

    void save(const char* Path);
};

#endif // BMPIMAGE_H
