#include <iostream>
#include <bmp24bpp.h>
#include <mirror.h>
#include <convolutionmatrix.h>

using namespace std;

int main(int argc, char *argv[]){

    Bmp24bpp bmp("D:\\DatiPaolo\\Desktop\\4k.bmp");
  //  Mirror::applyMirroring(bmp);

    // filtri di delineamento bordi
   // int M[3][3] ={ {-1,0,1},{0,0,0},{1,0,-1}};
   // int M[9] = {0,-1,0,-1,4,-1,0,-1,0};
   // int M[9] = {-1,-1,-1,-1, 8,-1,-1,-1,-1};

    // filtri di sharp
 //   int M[9] = {0,-1,0,-1,5,-1,0,-1,0};
  //  int M[3][3] = {{-1,-1,-1},{-1,9,-1},{-1,-1,-1}};

    int mSize = 7;
    bool sharpen = false;

    int **M = new int*[mSize];
    for(int j =0; j<mSize; j++){
        M[j] = new int[mSize];
        for(int i =0; i<mSize; i++){
            if(sharpen)
                M[j][i] = -1;
            else
                M[j][i] = 1;
        }
    }
    if(sharpen){
        M[(mSize-1)/2][(mSize-1)/2]=mSize*mSize+1;
    }

    // filtri di bleur
 // int M[3][3] ={ {1,1,1},{1,1,1},{1,1,1}};
  //  int M[9] = {1,2,1,2,4,2,1,2,1};

    ConvolutionMatrix::applyMask(bmp,M,(mSize-1)/2);

    bmp.save("D:\\DatiPaolo\\Documents\\progetti\\SistMult\\output.bmp");

    return 0;
}
