#include "convolutionmatrix.h"

ConvolutionMatrix::ConvolutionMatrix(){

}

void ConvolutionMatrix::applyMask(Bmp24bpp image,int** Matrix, int range){
    // prendo l'altezza della mappa in pixel
    int imageH = image.getHeight();
    // prendo la larghezza della mappa in pixel
    int imageW = image.getWidth();
    // prendo il numero di byte di padding per riga
    int paddingBytes = image.getPadding();
    // metto un puntatore all'inizio della mappa di byte dell'immagine
    unsigned char*** Map = image.getMap();
    // dimenzione della matrice di convoluzione
    int mSize = range*2 +1;
    // somma dei coefficenti della matrice di convoluzione
    int cSum =0;
    for(int a=0; a<mSize; a++){
        for(int b=0; b<mSize; b++){
            cSum += Matrix[a][b];
        }
    }
    // array nel quale salvare la bitmap filtrata;
    unsigned char*** Temp = new unsigned char **[imageH];
    for(int j=0; j<imageH;j++){
        Temp[j] = new unsigned char*[imageW];
        for(int i=0; i< imageW ;i++){
            Temp[j][i] = new unsigned char[3];
            for(int p=0; p<3; p++){
                int sum = 0;
                for(int a=-range; a<=range; a++){
                    for(int b=-range; b<=range; b++){
                        if(j+a < 0 || i+b <0 || j+a>=imageH || i+b >= imageW){
                            sum += Matrix[range+a][range+b]*Map[j][i][p];
                        }
                        else{
                            sum += Matrix[range+a][range+b]*Map[j+a][i+b][p];
                        }
                    }
                }
                if(cSum != 0){
                    sum = sum/cSum;
                }
                if(sum > 255){
                    sum = 255;
                }
                if(sum < 0){
                    sum = 0;
                }
                Temp[j][i][p] = sum;
            }
        }
    }

    for(int j=0; j<imageH;j++)
        for(int i=0; i< imageW ;i++)
            for(int p=0; p<3; p++)
                Map[j][i][p] = Temp[j][i][p];


}
