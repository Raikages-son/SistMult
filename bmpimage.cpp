#include "bmpimage.h"

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
    fread(&reserved,sizeof(int),1,file);
    fread(&offBytes,sizeof(int),1, file);


    // input dei dati dell'infoheader

    fread(&infoSize,sizeof(int),1,file);
    fread(&width,sizeof(int),1, file);
    fread(&height,sizeof(int),1, file);
    fread(&planes,sizeof(short),1, file);
    fread(&bpp,sizeof(short),1, file);
    fread(&compression,sizeof(int),1, file);
    fread(&imageSize,sizeof(int),1, file);
    fread(&xResolution,sizeof(int),1, file);
    fread(&yResolution,sizeof(int),1, file);
    fread(&usedColors,sizeof(int),1, file);
    fread(&importantColors,sizeof(int),1, file);

    // input dell' eventuale palette

    PALETTE = new unsigned char[offBytes-headerSize];

    fread(PALETTE,sizeof(char),(offBytes-headerSize),file);

    // input della mappa dei pixel

    fclose(file);
}

void BmpImage::save(const char *Path){
    FILE *file = fopen(Path, "wb");
    if(file == NULL) {
        cout << "Can't create file" << endl;
        exit(1);
    }

    // output dei dati del fileheader
    fseek(file,0,0);
    fwrite(&type,sizeof(short),1, file);
    fwrite(&fileSize,sizeof(int),1, file);
    fwrite(&reserved,sizeof(int),1,file);
    fwrite(&offBytes,sizeof(int),1, file);


    // output dei dati dell'infoheader

    fwrite(&infoSize,sizeof(int),1,file);
    fwrite(&width,sizeof(int),1, file);
    fwrite(&height,sizeof(int),1, file);
    fwrite(&planes,sizeof(short),1, file);
    fwrite(&bpp,sizeof(short),1, file);
    fwrite(&compression,sizeof(int),1, file);
    fwrite(&imageSize,sizeof(int),1, file);
    fwrite(&xResolution,sizeof(int),1, file);
    fwrite(&yResolution,sizeof(int),1, file);
    fwrite(&usedColors,sizeof(int),1, file);
    fwrite(&importantColors,sizeof(int),1, file);

    // output della palette

    fwrite(PALETTE, sizeof(char), offBytes-headerSize,file);

    fclose(file);

}

// funzione che calcola il numero di byte di padding
int BmpImage::getPadding(){
    int byteWidth = width*(bpp/8);

    int extraBytes = 0;
    for (;(byteWidth+extraBytes)%4 != 0; extraBytes++);

    return extraBytes;
}

void BmpImage::resize(unsigned int newWidth, unsigned int newHeight){
    width = newWidth;
    height = newHeight;
    int bpr = width*bpp+getPadding();
    fileSize = offBytes + height*bpr;
    imageSize = height * bpr;

}



