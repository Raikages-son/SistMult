#include "convolutionmatrix.h"

ConvolutionMatrix::ConvolutionMatrix(){

}

void ConvolutionMatrix::apply3x3Mask(BmpImage image, const int *Matrix){
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
    // array ausiliario per il calcolo del nuovo kernel
    int * Aux = new int[9];
    // array dove salvare la bitmap filtrata;
    unsigned char *Temp = new unsigned char[bpr*imageH];

    // scelgo l'algoritmo giusto in base ai bpp dell'immagine
    if (bpp == 2){
        cout << "Masking not supported yet for 2 bpp bitmaps" << endl;
    }
    else if (bpp == 4){
        cout << "Masking not supported yet for 4 bpp bitmaps" << endl;
    }
    else if (bpp == 8){
        cout << "Masking not supported yet for 8 bpp bitmaps" << endl;
    }
    else if (bpp == 16){
        cout << "Masking not supported yet for 16 bpp bitmaps" << endl;
    }
    else if (bpp == 24){
        for(int j=0; j<imageH;j++){
            for(int i=0; i< bpr - paddingBytes ;i++){
                int  Indexes[9] = {(j-1)*bpr+i-3,(j-1)*bpr+i,(j-1)*bpr+i+3,
                                   j*bpr + i-3  , j*bpr+i   , j*bpr+i+3,
                                   (j+1)*bpr+i-3,(j+1)*bpr+i,(j+1)*bpr+i+3
                                  };

                for(int t = 0; t < 9; t++){
                    if(Indexes[t]<0 || Indexes[t]>=imageH*bpr){
                        Aux[t] = Map[Indexes[4]]*Matrix[t];
                    }
                    else{
                        int val = Map[Indexes[t]];
                        Aux[t] = val * Matrix[t];
                    }
                }
                int sum = 0;
                int coeffSum = 0;
                for(int v =0; v<9; v++){
                    sum += Aux[v];
                    coeffSum += Matrix[v];
                }
                if(coeffSum != 0){
                    sum = sum/coeffSum;
                }
                if(sum >255) {sum =255;}
                else if(sum<0) {sum = 0;}
                unsigned char newKernel = sum;
                Temp[j*bpr+i] = newKernel;
            }
        }

        for(int i = 0; i<(imageH*bpr);i++){
            Map[i] = Temp[i];
        }
    }

}
