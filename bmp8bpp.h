#ifndef BMP8BPP_H
#define BMP8BPP_H

#include "bmpimage.h"

class Bmp8bpp : public BmpImage{   
private:
    unsigned char** PixelMap;
public:
    Bmp8bpp(const char *Path);

    void save(const char *Path);

    unsigned char ** getMap(){return PixelMap;}

    void editPMap(unsigned char** map){PixelMap=map;}
};

#endif // BMP8BPP_H
