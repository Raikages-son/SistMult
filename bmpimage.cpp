#include "bmpimage.h"

BmpImage::BmpImage(){

}

BmpImage::BmpImage(const char *Path){
    FILE *file;
    // apertura del file e controllo esistenza
    if ((file=fopen(Path,"rb"))==NULL ){
        cout << "File not found" << endl;
        exit(1);
    }

    // input dei dati del fileheader
    fseek(file,0,0);
    fread(&type,sizeof(short),1, file);
    fread(&fileSize,sizeof(int),1, file);

    fseek(file,10,0);
    fread(&offBytes,sizeof(int),1, file);


    // input dei dati dell'infoheader

    fread(&infoSize,sizeof(int),1,file);
    fread(&width,sizeof(int),1, file);
    fread(&height,sizeof(int),1, file);
    fread(&planes,sizeof(short),1, file);
    fread(&bpp,sizeof(short),1, file);
    fread(&compression,sizeof(int),1, file);
    fread(&imageSize,sizeof(int),1, file);

    // input delle parti degli header
    fseek(file,0,0);

    fread(FILE_HEADER,sizeof(char),14,file);

    fread(INFO_HEADER,sizeof(char),40,file);

    PALETTE = new unsigned char[offBytes-54];

    fread(PALETTE,sizeof(char),(offBytes-54),file);

    // input della mappa dei pixel

    fseek(file,offBytes,0);
    // do la dimensione alla mappa
    Bitmap = new unsigned char[(width*bpp + getPadding())*height];

    fread(Bitmap,sizeof(char), (width*bpp + getPadding())*height, file);
    fclose(file);
}

void BmpImage::save(const char *Path){
    FILE *outFile = fopen(Path, "wb");
    if(outFile == NULL) {
        cout << "Can't create file" << endl;
        exit(1);
    }

    // stampo l'header
    fwrite(FILE_HEADER, sizeof(char), 14 , outFile);
    fwrite(INFO_HEADER, sizeof(char), 40, outFile);
    fwrite(PALETTE, sizeof(char), offBytes-54,outFile);


    // stampo la mappa

    fwrite(Bitmap,sizeof(char), (width*bpp + getPadding())*height, outFile);
    fclose(outFile);

}

// funzione che calcola il numero di byte di padding
int BmpImage::getPadding(){
    int byteWidth = width*(bpp/8);

    int extraBytes = 0;
    for (;(byteWidth+extraBytes)%4 != 0; extraBytes++);

    return extraBytes;
}

