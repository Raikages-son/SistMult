#include "simplefilters.h"

simpleFilters::simpleFilters()
{

}

static void changeLight(Bmp24bpp* image, int scale){
    //Variabili ausiliarie per controllo limiti di luminosità e manipolazione immagine
    unsigned int color;
    unsigned char*** Map = image->getMap();

    for(int j=0; j<image->getHeight(); j++)
        for(int i=0; i<image->getWidth(); i++)
            for(int b=0; b<3; b++){
                color=Map[j][i][b];
                //Controllo la nuova tinta
                color=(color*scale)/255;
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

static void changeLight(Bmp8bpp* image, int scale){

    unsigned int pixel;
    unsigned char** Map = image->getMap();

    for(int j=0; j<image->getHeight(); j++)
        for(int i=0; i<image->getWidth(); i++){
                pixel=Map[j][i];
                pixel=(pixel*scale)/255;
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

static void changeContrast(Bmp24bpp* image){

    int color;
    unsigned char*** Map = image->getMap();

    for(int j=0; j<image->getHeight(); j++)
        for(int i=0; i<image->getWidth(); i++)
            for(int b=0; b<3; b++){
                color=(Map[j][i][b]*255)/120;
                color-=(255*80/120);
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

static void changeContrast(Bmp8bpp* image){

    int pixel;
    unsigned char** Map = image->getMap();

    for(int j=0; j<image->getHeight(); j++)
        for(int i=0; i<image->getWidth(); i++){
            pixel=(Map[j][i]*255)/120;
            pixel-=(255*80/120);
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

static void changeGamma(Bmp24bpp* image, int scale){

    int color;
    unsigned char*** Map = image->getMap();

    for(int j=0; j<image->getHeight(); j++)
        for(int i=0; i<image->getWidth() ;i++)
            for(int b=0; b<3; b++){
                color=Map[j][i][b];
                color=pow(color/255,scale)*255;
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

static void changeGamma(Bmp8bpp* image, int scale){

    int pixel;
    unsigned char** Map = image->getMap();

    for(int j=0; j<image->getHeight(); j++)
        for(int i=0; i<image->getWidth() ;i++){
            pixel=Map[j][i];
            pixel=pow(pixel/255,scale)*255;
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
