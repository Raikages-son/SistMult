#include <climits>
#include "simplefilters.h"

simpleFilters::simpleFilters()
{

}

void simpleFilters::changeLight(BmpImage *image, int scale) {
    Bmp24bpp* image24Bpp= dynamic_cast < Bmp24bpp* > ( image );
    Bmp8bpp* image8Bpp=dynamic_cast < Bmp8bpp* > ( image );
    if(image24Bpp!= NULL){
        changeLight(image24Bpp,scale);
    }else{
        if(image8Bpp!= NULL){
            changeLight(image8Bpp,scale);
        }else{
            cout<<"unsupported image type";
            exit(0);
        }

    }

}

void simpleFilters::changeContrast(BmpImage *image, int scale) {
    Bmp24bpp* image24Bpp= dynamic_cast < Bmp24bpp* > ( image );
    Bmp8bpp* image8Bpp=dynamic_cast < Bmp8bpp* > ( image );
    if(image24Bpp!= NULL){
        changeContrast(image24Bpp,scale);
    }else{
        if(image8Bpp!= NULL){
            changeContrast(image8Bpp,scale);
        }else{
            cout<<"unsupported image type";
            exit(0);
        }

    }

}



void simpleFilters::changeLight(Bmp24bpp* image, int scale){
    //Variabili ausiliarie per controllo limiti di luminosità e manipolazione immagine
    unsigned int color;
    unsigned char*** Map = image->getMap();

    for(int j=0; j<image->getHeight(); j++)
        for(int i=0; i<image->getWidth(); i++)
            for(int b=0; b<3; b++){
                color=Map[j][i][b];
                //Aumento la luminosità
                color=color+scale;
                //Controllo la nuova tinta
                if(color>255)
                    Map[j][i][b]=255;
                else{
                    if(color<0)
                        Map[j][i][b]=0;
                    else
                        Map[j][i][b]=color;
                }
            }
    image->editPMap(Map);
}

void simpleFilters::changeLight(Bmp8bpp* image, int scale){

    unsigned int pixel;
    unsigned char** Map = image->getMap();

    for(int j=0; j<image->getHeight(); j++)
        for(int i=0; i<image->getWidth(); i++){
                pixel=Map[j][i];
                //Aumento la luminosità
                pixel+=scale;
                //Controllo il nuovo pixel
                if(pixel>255)
                    Map[j][i]=255;
                else{

                    if(pixel<0)
                        Map[j][i]=0;
                    else
                        Map[j][i]=pixel;
                }
            }
    image->editPMap(Map);
}

void simpleFilters::changeContrast(Bmp24bpp* image, int scale){

    int color;
    unsigned char*** Map = image->getMap();

    for(int j=0; j<image->getHeight(); j++)
        for(int i=0; i<image->getWidth(); i++)
            for(int b=0; b<3; b++){
                color=(Map[j][i][b]*255)/128;
                color-=(255*scale)/128;
                if(color>255)
                    Map[j][i][b]=255;
                else{
                    if(color<0)
                        Map[j][i][b]=0;
                    else
                        Map[j][i][b]=color;
                }
            }

    image->editPMap(Map);
}

void simpleFilters::changeContrast(Bmp8bpp* image, int scale){

    int pixel;
    unsigned char** Map = image->getMap();

    for(int j=0; j<image->getHeight(); j++)
        for(int i=0; i<image->getWidth(); i++){
            pixel=(Map[j][i]*256)/128;
            pixel-=(256*scale/128);
            if(pixel>255)
                Map[j][i]=255;
            else{
                if(pixel<0)
                    Map[j][i]=0;
                else
                    Map[j][i]=pixel;
            }
        }
    image->editPMap(Map);
}

void simpleFilters::changeGamma(Bmp24bpp* image, float scale){
    float correction=1/scale;
    float color;
    unsigned char*** Map = image->getMap();

    for(int j=0; j<image->getHeight(); j++)
        for(int i=0; i<image->getWidth() ;i++)
            for(int b=0; b<3; b++){
                color=Map[j][i][b];
                color=pow(color/255,correction)*255;
                if(color>255)
                    Map[j][i][b]=255;
                else{
                    if(color<0)
                        Map[j][i][b]=0;
                    else
                        Map[j][i][b]=color;
                }
            }
    image->editPMap(Map);
}

void simpleFilters::changeGamma(Bmp8bpp* image, float scale){
    float correction=1/scale;
    float pixel;
    unsigned char** Map = image->getMap();

    for(int j=0; j<image->getHeight(); j++)
        for(int i=0; i<image->getWidth() ;i++){
            pixel=Map[j][i];
            pixel=pow(pixel/255,correction)*255;
            if(pixel>255)
                Map[j][i]=255;
            else{
                if(pixel<0)
                    Map[j][i]=0;
                else
                    Map[j][i]=pixel;
            }
        }
    image->editPMap(Map);
}

void simpleFilters::desaturate(BmpImage *baseimage)
{
    Bmp24bpp* image= dynamic_cast < Bmp24bpp* > ( baseimage );
    if(image==NULL){
        cout<<"unsupported image type";
        exit(0);
    }
    unsigned char*** Map = image->getMap();
    int gray, min, max;

    for(int j=0; j<image->getHeight(); j++)
        for(int i=0; i<image->getWidth(); i++){
            max=0;
            min=INT_MAX;
            for(int b=0; b<3; b++){
                if(Map[j][i][b]>max)
                    max=Map[j][i][b];
                if(Map[j][i][b]<min)
                    min=Map[j][i][b];
            }
            //Uso una formula veloce per la desaturazione del colore
            gray=(max+min)/2;
            for(int b=0; b<3; b++)
                Map[j][i][b]=gray;
        }
    image->editPMap(Map);
}

void simpleFilters::changeGamma(BmpImage *image, float scale) {
    Bmp24bpp* image24Bpp= dynamic_cast < Bmp24bpp* > ( image );
    Bmp8bpp* image8Bpp=dynamic_cast < Bmp8bpp* > ( image );
    if(image24Bpp!= NULL){
        changeGamma(image24Bpp,scale);
    }else{
        if(image8Bpp!= NULL){
            changeGamma(image8Bpp,scale);
        }else{
            cout<<"unsupported image type";
            exit(0);
        }

    }

}
