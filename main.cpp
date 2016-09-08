#include <iostream>
#include "bmp24bpp.h"
#include "bmp8bpp.h"
#include "mirror.h"
#include "convolutionmatrix.h"
#include "Matrix.h"
#include "imageresizer.h"
#include "simplefilters.h"
#include "bpmFactory.h"
#include "Test.h"
#include "Help.h"
#include <stdexcept>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]){
    if(argc<2){
        cout<< "Not enough arguments, at least 1 is needed, launch with -help to have all the information about the possible commands and arguments"<<endl;
        exit(0);
    }
    string command;
    BmpImage *img;
    if(argc>2){
        command=argv[2];
        img= bpmFactory::buildImg(argv[1]);
    }else{
        command=argv[1];
    }
    cout <<command<<endl;
    switch(argc) {
        case 2:{
            if(command=="help"){
                Help::help();
            }else{
                cout << "unknown 1 argument command: " << command << endl;
            }
            break;
        }
        case 3:{
            if(command=="test") {
                Test::test(argv[1]);
            }else{
                cout << "unknown 2 arguments command: " << command << endl;
            }
            break;
        }
        case 6: {
            if (command == "blur" || command == "sharpen" || command == "edge") {
                string strength = argv[3];
                int range = 0;
                try {
                    range = stoi(argv[4]);
                    if (range < 1) {
                        throw std::invalid_argument("Must be bigger than 0");
                    }
                    if (range > 10) {
                        cout << "With a range bigger than 10 the operation becomes really slow" << endl;
                    }
                }
                catch (invalid_argument e) {
                    cout << "invalid range :" << argv[4] << e.what() << endl;
                }
                if (command == "blur") {
                    if (strength == "1") {
                        ConvolutionMatrix::applyMask(img, Matrix::getBlur1(range), range);
                    } else {
                        ConvolutionMatrix::applyMask(img, Matrix::getBlur2(range), range);
                    }
                } else {
                    if (command == "sharpen") {
                        if (strength == "1") {
                            ConvolutionMatrix::applyMask(img, Matrix::getSharp1(range), range);
                        } else {
                            ConvolutionMatrix::applyMask(img, Matrix::getSharp2(range), range);
                        }
                    } else {
                        if (command == "edge") {
                            if (strength == "1") {
                                ConvolutionMatrix::applyMask(img, Matrix::getEdgeDetection1(range), range);
                            } else {
                                if (strength == "2") {
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
                        cout << "Invalid arguments for height and/or width"<<endl;
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
            int scale=0;
            if(command=="light"){
                try {
                    scale= stoi(argv[3]);
                }catch (invalid_argument e){
                    cout << "invalid arguments for scale"<<endl;
                }
                simpleFilters::changeLight(img,scale);
            }else{
                if(command=="gamma"){
                    try {
                        scale= stoi(argv[3]);
                    }catch (invalid_argument e){
                        cout << "invalid arguments for scale"<<endl;
                    }
                    simpleFilters::changeGamma(img,scale);

                }else{
                    if(command=="contrast"){
                        try {
                            scale= stoi(argv[3]);
                        }catch (invalid_argument e){
                            cout << "invalid arguments for scale"<<endl;
                        }
                        simpleFilters::changeContrast(img,scale);
                    }else {
                        cout << "unknown 4 arguments command: " << command << endl;
                    }
                }
            }
            img->save(argv[4]);
            break;
        }
        case 4:{
            if(command=="horizontalmirroring"){
                Mirror::horizontalMirroring(img);
            }else {
                if (command == "desaturate") {
                    simpleFilters::desaturate(img);
                } else {
                    if (command == "verticalmirroring") {
                        Mirror::verticalMirroring(img);
                    } else {
                        if (command == "diagonalmirroring") {
                            Mirror::diagonalMirroring(img);
                        } else {
                            cout << "unknown 3 arguments command: " << command << endl;
                        }
                    }
                }
            }
            img->save(argv[3]);
            break;
        }
        default:{
            cout <<"unknown command with: "<<argc<<" arguments"<<endl;
            break;
        }
    }

}

