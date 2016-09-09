#include "bmp8bpp.h"

Bmp8bpp::Bmp8bpp(const char *Path): BmpImage(Path){

    FILE *file;
    //Apertura del file e controllo esistenza
    if ((file=fopen(Path,"rb"))==NULL ){
        exit(1);
    }

    fseek(file,offBytes,0);

    char paddingByte;
    //Carico la nuova immagine in una mappa bidimensionale
    PixelMap = new unsigned char*[height];
    for(int j=0; j<height; j++){
        PixelMap[j] = new unsigned char[width];
        for(int i=0; i<width; i++){
            fread(&PixelMap[j][i],sizeof(char),1,file);
        }
        fread(&paddingByte,sizeof(char),getPadding(),file);
    }
    fclose(file);
}

void Bmp8bpp::save(const char *Path){
    //Scrivo l'header della nuova immagine
    BmpImage::save(Path);
    //Apro la nuova immagine in modalità append, così da poter scrivere di seguito all'header
    FILE *file = fopen(Path, "ab");
    if(file == NULL) {
        cout << "Can't create file" << endl;
        exit(1);
    }

    //Byte di padding
    char paddingByte = 0;
    //Scrivo la nuova immagine inserendo, se necessario, un byte di padding alla fine della riga
    for(int j=0; j<height; j++){
        for(int i=0; i<width; i++){
            fwrite(&PixelMap[j][i],sizeof(char),1,file);
        }
        fwrite(&paddingByte,sizeof(char),getPadding(),file);
    }
    fclose(file);
}
