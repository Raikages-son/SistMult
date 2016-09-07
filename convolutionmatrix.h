#ifndef CONVOLUTIONMATRIX_H
#define CONVOLUTIONMATRIX_H

#include "bmpimage.h"
#include "bmp24bpp.h"

class ConvolutionMatrix{
public:
    ConvolutionMatrix();
    static void applyMask(Bmp24bpp *image,int** Matrix,int range);

};

#endif // CONVOLUTIONMATRIX_H
