#ifndef CONVOLUTIONMATRIX_H
#define CONVOLUTIONMATRIX_H

#include "bmpimage.h"

class ConvolutionMatrix{
public:
    ConvolutionMatrix();
    static void apply3x3Mask(BmpImage image,const int *Matrix);

};

#endif // CONVOLUTIONMATRIX_H
