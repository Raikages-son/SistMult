#include <iostream>
#include <bmpimage.h>

using namespace std;

int main(int argc, char *argv[]){

    BmpImage bmp("D:\\DatiPaolo\\Documents\\progetti\\SistMult\\kimi512.bmp");
    bmp.mirror();
    bmp.save("D:\\DatiPaolo\\Documents\\progetti\\SistMult\\output.bmp");

    return 0;
}
