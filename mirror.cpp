#include "mirror.h"

Mirror::Mirror(){

}

void Mirror::applyMirroring(BmpImage image){/*
    // prendo l'altezza della mappa in pixel
    int imageH = image.getHeight();
    // prendo la larghezza della mappa in pixel
    int imageW = image.getWidth();
    // prendo il numero di byte di padding per riga
    int paddingBytes = image.getPadding();
    // prendo il numero di bit che codificano per un pixel
    int bpp = image.getBPP();
    // prendo il numero totale di bytes in una riga
    int bpr = imageW*bpp/8 + paddingBytes;
    // metto un puntatore all'inizio della mappa di byte dell'immagine
    unsigned char* Map = image.getMap();

    // scelgo l'algoritmo giusto in base ai bpp dell'immagine
    if (bpp == 2){
        cout << "Mirroring not supported yet for 2 bpp bitmaps" << endl;
    }
    else if (bpp == 4){
        cout << "Mirroring not supported yet for 4 bpp bitmaps" << endl;
    }
    else if (bpp == 8){
        unsigned char auxPixel;

        for(int j = 0; j<imageH; j++){
            int lastPixel = (j+1)*bpr - paddingBytes -1;
            // scorro i pixel della riga fino a metà
            for(int i = 0; i<=(bpr - paddingBytes)/2; i++){
                // salvo il pixel nel byte ausiliario
                auxPixel = Map[j*bpr + i];
                // imposto il pixel uguale al pixel simmetricamente opposto
                Map[j*bpr + i] = Map[lastPixel - i];
                // imposto il pixel simmetricamente opposto con l'array ausiliario
                Map[lastPixel - i] = auxPixel;
            }
        }
    }
    else if (bpp == 16){
        cout << "Mirroring not supported yet for 16 bpp bitmaps" << endl;
    }
    else if (bpp == 24){
        // array che rappresenta un pixel ausiliario
        unsigned char *AuxPixel= new unsigned char[3];
        // calcolo la metà per difetto
        int half;
        if((bpr-paddingBytes)%2 == 0){
            half = (bpr - paddingBytes)/2;
        }
        else{
            half = (bpr - paddingBytes -1)/2;
        }

        // scorro le righe della mappa
        for(int j = 0; j<imageH; j++){
            int lastPixel = (j+1)*bpr - paddingBytes - 3;
            // scorro i pixel della riga fino a metà
            for(int i = 0; i<=half; i+=3){
                // per le 3 componenti BGR (sono al contrario)
                for(int t = 0; t<3; t++){
                    // salvo il pixel nell'array ausiliario
                    AuxPixel[t] = Map[j*bpr + i + t];
                    // imposto il pixel uguale al pixel simmetricamente opposto
                    Map[j*bpr + i + t] = Map[lastPixel - i + t];
                    // imposto il pixel simmetricamente opposto con l'array ausiliario
                    Map[lastPixel - i + t] = AuxPixel[t];
                }
            }
        }*/
    /* // versione che salva tutta la mappa su un array temporaneo
        unsigned char *Temp = new unsigned char[bpr*imageH];
        for(int j =0; j < imageH; j++){
            int lastPixel = (j+1)*bpr - paddingBytes - 3;
            for(int i = 0; i < bpr - paddingBytes; i+=3){
                for(int t = 0; t<3; t++){
                    Temp[j*bpr+i+t] = Map[lastPixel-i+t];
                }
            }
        }
        for(int i = 0; i<(imageH*bpr);i++){
            Map[i] = Temp[i];
        }*/
    //}
}
