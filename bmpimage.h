#ifndef BMPIMAGE_H
#define BMPIMAGE_H

#include <iostream>

using namespace::std;

class BmpImage{
protected:
    const int headerSize=54;

    // DATI DEL FILE HEADER
    unsigned short type;
    unsigned int fileSize;
    unsigned int reserved;
    unsigned int offBytes;


    // DATI DEL INFO HEADER
    unsigned int infoSize;
    unsigned int width;
    unsigned int height;
    unsigned short planes;
    unsigned short bpp;
    unsigned int compression;
    unsigned int imageSize;
    unsigned int xResolution;
    unsigned int yResolution;
    unsigned int usedColors;
    unsigned int importantColors;

    // PALETTE
    unsigned char* PALETTE;


public:
    BmpImage(const char* Path);

    void save(const char* Path);

    unsigned int getWidth(){return width;}
    unsigned int getHeight(){return height;}
    unsigned int getOffset(){return offBytes;}
    unsigned short getBPP(){return bpp;}

    int getPadding();

    void resize(unsigned int newWidth, unsigned int newHeight);

};

#endif // BMPIMAGE_H
