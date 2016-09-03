#include "bmpimage.h"

BmpImage::BmpImage(){

}

BmpImage::BmpImage(const char *Path){
    FILE *file;
    if ( (file=fopen(Path,"rb"))==NULL ){
         //printf("File non trovato!!");
        cout << "File not found" << endl;
        exit(1);
    }

    fread(&type,1,sizeof(short), file);
    fread(&fileSize, 1, sizeof(int), file);

    fseek(file,10,0);
    fread(&offBytes, 1, sizeof(int), file);


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

    unsigned char map[width][height];


}

