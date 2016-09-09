//
// Created by biggeb4 on 05/09/16.
//

#ifndef SISTMULT_MATRIX_H
#define SISTMULT_MATRIX_H

#include<iostream>

using namespace::std;

class Matrix {
public:
    Matrix();
    static int** getEdgeDetection1(int range);
    static int** getEdgeDetection2(int range);
    static int** getEdgeDetection3(int range);
    static int** getBlur1(int range);
    static int** getBlur2(int range);
    static int** getSharp1(int range);
    static int** getSharp2(int range);

};


#endif //SISTMULT_MATRIX_H
