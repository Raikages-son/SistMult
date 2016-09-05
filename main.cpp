#include <iostream>
#include "bmpimage.h"
#include "mirror.h"
#include "convolutionmatrix.h"
#include "Matrix.h"
#include <string>

using namespace std;

int main(int argc, char *argv[]){
    string command=argv[2];
    cout <<command;
    BmpImage img=BmpImage(argv[1]);
    if(command=="blur") {

    }else {
        if(command=="sharpen") {

        }else {
            if(command=="edgedetection") {

            }else {
                if(command=="mirror"){
                    Mirror::applyMirroring(img);
                    img.save(argv[3]);
                }
            }
        }
    }
}
