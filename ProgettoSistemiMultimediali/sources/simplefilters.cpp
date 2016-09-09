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
    }
    else{
        if(image8Bpp!= NULL)
            changeLight(image8Bpp,scale);
        else{
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

//Filtro di aumento o diminuzione luminosità - 24bpp
void simpleFilters::changeLight(Bmp24bpp* image, int scale){
    //Variabili ausiliarie per controllo limiti di luminosità e manipolazione immagine
    unsigned int color;
    unsigned char*** Map = image->getMap();

    for(int j=0; j<image->getHeight(); j++)
        for(int i=0; i<image->getWidth(); i++)
            for(int b=0; b<3; b++){
                color=Map[j][i][b];
                //Modifico la luminosità in base al valore inserito
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

//Filtro di aumento o diminuzione luminosità - 8bpp
void simpleFilters::changeLight(Bmp8bpp* image, int scale){
    //Variabili ausiliarie per controllo limiti di luminosità e manipolazione immagine
    unsigned int pixel;
    unsigned char** Map = image->getMap();

    for(int j=0; j<image->getHeight(); j++)
        for(int i=0; i<image->getWidth(); i++){
                pixel=Map[j][i];
                //Modifico la luminosità
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

//Filtro di aumento contrasto - 24bpp
void simpleFilters::changeContrast(Bmp24bpp* image, int scale){
    //Variabili ausiliarie
    int color;
    unsigned char*** Map = image->getMap();

    for(int j=0; j<image->getHeight(); j++)
        for(int i=0; i<image->getWidth(); i++)
            for(int b=0; b<3; b++){
                //Calcolo la tinta del nuovo pixel
                color=((Map[j][i][b]-scale)*255)/128;
                //Controllo che la tinta sia ammissibile
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

//Filtro di aumento contrasto - 8bpp
void simpleFilters::changeContrast(Bmp8bpp* image, int scale){
    //Variabili ausiliarie
    int pixel;
    unsigned char** Map = image->getMap();

    for(int j=0; j<image->getHeight(); j++)
        for(int i=0; i<image->getWidth(); i++){
            //Calcolo la tinta del nuovo pixel
            pixel=((Map[j][i]-scale)*255)/128;
            //Controllo che la tinta sia ammissibile
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

//Filtro di correzione di gamma - 24bpp
void simpleFilters::changeGamma(Bmp24bpp* image, float scale){
    //Variabili ausiliarie ed esponente di correzione
    float correction=1/scale;
    float color;
    unsigned char*** Map = image->getMap();

    for(int j=0; j<image->getHeight(); j++)
        for(int i=0; i<image->getWidth() ;i++)
            for(int b=0; b<3; b++){
                //Calcolo la nuova gamma
                color=Map[j][i][b];
                color=pow(color/255,correction)*255;
                //Controllo che il valore sia ammissibile
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

//Filtro di correzione di gamma - 8bpp
void simpleFilters::changeGamma(Bmp8bpp* image, float scale){
    float correction=1/scale;
    float pixel;
    unsigned char** Map = image->getMap();

    for(int j=0; j<image->getHeight(); j++)
        for(int i=0; i<image->getWidth() ;i++){
            //Calcolo la nuova gamma
            pixel=Map[j][i];
            pixel=pow(pixel/255,correction)*255;
            //Controllo che il valore sia ammissibile
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

//Filtro di desaturazione - 24bpp
void simpleFilters::desaturate(BmpImage *baseimage)
{
    Bmp24bpp* image= dynamic_cast < Bmp24bpp* > ( baseimage );
    if(image==NULL){
        cout<<"unsupported image type";
        exit(0);
    }
    //Varaibili ausiliarie
    unsigned char*** Map = image->getMap();
    int gray;

    for(int j=0; j<image->getHeight(); j++)
        for(int i=0; i<image->getWidth(); i++){
            //Uso una formula efficace per la desaturazione del colore
            //Calcolo il valore di grigio corretto in base alla reazione dell'occhio umano ai singoli colori
            gray=(Map[j][i][0]*0.11)+(Map[j][i][1]*0.59)+(Map[j][i][2]*0.3);
            for(int b=0; b<3; b++)
                Map[j][i][b]=gray;
        }
    image->editPMap(Map);
}
