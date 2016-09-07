#ifndef IMAGERESIZER_H
#define IMAGERESIZER_H

#include "bmp24bpp.h"

class ImageResizer
{
public:
    ImageResizer();

    static void resize(Bmp24bpp* image,const int& newWidth,const int& newHeight);
};

#endif // IMAGERESIZER_H
