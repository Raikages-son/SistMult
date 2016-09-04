#include <iostream>
#include <bmpimage.h>
#include <mirror.h>

using namespace std;

int main(int argc, char *argv[]){

    BmpImage bmp("D:\\DatiPaolo\\Documents\\progetti\\SistMult\\dist512.bmp");
    Mirror::applyMirroring(bmp);
    bmp.save("D:\\DatiPaolo\\Documents\\progetti\\SistMult\\output.bmp");

    return 0;
}
