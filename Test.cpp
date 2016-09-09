//
// Created by biggeb4 on 08/09/16.
//

#include <string.h>
#include "Test.h"
#include "convolutionmatrix.h"
#include "Matrix.h"
#include "imageresizer.h"
#include "simplefilters.h"
#include "mirror.h"
#include "bpmFactory.h"

Test::Test() {}

void Test::test(string basepath) {
    string path=basepath;
    char* charpath=strdup(path.append("/test.bmp").c_str());
    BmpImage* img=bpmFactory::buildImg(charpath);
    ConvolutionMatrix::applyMask(img, Matrix::getBlur1(1), 1);
    path=basepath;
    char* outpath=strdup(path.append("/testResult/getBlur1.bmp").c_str());
    img->save(outpath);

    img=bpmFactory::buildImg(charpath);
    //ConvolutionMatrix::applyMask(img, Matrix::getBlur2(1), 1);
    path=basepath;
    outpath=strdup(path.append("/testResult/getBlur2.bmp").c_str());
    img->save(outpath);

    img=bpmFactory::buildImg(charpath);
    ConvolutionMatrix::applyMask(img, Matrix::getSharp1(1), 1);
    path=basepath;
    outpath=strdup(path.append("/testResult/getSharp1.bmp").c_str());
    img->save(outpath);

    img=bpmFactory::buildImg(charpath);
    ConvolutionMatrix::applyMask(img, Matrix::getSharp2(1), 1);
    path=basepath;
    outpath=strdup(path.append("/testResult/getSharp2.bmp").c_str());
    img->save(outpath);

    img=bpmFactory::buildImg(charpath);
    ConvolutionMatrix::applyMask(img, Matrix::getEdgeDetection1(1), 1);
    path=basepath;
    outpath=strdup(path.append("/testResult/getEdgeDetection1.bmp").c_str());
    img->save(outpath);

    img=bpmFactory::buildImg(charpath);
    ConvolutionMatrix::applyMask(img, Matrix::getEdgeDetection2(1), 1);
    path=basepath;
    outpath=strdup(path.append("/testResult/getEdgeDetection2.bmp").c_str());
    img->save(outpath);

    img=bpmFactory::buildImg(charpath);
    ConvolutionMatrix::applyMask(img, Matrix::getEdgeDetection3(1), 1);
    path=basepath;
    outpath=strdup(path.append("/testResult/getEdgeDetection3.bmp").c_str());
    img->save(outpath);




    img=bpmFactory::buildImg(charpath);
    ImageResizer::resize(img,200,200);
    path=basepath;
    outpath=strdup(path.append("/testResult/resize.bmp").c_str());
    img->save(outpath);


    img=bpmFactory::buildImg(charpath);
    simpleFilters::changeLight(img,100);
    path=basepath;
    outpath=strdup(path.append("/testResult/changeLight.bmp").c_str());
    img->save(outpath);

    img=bpmFactory::buildImg(charpath);
    simpleFilters::changeContrast(img,12);
    path=basepath;
    outpath=strdup(path.append("/testResult/changeContrast.bmp").c_str());
    img->save(outpath);

    img=bpmFactory::buildImg(charpath);
    simpleFilters::changeGamma(img,4);
    path=basepath;
    outpath=strdup(path.append("/testResult/changeGamma.bmp").c_str());
    img->save(outpath);

    img=bpmFactory::buildImg(charpath);
    simpleFilters::desaturate(img);
    path=basepath;
    outpath=strdup(path.append("/testResult/desaturate.bmp").c_str());
    img->save(outpath);



    img=bpmFactory::buildImg(charpath);
    Mirror::horizontalMirroring(img);
    path=basepath;
    outpath=strdup(path.append("/testResult/horizontalMirroring.bmp").c_str());
    img->save(outpath);

    img=bpmFactory::buildImg(charpath);
    Mirror::diagonalMirroring(img);
    path=basepath;
    outpath=strdup(path.append("/testResult/diagonalMirroring.bmp").c_str());
    img->save(outpath);

    img=bpmFactory::buildImg(charpath);
    Mirror::verticalMirroring(img);
    path=basepath;
    outpath=strdup(path.append("/testResult/verticalMirroring.bmp").c_str());
    img->save(outpath);

    exit(0);
}
