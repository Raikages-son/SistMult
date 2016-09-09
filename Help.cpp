//
// Created by biggeb4 on 08/09/16.
//
#include <iostream>
#include "Help.h"

using namespace std;
Help::Help() {}

void Help::help() {
    cout<<"List of commands and explanation of their arguments and effects: "<<endl;

    cout<<" <path> <test>  : launches all the commands on test.bmp and stores the results in the testResult folder"<<endl;
    cout<<"  The first argument is a path to a folder containing a test.bmp image and a testResult folder, you can use the project folder."<<endl;
    cout<<endl;

    cout<<" <path> <convolution matrix filter> <variant> <range> <path> :"<<endl;
    cout<<"  The first argument is the path to the image to be edited"<<endl;
    cout<<"  The second argument is the filter to apply to the image, the available ones are: blur sharpen edge"<<endl;
    cout<<"  The third argument is the variant of the filter, 1 or 2 for blur and sharpen, 1 to 3 for edge"<<endl;
    cout<<"  The fourth argument is the range of the matrix, values over 10 are really slow to compute"<<endl;
    cout<<"  The fifth argument is the path to the output.bmp edited image"<<endl;
    cout<<endl;


    cout<<" <path> <resize> <width> <height> <path> :"<<endl;
    cout<<"  The first argument is the path to the image to be edited"<<endl;
    cout<<"  The second argument is \"resize\""<<endl;
    cout<<"  The third argument is the new width you want for the image"<<endl;
    cout<<"  The fourth argument is the new height you want for the image"<<endl;
    cout<<"  The fifth argument is the path to the output.bmp edited image"<<endl;
    cout<<endl;

    cout<<" <path> <scale filter> <scale> <path> :"<<endl;
    cout<<"  The first argument is the path to the image to be edited"<<endl;
    cout<<"  The second argument is the filter to apply to the image, the available are: "<<endl;
    cout<<"   light, that takes values from -255 to 255"<<endl;
    cout<<"   gamma, that takes values from 0 to 8"<<endl;
    cout<<"   contrast, that takes scale form 0 to 128"<<endl;
    cout<<"  The third argument is the path to the output.bmp edited image"<<endl;
    cout<<endl;

    cout<<" <path> <simple filter> <path> :"<<endl;
    cout<<"  The first argument is the path to the image to be edited"<<endl;
    cout<<"  The second argument is the filter to apply to the image, the available are: horizontalmirroring, diagonalmirroring, verticalmirroring, desaturate"<<endl;
    cout<<"     Note that the desaturate command is only available for 24bpp images"<<endl;
    cout<<"  The third argument is the path to the output.bmp edited image"<<endl;
    cout<<endl;
    exit(0);
}
