#include <iostream>
#include <bmp24bpp.h>
#include <mirror.h>
#include <convolutionmatrix.h>

using namespace std;

int main(int argc, char *argv[]){

    Bmp24bpp bmp("D:\\DatiPaolo\\Documents\\progetti\\SistMult\\kimi512.bmp");
  //  Mirror::applyMirroring(bmp);

    // filtri di delineamento bordi
   // int M[9] = {-1,0,1,0,0,0,1,0,-1};
   // int M[9] = {0,-1,0,-1,4,-1,0,-1,0};
   // int M[9] = {-1,-1,-1,-1, 8,-1,-1,-1,-1};

    // filtri di sharp
 //   int M[9] = {0,-1,0,-1,5,-1,0,-1,0};
  //  int M[9] = {-1,-1,-1,-1,9,-1,-1,-1,-1};

    // filtri di bleur
  //  int M[9] = {1,1,1,1,1,1,1,1,1};
  //  int M[9] = {1,2,1,2,4,2,1,2,1};

 //   ConvolutionMatrix::apply3x3Mask(bmp,M);

    bmp.save("D:\\DatiPaolo\\Documents\\progetti\\SistMult\\output.bmp");

    return 0;
}
