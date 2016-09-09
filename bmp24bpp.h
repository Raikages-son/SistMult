#ifndef BMP24BPP_H
#define BMP24BPP_H

#include "bmpimage.h"
#include "bmp8bpp.h"

class Bmp24bpp : public BmpImage{
private:
    unsigned char*** PixelMap;
public:
    Bmp24bpp(const char *Path);

    void save(const char *Path);

    unsigned char *** getMap(){return PixelMap;}

    void editPMap(unsigned char*** map){PixelMap=map;}

    Bmp8bpp* to8bpp();
    /*BmpImage* convert(){

        unsigned char** newmap;
        unsigned char*** map=this->getMap();

        //DESATURARE, FATTO CIRCA e forse in modo un po' furbo
        float gray;
        for(int j=0; j<this->getHeight(); j++)
            for(int i=0; i<this->getWidth(); i++){
                //Formula furba per desaturazione
                gray=(map[j][i][0]*0.11)+(map[j][i][1]*0.59)+(map[j][i][2]*0.3);
                //Non ci serve che tutti i toni siano a grigio, tanto map poi va scartata
                map[j][i][0]=gray;
            }

        //RIEMPIO LA MAPPA A 8 BIT
        for(int j=0; j<this->getHeight(); j++)
            for(int i=0; i<this->getWidth(); i++){
                newmap[j][i]=map[j][i][0];
            }

        //COSTRUISCO OGGETTO A 8 BIT (con costruttore che andrà fatto) E MODIFICO L'HEADER (con funzione che va fatta)
        Bmp8bpp* converted=new Bmp8bpp();
        converted->convertHeader();

        //??SISTEMARE PALETTE??

        return converted;
    }*/

};

#endif // BMP24BPP_H
