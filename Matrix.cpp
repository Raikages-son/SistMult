//
// Created by biggeb4 on 05/09/16.
//

#include "Matrix.h"

Matrix::Matrix() {}

int** Matrix::getEdgeDetection1(int range) {
    int size=range*2+1;
    int** matrix=new int*[size];
    for(int j=0; j<size;j++){
        matrix[j]=new int[size];
        for(int h=0; h<size; h++){
            if((j<size/2 && h<size/2)||(j>size/2 && h>size/2)) {
                matrix[j][h] = -1;
            }else{if((j>size/2 && h<size/2)||(j>size/2 && h>size/2)) {
                    matrix[j][h] = 1;
                }else{
                    matrix[j][h] = 0;
                }
            }
        }
    }
    return matrix;
    }

int** Matrix::getEdgeDetection2(int range) {
    int size=range*2+1;
    int** matrix=new int*[size];
    for(int j=0; j<size;j++){
        matrix[j]=new int[size];
        for(int h=0; h<size; h++){
            if((j==size/2 || h==size/2)) {
                if(j!=h) {
                    matrix[j][h] = -1;
                }else {
                    matrix[j][h] = 4;
                }
            }else{
                matrix[j][h] = 0;
            }
        }
    }
    return matrix;
}
    /*int** matrix=new int*[3];
    matrix[0] = new int[3]{0,-1,0};
    matrix[1] = new int[3]{-1,4,-1};
    matrix[2] = new int[3]{0,-1,0};


    matrix[0] = new int[5]{ 0, 0,-1, 0, 0};
    matrix[2] = new int[5]{ 0, 0,-1, 0, 0};
    matrix[1] = new int[5]{-1,-1, 4,-1,-1};
    matrix[0] = new int[5]{ 0, 0,-1, 0, 0};
    matrix[2] = new int[5]{ 0, 0,-1, 0, 0};

    return matrix;
}*/

int** Matrix::getEdgeDetection3(int range) {
        int size=range*2+1;
        int** matrix=new int*[size];
        for(int j=0; j<size;j++){
            matrix[j]=new int[size];
            for(int h=0; h<size; h++){
                if(j==size/2 && h==size/2) {
                    matrix[j][h] = 8;
                }else {
                    matrix[j][h] = -1;
                }
            }
        }
        return matrix;
    }
/*{
    int** matrix=new int*[3];
    matrix[0] = new int[3]{-1,-1,-1};
    matrix[1] = new int[3]{-1, 8,-1};
    matrix[2] = new int[3]{-1,-1,-1};
    return matrix;
}*/
int** Matrix::getBlur1(int range) {
    int size=range*2+1;
    int** matrix=new int*[size];
    for(int j=0; j<size;j++){
        matrix[j]=new int[size];
        for(int h=0; h<size; h++){
            matrix[j][h] = 1;
        }
    }
    return matrix;
}
/*
    int** matrix=new int*[3];
    matrix[0] = new int[3]{1,1,1};
    matrix[1] = new int[3]{1,1,1};
    matrix[2] = new int[3]{1,1,1};
    return matrix;
}*/
int** Matrix::getBlur2(int range) {
    int size=range*2+1;
    int** matrix=new int*[size];
    for(int j=0; j<size;j++){
        matrix[j]=new int[size];
        for(int h=0; h<size; h++){
            if((j==size/2 || h==size/2)) {
                if(j!=h) {
                    matrix[j][h] = 2;
                }else {
                    matrix[j][h] = 4;
                }
            }else{
                matrix[j][h] = 1;
            }
        }
    }
    return matrix;
}
/*
    int** matrix=new int*[3];
    matrix[0] = new int[3]{1,2,1};
    matrix[1] = new int[3]{2,4,2};
    matrix[2] = new int[3]{1,2,1};
    return matrix;
}*/
int** Matrix::getSharp1(int range) {
    int size=range*2+1;
    int** matrix=new int*[size];
    for(int j=0; j<size;j++){
        matrix[j]=new int[size];
        for(int h=0; h<size; h++){
            if((j==size/2 || h==size/2)) {
                if(j!=h) {
                    matrix[j][h] = -1;
                }else {
                    matrix[j][h] = 5;
                }
            }else{
                matrix[j][h] = 0;
            }
        }
    }
    return matrix;
}
/*
    int** matrix=new int*[3];
    matrix[0] = new int[3]{0,-1,0};
    matrix[1] = new int[3]{-1,5,-1};
    matrix[2] = new int[3]{0,-1,0};
    return matrix;
}*/
int** Matrix::getSharp2(int range) {
    int size=range*2+1;
    int** matrix=new int*[size];
    for(int j=0; j<size;j++){
        matrix[j]=new int[size];
        for(int h=0; h<size; h++){
            if(j==size/2 && h==size/2) {
                matrix[j][h] = 9;
            }else {
                matrix[j][h] = -1;
            }
        }
    }
    return matrix;
}
/*
    int** matrix=new int*[3];
    matrix[0] = new int[3]{-1,-1,-1};
    matrix[1] = new int[3]{-1,9,-1};
    matrix[2] = new int[3]{-1,-1,-1};
    return matrix;
}*/