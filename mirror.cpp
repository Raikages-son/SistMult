#include "mirror.h"

Mirror::Mirror(){

}

void Mirror::horizontalMirroring(Bmp24bpp image){
    // prendo l'altezza della mappa in pixel
    int imageH = image.getHeight();
    // prendo la larghezza della mappa in pixel
    int imageW = image.getWidth();
    /* INUTILIZZATO prendo il numero di byte di padding per riga
    int paddingBytes = image.getPadding();*/
    // prendo il numero di bit che codificano per un pixel
    int bpp = image.getBPP();
    /* ORA INUTILE prendo il numero totale di bytes in una riga
    int bpr = imageW*bpp/8 + paddingBytes;*/
    // metto un puntatore all'inizio della mappa di byte dell'immagine
    unsigned char*** Map = image.getMap();

    // scelgo l'algoritmo giusto in base ai bpp dell'immagine
    if (bpp == 2){
        cout << "Mirroring not supported yet for 2 bpp bitmaps" << endl;
    }
    else if (bpp == 4){
        cout << "Mirroring not supported yet for 4 bpp bitmaps" << endl;
    }
    else if (bpp == 8){
        /*unsigned char auxPixel;

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
        }*/
        cout << "Mirroring not supported yet for 8 bpp bitmaps" << endl;
    }
    else if (bpp == 16){
        cout << "Mirroring not supported yet for 16 bpp bitmaps" << endl;
    }
    else if (bpp == 24){
        //Remake by Diego

        //Pixel ausiliario
        unsigned char *Aux=new unsigned char[3];

        //Scorro solo metà delle colonne
        for(int j=0; j<imageH; j++)
            for(int i=0; i<(imageW/2); i++)
                for(int b=0; b<3; b++)
                {
                    //Carico pixel ausiliario
                    Aux[b]=Map[j][i][b];
                    //Scambio pixel con opposto
                    Map[j][i][b]=Map[j][imageW-i-1][b];
                    //Inserisco pixel ausiliario
                    Map[j][imageW-i-1][b]=Aux[b];
                }
        image.editPMap(Map);

        /*// array che rappresenta un pixel ausiliario
        unsigned char *AuxPixel= new unsigned char[3];
        cout<<"inizio"<<endl;
        // calcolo la metà per difetto
        int half;
        if((bpr-paddingBytes)%2 == 0){
            half = (bpr - paddingBytes)/2;
        }
        else{
            half = (bpr - paddingBytes -1)/2;
        }
    cout<<"fatta metà"<<endl;
        // scorro le righe della mappa
        for(int j = 0; j<imageH; j++){
            //int lastPixel = (j+1)*bpr - paddingBytes - 3;
            // scorro i pixel della riga fino a metà
            for(int i = 0; i<=half; i++){
                // per le 3 componenti BGR (sono al contrario)
                for(int t = 0; t<3; t++){
                    // salvo il pixel nell'array ausiliario
                    cout<<"Problema qui?"<<endl;
                    AuxPixel[t] = Map[j][i][t];
                    // imposto il pixel uguale al pixel simmetricamente opposto
                    Map[j*imageW*3+i*3+t] = Map[(imageH-j)*imageW*3+i*3+t];
                    // imposto il pixel simmetricamente opposto con l'array ausiliario
                    Map[imageH-j][i][t] = AuxPixel[t];
                }
            }
        }*/
    }
}

void Mirror::verticalMirroring(Bmp24bpp image){

    // prendo l'altezza della mappa in pixel
    int imageH = image.getHeight();

    // prendo la larghezza della mappa in pixel
    int imageW = image.getWidth();

    // prendo il numero di bit che codificano per un pixel
    int bpp = image.getBPP();

    // metto un puntatore all'inizio della mappa di byte dell'immagine
    unsigned char*** Map = image.getMap();

    // scelgo l'algoritmo giusto in base ai bpp dell'immagine
    if (bpp == 2){
        cout << "Mirroring not supported yet for 2 bpp bitmaps" << endl;
    }
    else if (bpp == 4){
        cout << "Mirroring not supported yet for 4 bpp bitmaps" << endl;
    }
    else if (bpp == 8){
        cout << "Mirroring not supported yet for 8 bpp bitmaps" << endl;
    }
    else if (bpp == 16){
        cout << "Mirroring not supported yet for 16 bpp bitmaps" << endl;
    }
    else if (bpp == 24){
        //Pixel ausiliario
        unsigned char *Aux=new unsigned char[3];

        //Scorro solo metà delle righe
        for(int j=0; j<(imageH/2); j++)
            for(int i=0; i<imageW; i++)
                for(int b=0; b<3; b++)
                {
                    //Carico pixel ausiliario
                    Aux[b]=Map[j][i][b];
                    //Scambio pixel con opposto
                    Map[j][i][b]=Map[imageH-j-1][i][b];
                    //Inserisco pixel ausiliario
                    Map[imageH-j-1][i][b]=Aux[b];
                }
        image.editPMap(Map);
    }
}

void Mirror::diagonalMirroring(Bmp24bpp image){

    // prendo l'altezza della mappa in pixel
    int imageH = image.getHeight();

    // prendo la larghezza della mappa in pixel
    int imageW = image.getWidth();

    // prendo il numero di bit che codificano per un pixel
    int bpp = image.getBPP();

    // metto un puntatore all'inizio della mappa di byte dell'immagine
    unsigned char*** Map = image.getMap();

    // scelgo l'algoritmo giusto in base ai bpp dell'immagine
    if (bpp == 2){
        cout << "Mirroring not supported yet for 2 bpp bitmaps" << endl;
    }
    else if (bpp == 4){
        cout << "Mirroring not supported yet for 4 bpp bitmaps" << endl;
    }
    else if (bpp == 8){
        cout << "Mirroring not supported yet for 8 bpp bitmaps" << endl;
    }
    else if (bpp == 16){
        cout << "Mirroring not supported yet for 16 bpp bitmaps" << endl;
    }
    else if (bpp == 24){
        //Pixel ausiliario
        unsigned char *Aux=new unsigned char[3];

        //Scorro solo metà delle righe
        for(int j=0; j<imageH; j++)
            for(int i=0; i<(imageW/2); i++)
                for(int b=0; b<3; b++)
                {
                    //Carico pixel ausiliario
                    Aux[b]=Map[j][i][b];
                    //Scambio pixel con opposto
                    Map[j][i][b]=Map[imageH-j-1][imageW-i-1][b];
                    //Inserisco pixel ausiliario
                    Map[imageH-j-1][imageW-i-1][b]=Aux[b];
                }
        image.editPMap(Map);
    }
}
