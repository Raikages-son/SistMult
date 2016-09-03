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
    fread(&bit_X_pixel,sizeof(short),1, file);
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
    Bitmap = new unsigned char[getBytesPerRow()*height];

    fread(Bitmap,sizeof(char), getBytesPerRow()*height, file);
    fclose(file);
}

void BmpImage::save(const char *Path){
    cout << " scrivo su: "<< Path << endl;
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

    fwrite(Bitmap,sizeof(char), getBytesPerRow()*height, outFile);
    fclose(outFile);

}

// é sono un abbozzo!
void BmpImage::mirror(){
    unsigned char Temp[getBytesPerRow()*height];
    for(int j =0; j < height; j++){
        for(int i = 0; i < getBytesPerRow(); i++){
            Temp[j*getBytesPerRow() + i] = Bitmap[j*getBytesPerRow() + (getBytesPerRow()-i)];
        }
    }
    Bitmap = Temp;
}

// funzione che calcola il numero di byte per riga, considerando anche quelli di padding
int BmpImage::getBytesPerRow(){
    int byteWidth = width*(bit_X_pixel/8);

    int extraBytes = 0;
    for (;(byteWidth+extraBytes)%4 != 0; extraBytes++);

    return byteWidth + extraBytes;
}

