//
// Created by biggeb4 on 05/09/16.
//

#ifndef SISTMULT_MATRIX_H
#define SISTMULT_MATRIX_H


class Matrix {
public:
    Matrix();
    static int** getEdgeDetection1();
    static int** getEdgeDetection2();
    static int** getEdgeDetection3();
    static int** getBlur1();
    static int** getBlur2();
    static int** getSharp1();
    static int** getSharp2();

};


#endif //SISTMULT_MATRIX_H
