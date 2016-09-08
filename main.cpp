#include <iostream>
#include "bmp24bpp.h"
#include "bmp8bpp.h"
#include "mirror.h"
#include "convolutionmatrix.h"
#include "Matrix.h"
#include "imageresizer.h"
#include "simplefilters.h"
#include <stdexcept>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]){
    if(argc<4){
        cout<< "not enougth arguments, at list 4 needed"<<endl;
        exit(0);
    }
    string command=argv[2];
    cout <<command<<endl;
    Bmp24bpp bmp = Bmp24bpp(argv[1]);
    Bmp24bpp *img=  &bmp;
    switch(argc) {
        case 6: {
            if (command == "blur" || command == "sharpen" || command == "edge") {
                string streght = argv[3];
                int range = 0;
                try {
                    range = stoi(argv[4]);
                    if (range < 1) {
                        throw std::invalid_argument("must be bigger than 0");
                    }
                    if (range > 10) {
                        cout << "with a range bigger than 10, operation become really slow" << endl;
                    }
                }
                catch (invalid_argument e) {
                    cout << "invalid range :" << argv[4] << e.what() << endl;
                }
                if (command == "blur") {
                    if (streght == "1") {
                        ConvolutionMatrix::applyMask(img, Matrix::getBlur1(range), range);
                    } else {
                        ConvolutionMatrix::applyMask(img, Matrix::getBlur2(range), range);
                    }
                } else {
                    if (command == "sharpen") {
                        if (streght == "1") {
                            ConvolutionMatrix::applyMask(img, Matrix::getSharp1(range), range);
                        } else {
                            ConvolutionMatrix::applyMask(img, Matrix::getSharp2(range), range);
                        }
                    } else {
                        if (command == "edge") {
                            if (streght == "1") {
                                ConvolutionMatrix::applyMask(img, Matrix::getEdgeDetection1(range), range);
                            } else {
                                if (streght == "2") {
                                    ConvolutionMatrix::applyMask(img, Matrix::getEdgeDetection2(range), range);
                                } else {
                                    ConvolutionMatrix::applyMask(img, Matrix::getEdgeDetection3(range), range);
                                }
                            }
                        }
                    }
                }
            }else{
                if(command=="resize"){
                    int with=0;
                    int height=0;
                    try {
                        with= stoi(argv[3]);
                        height= stoi(argv[4]);
                    }catch (invalid_argument e){
                        cout << "invalid arguments for height or/and width"<<endl;
                    }
                    ImageResizer::resize(img,with,height);
                }else{
                    cout << "unknown 5 arguments command: " << command << endl;
                }
            }
            img->save(argv[5]);
            break;
        }
        case 5:{
            if(command=="light"){
                int scale=0;
                try {
                    scale= stoi(argv[3]);
                }catch (invalid_argument e){
                    cout << "invalid arguments for scale"<<endl;
                }
                simpleFilters::changeLight(img,scale);
            }else{
                if(command=="gamma"){
                    int scale=0;
                    try {
                        scale= stoi(argv[3]);
                    }catch (invalid_argument e){
                        cout << "invalid arguments for scale"<<endl;
                    }
                    simpleFilters::changeGamma(img,scale);

                }else{
                    cout << "unknown 4 arguments command: " << command << endl;
                }
            }
            img->save(argv[4]);
            break;
        }
        case 4:{
            if(command=="mirror"){
                Mirror::horizontalMirroring(img);
            }else{
                if(command=="contrast"){
                    simpleFilters::changeContrast(img);
                }else {
                    cout << "unknown 3 arguments command: " << command << endl;
                }
            }
            break;
            img->save(argv[3]);
        }
        default:{
            cout <<"unknown command with: "<<argc<<" arguments"<<endl;
            break;
        }
    }
    exit(0);
}

