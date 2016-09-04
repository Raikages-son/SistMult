#ifndef MIRROR_H
#define MIRROR_H

#include <bmpimage.h>

class Mirror
{
public:
    Mirror();
    static void applyMirroring(BmpImage image);
};

#endif // MIRROR_H
