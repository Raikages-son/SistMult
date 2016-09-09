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


// COSTRUTTORE PER CONVERSIONE(solo scala di grigi)
// header costruito di copia dall'immagine di partenza
Bmp8bpp::Bmp8bpp(const BmpImage &header, unsigned char **NewMap):BmpImage(header){
    // costruisco una palette monocromatica
    unsigned char*Palet =  new unsigned char[1024];
    // inizializzo le entryes della palette con i numeri da 0 a 255 per tutti i colori
    for(int i =0; i<256; i++){
        Palet[i*4] = i;
        Palet[i*4 +1] = i;
        Palet[i*4 +2] = i;
        // byte riservato
        Palet[i*4 +3] = 0;
    }
    // l'offset dell' immagine va impostato a 1078
    offBytes = 1078;
    // i bpp devono essere cambiati a 8
    bpp = 8;
    // calcolo i byte reali per riga
    int bpr = width*bpp+getPadding();
    // aggiorno la dimenzione del file
    fileSize = offBytes + height*bpr;
    // aggiorno la dimensione della mappa dei pixels
    imageSize = fileSize - offBytes;

    // imposto la palette monocromatica
    changePalette(Palet);
    // imposto la nuova mappa
    editPMap(NewMap);

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
