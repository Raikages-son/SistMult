//
// Created by biggeb4 on 08/09/16.
//

#ifndef SISTMULT_BPMFACTORY_H
#define SISTMULT_BPMFACTORY_H


#include "bmpimage.h"

class bpmFactory {
public:
    bpmFactory();
    static BmpImage* buildImg(const char *Path);
};


#endif //SISTMULT_BPMFACTORY_H
