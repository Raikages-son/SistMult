#include "convolutionmatrix.h"

ConvolutionMatrix::ConvolutionMatrix(){

}

//Procedura che richiama la funzione adatta al tipo dell'immagine
void ConvolutionMatrix::applyMask(BmpImage *image, int **Matrix, int range) {
    Bmp24bpp* image24Bpp= dynamic_cast < Bmp24bpp* > ( image );
    Bmp8bpp* image8Bpp=dynamic_cast < Bmp8bpp* > ( image );
    if(image24Bpp!= NULL){
        applyMask(image24Bpp,Matrix,range);
    }else{
        if(image8Bpp!= NULL){
            applyMask(image8Bpp,Matrix,range);
        }else{
            cout<<"unsupported image type";
            exit(0);
        }

    }
}

//Funzione che applica una matrice di convoluzione sull'immagine a 24b caricata
void ConvolutionMatrix::applyMask(Bmp24bpp *image,int** Matrix, int range){
    if(range < 1){
        cout << "Range of convolution matrix must be greater than zero" << endl;
    }
    else{
        //Prendo l'altezza della mappa in pixel
        int imageH = image->getHeight();
        //Prendo la larghezza della mappa in pixel
        int imageW = image->getWidth();
        //Metto un puntatore all'inizio della mappa di byte dell'immagine
        unsigned char*** Map = image->getMap();
        //Dimensione della matrice di convoluzione
        int mSize = range*2 +1;
        //Somma dei coefficenti della matrice di convoluzione
        int cSum =0;
        for(int a=0; a<mSize; a++)
            for(int b=0; b<mSize; b++){
                cSum += Matrix[a][b];
           }
        //Array nel quale salvare la bitmap filtrata;
        unsigned char*** Temp = new unsigned char **[imageH];
        for(int j=0; j<imageH;j++){
            Temp[j] = new unsigned char*[imageW];
            for(int i=0; i< imageW ;i++){
              Temp[j][i] = new unsigned char[3];
              for(int p=0; p<3; p++){
                  int sum = 0;
                  for(int a=-range; a<=range; a++)
                     for(int b=-range; b<=range; b++){
                          if(j+a < 0 || i+b <0 || j+a>=imageH || i+b >= imageW){
                             sum += Matrix[range+a][range+b]*Map[j][i][p];
                         }
                        else{
                            sum += Matrix[range+a][range+b]*Map[j+a][i+b][p];
                        }
                    }
                 if(cSum != 0)
                     sum = sum/cSum;
                 if(sum > 255)
                     sum = 255;
                 if(sum < 0)
                     sum = 0;
                 Temp[j][i][p] = sum;
              }
            }
        }
        image->editPMap(Temp);
    }
}

//Funzione che applica una matrice di convoluzione sull'immagine a 8b caricata
void ConvolutionMatrix::applyMask(Bmp8bpp *image, int **Matrix, int range){
    if(range < 1){
        cout << "Range of convolution matrix must be greater than zero" << endl;
    }
    else{
        //Prendo l'altezza della mappa in pixel
        int imageH = image->getHeight();
        //Prendo la larghezza della mappa in pixel
        int imageW = image->getWidth();
        //Metto un puntatore all'inizio della mappa di byte dell'immagine
        unsigned char** Map = image->getMap();
        //Dimensione della matrice di convoluzione
        int mSize = range*2 +1;
        //Somma dei coefficenti della matrice di convoluzione
        int cSum =0;
        for(int a=0; a<mSize; a++)
            for(int b=0; b<mSize; b++){
                cSum += Matrix[a][b];
            }

        //Array nel quale salvare la bitmap filtrata;
        unsigned char** Temp = new unsigned char *[imageH];
        for(int j=0; j<imageH;j++){
            Temp[j] = new unsigned char[imageW];
            for(int i=0; i< imageW ;i++){
                int sum = 0;
                for(int a=-range; a<=range; a++)
                    for(int b=-range; b<=range; b++){
                        if(j+a < 0 || i+b <0 || j+a>=imageH || i+b >= imageW){
                            sum += Matrix[range+a][range+b]*Map[j][i];
                        }
                        else{
                            sum += Matrix[range+a][range+b]*Map[j+a][i+b];
                        }
                    }
                if(cSum != 0)
                    sum = sum/cSum;
                if(sum > 255)
                    sum = 255;
                if(sum < 0)
                    sum = 0;
                Temp[j][i] = sum;
            }
        }
        image->editPMap(Temp);
    }
}
