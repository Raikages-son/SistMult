#ifndef BMP24BPP_H
#define BMP24BPP_H

#include "bmpimage.h"

class Bmp24bpp : public BmpImage{
private:
    unsigned char*** PixelMap;
public:
    Bmp24bpp(const char *Path);

    void save(const char *Path);

    unsigned char *** getMap(){return PixelMap;}

};

#endif // BMP24BPP_H
