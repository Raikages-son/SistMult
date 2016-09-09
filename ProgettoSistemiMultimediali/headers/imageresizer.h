#ifndef IMAGERESIZER_H
#define IMAGERESIZER_H

#include "bmp24bpp.h"
#include "bmp8bpp.h"

class ImageResizer
{
public:
    ImageResizer();

    static void resize(BmpImage* image,const int& newWidth,const int& newHeight);

    static void resize(Bmp24bpp* image,const int& newWidth,const int& newHeight);

    static void resize(Bmp8bpp* image, const int& newWidth, const int& newHeight);
};

#endif // IMAGERESIZER_H
