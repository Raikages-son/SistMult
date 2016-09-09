#ifndef MIRROR_H
#define MIRROR_H

#include "bmpimage.h"
#include "bmp24bpp.h"
#include "bmp8bpp.h"

class Mirror
{
public:
    Mirror();
    static void horizontalMirroring(BmpImage* image);
    static void verticalMirroring(BmpImage* image);
    static void diagonalMirroring(BmpImage* image);
    static void horizontalMirroring(Bmp24bpp* image);
    static void verticalMirroring(Bmp24bpp* image);
    static void diagonalMirroring(Bmp24bpp* image);
    static void horizontalMirroring(Bmp8bpp* image);
    static void verticalMirroring(Bmp8bpp* image);
    static void diagonalMirroring(Bmp8bpp* image);
};

#endif // MIRROR_H
