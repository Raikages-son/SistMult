//
// Created by biggeb4 on 05/09/16.
//

#include "Matrix.h"

Matrix::Matrix() {}

int** Matrix::getEdgeDetection1(int range) {
    int** matrix=new int*[3];
    matrix[0] = new int[3]{-1, 0, 1};
    matrix[1] = new int[3]{0, 0, 0};
    matrix[2] = new int[3]{1, 0, -1};
    return matrix;
    }

int** Matrix::getEdgeDetection2(int range) {
    int** matrix=new int*[3];
    matrix[0] = new int[3]{0,-1,0};
    matrix[1] = new int[3]{-1,4,-1};
    matrix[2] = new int[3]{0,-1,0};
    return matrix;
}

int** Matrix::getEdgeDetection3(int range) {
    int** matrix=new int*[3];
    matrix[0] = new int[3]{-1,-1,-1};
    matrix[1] = new int[3]{-1, 8,-1};
    matrix[2] = new int[3]{-1,-1,-1};
    return matrix;
}
int** Matrix::getBlur1(int range) {
    int** matrix=new int*[3];
    matrix[0] = new int[3]{1,1,1};
    matrix[1] = new int[3]{1,1,1};
    matrix[2] = new int[3]{1,1,1};
    return matrix;
}
int** Matrix::getBlur2(int range) {
    int** matrix=new int*[3];
    matrix[0] = new int[3]{1,2,1};
    matrix[1] = new int[3]{2,4,2};
    matrix[2] = new int[3]{1,2,1};
    return matrix;
}
int** Matrix::getSharp1(int range) {
    int** matrix=new int*[3];
    matrix[0] = new int[3]{0,-1,0};
    matrix[1] = new int[3]{-1,5,-1};
    matrix[2] = new int[3]{0,-1,0};
    return matrix;
}
int** Matrix::getSharp2(int range) {
    int** matrix=new int*[3];
    matrix[0] = new int[3]{-1,-1,-1};
    matrix[1] = new int[3]{-1,9,-1};
    matrix[2] = new int[3]{-1,-1,-1};
    return matrix;
}