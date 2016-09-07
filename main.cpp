#include <iostream>
#include "bmp24bpp.h"
#include "bmp8bpp.h"
#include "mirror.h"
#include "convolutionmatrix.h"
#include "Matrix.h"
#include "imageresizer.h"

using namespace std;

int main(int argc, char *argv[]){
    Bmp8bpp b = Bmp8bpp("D:\\DatiPaolo\\Documents\\progetti\\SistMult\\dist512.bmp");
    Bmp8bpp *bmpp = &b;

    int mSize = 3;
    bool sharpen = true;

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

    //ConvolutionMatrix::applyMask(bmpp,M,(mSize-1)/2);
    ImageResizer::resize(bmpp,-292,1077);
    bmpp->save("D:\\DatiPaolo\\Documents\\progetti\\SistMult\\output.bmp");
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

