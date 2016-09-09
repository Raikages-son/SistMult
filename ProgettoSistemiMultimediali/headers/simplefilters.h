#ifndef SIMPLEFILTERS_H
#define SIMPLEFILTERS_H

#include "bmpimage.h"
#include "bmp24bpp.h"
#include "bmp8bpp.h"
#include <math.h>

class simpleFilters
{
public:
    simpleFilters();

    static void changeLight(BmpImage* image, int scale);
    static void changeLight(Bmp24bpp* image, int scale);
    static void changeLight(Bmp8bpp* image, int scale);

    static void changeContrast(BmpImage* image, int scale);
    static void changeContrast(Bmp24bpp* image, int scale);
    static void changeContrast(Bmp8bpp* image, int scale);

    static void changeGamma(BmpImage* image, float scale);
    static void changeGamma(Bmp24bpp* image, float scale);
    static void changeGamma(Bmp8bpp* image, float scale);

    static void desaturate(BmpImage* baseimage);
};

#endif // SIMPLEFILTERS_H
