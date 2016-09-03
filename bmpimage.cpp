#include "bmpimage.h"

BmpImage::BmpImage(){

}

BmpImage::BmpImage(const char *Path){
    FILE *file;
    // apertura del file e controllo esistenza
    if ( (file=fopen(Path,"rb"))==NULL ){
        cout << "File not found" << endl;
        exit(1);
    }

    // input delle parti degli header
    for(int i = 0; i<14; i++){
        fread(&FILE_HEADER[i],1,sizeof(char),file);
    }
    for(int i = 0; i<40; i++){
        fread(&INFO_HEADER[i],1,sizeof(char),file);
    }
    for(int i = 0; i<1024; i++){
        fread(&PALETTE[i],1,sizeof(char),file);
    }


    // input dei dati del fileheader
    fseek(file,0,0);
    fread(&type,1,sizeof(short), file);
    fread(&fileSize, 1, sizeof(int), file);

    fseek(file,10,0);
    fread(&offBytes, 1, sizeof(int), file);


    // input dei dati dell'infoheader

    fread(&infoSize,1,sizeof(int),file);
    fread(&width, 1, sizeof(int), file);
    fread(&height, 1, sizeof(int), file);
    fread(&planes,1, sizeof(short), file);
    fread(&bit_X_pixel,1, sizeof(short), file);
    fread(&compression,1, sizeof(int), file);
    fread(&imageSize,1, sizeof(int), file);

    cout << "Map's offset: "<< offBytes << endl;
    cout << "Width is: "<< width << endl;
    cout << "Height is: "<< height << endl;

    cout << "Using : "<< bit_X_pixel << " bit to encode a pixel" << endl;

    // larghezza in byte
    int byteWidth = width*(bit_X_pixel/8);

    int extraBytes = 0;
    for (;(byteWidth+extraBytes)%4 != 0; extraBytes++);

    cout << "Width in bytes: "<< byteWidth << endl;
    cout << "Extra Bytes in a row: "<< extraBytes <<endl;

    // lettura pixels

    unsigned char map[(byteWidth+extraBytes)*height];

    for (int i=0; i<height; i++ ) {
        unsigned char* data = new unsigned char[byteWidth+extraBytes];
        fread( data, sizeof(unsigned char), byteWidth+extraBytes, file);

        // ATTENZIONE CHE I PIXELS SONO CODIFICATI IN BGR E NON RGB;
    }

    fclose(file); //chiusura del file
}

void BmpImage::save(const char *Path){
    FILE *file = fopen(Path, "wb");
    if(file == NULL) {
        cout << "Can't create file" << endl;
        exit(1);
    }

    // stampo l'header
    fwrite(FILE_HEADER, 14, 1, file);
    fwrite(INFO_HEADER, 40, 1, file);
    fwrite(PALETTE, 1024, 1,file);


    int byteWidth = width*(bit_X_pixel/8);

    int extraBytes = 0;
    for (;(byteWidth+extraBytes)%4 != 0; extraBytes++);

    byteWidth += extraBytes;

    int totalBytes = byteWidth*height;

    // stampo la mappa
    fwrite(bitmap,totalBytes,1,file);

    fclose(file);

}

