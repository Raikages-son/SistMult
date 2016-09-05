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
        if(argv[3]=="1"){

        }else {
            if (argv[3] == "2") {

            } else {
                cout<< "invalid argument for command blur"<<endl;
            }
        }

    }else {
        if(command=="sharpen") {
            if(argv[3]=="1"){

            }else {
                if (argv[3] == "2") {

                } else {
                    cout<< "invalid argument for command sharpen"<<endl;
                }
            }

        }else {
            if(command=="edgedetection") {
                if(argv[3]=="1"){

                }else{
                    if(argv[3]=="2"){

                    }else{
                        if(argv[3]=="3"){

                        }else{
                            cout<< "invalid argument for command edgedetection"<<endl;
                        }
                    }
                }

            }else {
                if(command=="mirror"){
                    Mirror::applyMirroring(img);
                    img.save(argv[3]);
                }else{
                    cout <<"unknown command: "<<command <<endl;
                }
            }
        }
    }
}
