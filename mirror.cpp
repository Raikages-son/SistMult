#include "mirror.h"

Mirror::Mirror(){

}

void Mirror::horizontalMirroring(BmpImage* image){
    Bmp24bpp* image24Bpp= dynamic_cast < Bmp24bpp* > ( image );
    Bmp8bpp* image8Bpp=dynamic_cast < Bmp8bpp* > ( image );
    if(image24Bpp!= NULL){
        horizontalMirroring(image24Bpp);
    }else{
        if(image8Bpp!= NULL){
            horizontalMirroring(image8Bpp);
        }else{
            cout<<"unsupported image type";
            exit(0);
        }

    }
}

void Mirror::verticalMirroring(BmpImage* image){
    Bmp24bpp* image24Bpp= dynamic_cast < Bmp24bpp* > ( image );
    Bmp8bpp* image8Bpp=dynamic_cast < Bmp8bpp* > ( image );
    if(image24Bpp!= NULL){
        verticalMirroring(image24Bpp);
    }else{
        if(image8Bpp!= NULL){
            verticalMirroring(image8Bpp);
        }else{
            cout<<"unsupported image type";
            exit(0);
        }

    }
}

void Mirror::diagonalMirroring(BmpImage* image){
    Bmp24bpp* image24Bpp= dynamic_cast < Bmp24bpp* > ( image );
    Bmp8bpp* image8Bpp=dynamic_cast < Bmp8bpp* > ( image );
    if(image24Bpp!= NULL){
        diagonalMirroring(image24Bpp);
    }else{
        if(image8Bpp!= NULL){
            diagonalMirroring(image8Bpp);
        }else{
            cout<<"unsupported image type";
            exit(0);
        }

    }
}

void Mirror::horizontalMirroring(Bmp24bpp* image){
    //Prendo l'altezza della mappa in pixel
    int imageH = image->getHeight();

    //Prendo la larghezza della mappa in pixel
    int imageW = image->getWidth();

    //Metto un puntatore all'inizio della mappa di byte dell'immagine
    unsigned char*** Map = image->getMap();

    //Pixel ausiliario
    unsigned char *Aux=new unsigned char[3];

    //Scorro solo metà delle colonne; scorrerle tutte annullerebbe l'effetto
    for(int j=0; j<imageH; j++)
        for(int i=0; i<(imageW/2); i++)
            for(int b=0; b<3; b++){
                //Carico pixel ausiliario
                Aux[b]=Map[j][i][b];
                //Scambio pixel con opposto
                Map[j][i][b]=Map[j][imageW-i-1][b];
                //Inserisco pixel ausiliario
                Map[j][imageW-i-1][b]=Aux[b];
            }
    image->editPMap(Map);
}

void Mirror::verticalMirroring(Bmp24bpp* image){
    //Prendo l'altezza della mappa in pixel
    int imageH = image->getHeight();

    //Prendo la larghezza della mappa in pixel
    int imageW = image->getWidth();

    //Metto un puntatore all'inizio della mappa di byte dell'immagine
    unsigned char*** Map = image->getMap();

    //Pixel ausiliario
    unsigned char *Aux=new unsigned char[3];

    //Scorro solo metà delle righe; scorrerle tutte annullerebbe l'effetto
    for(int j=0; j<(imageH/2); j++)
        for(int i=0; i<imageW; i++)
            for(int b=0; b<3; b++){
                //Carico pixel ausiliario
                Aux[b]=Map[j][i][b];
                //Scambio pixel con opposto
                Map[j][i][b]=Map[imageH-j-1][i][b];
                //Inserisco pixel ausiliario
                Map[imageH-j-1][i][b]=Aux[b];
            }
    image->editPMap(Map);
}

void Mirror::diagonalMirroring(Bmp24bpp *image){
    //Prendo l'altezza della mappa in pixel
    int imageH = image->getHeight();

    //Prendo la larghezza della mappa in pixel
    int imageW = image->getWidth();

    //Metto un puntatore all'inizio della mappa di byte dell'immagine
    unsigned char*** Map = image->getMap();

    //Pixel ausiliario
    unsigned char *Aux=new unsigned char[3];

    //Scorro solo metà delle righe; scorrere metà delle colonne non cambia il risultato
    for(int j=0; j<imageH; j++)
        for(int i=0; i<(imageW/2); i++)
            for(int b=0; b<3; b++){
                //Carico pixel ausiliario
                Aux[b]=Map[j][i][b];
                //Scambio pixel con opposto
                Map[j][i][b]=Map[imageH-j-1][imageW-i-1][b];
                //Inserisco pixel ausiliario
                Map[imageH-j-1][imageW-i-1][b]=Aux[b];
            }
    image->editPMap(Map);
}

void Mirror::horizontalMirroring(Bmp8bpp* image){
    //Prendo l'altezza della mappa in pixel
    int imageH = image->getHeight();

    //Prendo la larghezza della mappa in pixel
    int imageW = image->getWidth();

    //Metto un puntatore all'inizio della mappa di byte dell'immagine
    unsigned char** Map = image->getMap();

    //Pixel ausiliario
    unsigned char *Aux=new unsigned char;

    //Scorro solo metà delle colonne; scorrerle tutte annullerebbe l'effetto
    for(int j=0; j<imageH; j++)
        for(int i=0; i<imageW/2; i++){
                //Carico pixel ausiliario
                *Aux=Map[j][i];
                //Scambio pixel con opposto
                Map[j][i]=Map[j][imageW-i-1];
                //Inserisco pixel ausiliario
                Map[j][imageW-i-1]=*Aux;
            }
    image->editPMap(Map);
}

void Mirror::verticalMirroring(Bmp8bpp* image){
    //Prendo l'altezza della mappa in pixel
    int imageH = image->getHeight();

    //Prendo la larghezza della mappa in pixel
    int imageW = image->getWidth();

    //Metto un puntatore all'inizio della mappa di byte dell'immagine
    unsigned char** Map = image->getMap();

    //Pixel ausiliario
    unsigned char *Aux=new unsigned char;

    //Scorro solo metà delle righe; scorrerle tutte annullerebbe l'effetto
    for(int j=0; j<(imageH/2); j++)
        for(int i=0; i<imageW; i++){
                //Carico pixel ausiliario
                *Aux=Map[j][i];
                //Scambio pixel con opposto
                Map[j][i]=Map[imageH-j-1][i];
                //Inserisco pixel ausiliario
                Map[imageH-j-1][i]=*Aux;
            }
    image->editPMap(Map);
}

void Mirror::diagonalMirroring(Bmp8bpp *image){
    //Prendo l'altezza della mappa in pixel
    int imageH = image->getHeight();

    //Prendo la larghezza della mappa in pixel
    int imageW = image->getWidth();

    //Metto un puntatore all'inizio della mappa di byte dell'immagine
    unsigned char** Map = image->getMap();

    //Pixel ausiliario
    unsigned char *Aux=new unsigned char;

    //Scorro solo metà delle righe; scorrere metà delle colonne non cambia il risultato
    for(int j=0; j<imageH; j++)
        for(int i=0; i<(imageW/2); i++){
                //Carico pixel ausiliario
                *Aux=Map[j][i];
                //Scambio pixel con opposto
                Map[j][i]=Map[imageH-j-1][imageW-i-1];
                //Inserisco pixel ausiliario
                Map[imageH-j-1][imageW-i-1]=*Aux;
            }
    image->editPMap(Map);
}
