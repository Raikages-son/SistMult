#include <iostream>
#include "bmp24bpp.h"
#include "mirror.h"
#include "convolutionmatrix.h"
#include "Matrix.h"
#include "imageresizer.h"

using namespace std;

int main(int argc, char *argv[]){
    if(argc<4){
        cout<< "not enougth arguments, at list 4 needed"<<endl;
        exit(0);
    }
    string command=argv[2];
    cout <<command;
    Bmp24bpp bmp = Bmp24bpp(argv[1]);
    Bmp24bpp *img=  &bmp;
    if(command=="blur"||command=="sharpen"||command=="edge"){
        if(argc<6){
            cout<< "not enougth arguments for command:"+command+", 5 needed"<<endl;
            exit(0);
        }
        string streght=argv[3];
        int range=0;
        try {
            range=stoi(argv[4]);
            if(range!=1){
                throw std::invalid_argument("must be 1");
            }
        }
        catch( invalid_argument e){
            cout<< "invalid range :"<<argv[4]<<e.what()<<endl;
            exit(0);
        }
        if(command=="blur"){
            if(streght=="1") {
                ConvolutionMatrix::applyMask(img, Matrix::getBlur1(range), range);
            }else{
                ConvolutionMatrix::applyMask(img, Matrix::getBlur2(range), range);
            }
        }else{
            if(command=="sharpen"){
                if(streght=="1") {
                    ConvolutionMatrix::applyMask(img, Matrix::getSharp1(range), range);
                }else{
                    ConvolutionMatrix::applyMask(img, Matrix::getSharp2(range), range);
                }
            }else{
                if(command=="edge") {
                    if(streght=="1") {
                        ConvolutionMatrix::applyMask(img, Matrix::getEdgeDetection1(range), range);
                    }else{
                        if(streght=="2") {
                            ConvolutionMatrix::applyMask(img, Matrix::getEdgeDetection2(range), range);
                        }else{
                            ConvolutionMatrix::applyMask(img, Matrix::getEdgeDetection3(range), range);
                        }
                    }
                }

            }
        }
        img->save(argv[5]);
        exit(0);
    }else {
        if(command=="mirror"){
            Mirror::horizontalMirroring(bmp);
            img->save(argv[3]);
        }else{
            cout <<"unknown command: "<<command <<endl;
        }
    }
}

