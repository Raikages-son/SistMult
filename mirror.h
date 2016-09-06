#ifndef MIRROR_H
#define MIRROR_H

#include "bmpimage.h"
#include "bmp24bpp.h"

class Mirror
{
public:
    Mirror();
    static void horizontalMirroring(Bmp24bpp image);
    static void verticalMirroring(Bmp24bpp image);
    static void diagonalMirroring(Bmp24bpp image);
};

#endif // MIRROR_H
