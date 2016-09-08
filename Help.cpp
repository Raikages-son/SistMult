//
// Created by biggeb4 on 08/09/16.
//
#include <iostream>
#include "Help.h"

using namespace std;
Help::Help() {}

void Help::help() {
    cout<<"list of commands and the explanation of their arguments and effects: "<<endl;

    cout<<" <path> <test>  : launches all the commands on test.bmp and store the results in the folder testResult,"<<endl;
    cout<<"  the first argument is a path to a folder containing a test.bpm image and a testResult folder, you can use the project folder"<<endl;
    cout<<endl;

    cout<<" <path> <convolution matrix filter> <strength> <range> <path> :"<<endl;
    cout<<"  the first argument is the path to the image to be edited"<<endl;
    cout<<"  the second argument is the filter to apply to the image, the available are: blur sharpen edge"<<endl;
    cout<<"  the third argument is the strength of the filter, "<<endl;
    cout<<"  the fourth argument is the range of the matrix,values over 10 are really slow to compute"<<endl;
    cout<<"  the fifth argument is the path to the output.bpm edited image"<<endl;
    cout<<endl;


    cout<<" <path> <resize> <width> <height> <path> :"<<endl;
    cout<<"  the first argument is the path to the image to be edited"<<endl;
    cout<<"  the second argument is \"resize\""<<endl;
    cout<<"  the third argument is new width that you want for the image"<<endl;
    cout<<"  the fourth argument is new height that you want for the image"<<endl;
    cout<<"  the fifth argument is the path to the output.bpm edited image"<<endl;
    cout<<endl;

    cout<<" <path> <scale filter> <scale> <path> :"<<endl;
    cout<<"  the first argument is the path to the image to be edited"<<endl;
    cout<<"  the second argument is the filter to apply to the image, the available are: "<<endl;
    cout<<"   light, that takes scale form -255 to 255"<<endl;
    cout<<"   gamma, that takes scale form 0 to 8"<<endl;
    cout<<"   contrast, that takes scale form 0 to 128"<<endl;
    cout<<"  the third argument is the path to the output.bpm edited image"<<endl;
    cout<<endl;

    cout<<" <path> <simple filter> <path> :"<<endl;
    cout<<"  the first argument is the path to the image to be edited"<<endl;
    cout<<"  the second argument is the filter to apply to the image, the available are: horizontalmirroring, diagonalmirroring, verticalmirroring, desaturate"<<endl;
    cout<<"  the third argument is the path to the output.bpm edited image"<<endl;
    cout<<endl;
    exit(0);
}