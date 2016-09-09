#include "bmpimage.h"

BmpImage::BmpImage(const char *Path){
    FILE *file;
    //Apertura del file e controllo esistenza
    if ((file=fopen(Path,"rb"))==NULL ){
        cout << "File not found" << endl;
        exit(1);
    }

    //Input dei dati del fileheader
    fseek(file,0,0);
    fread(&type,sizeof(short),1, file);
    fread(&fileSize,sizeof(int),1, file);
    fread(&reserved,sizeof(int),1,file);
    fread(&offBytes,sizeof(int),1, file);


    //Input dei dati dell'infoheader

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

    //Input dell' eventuale palette

    PALETTE = new unsigned char[offBytes-headerSize];

    fread(PALETTE,sizeof(char),(offBytes-headerSize),file);

    //Input della mappa dei pixel

    fclose(file);
}

void BmpImage::save(const char *Path){
    FILE *file = fopen(Path, "wb");
    if(file == NULL) {
        cout << "Can't create file" << endl;
        exit(1);
    }


    //Output dei dati del fileheader
    fseek(file,0,0);
    fwrite(&type,sizeof(short),1, file);
    fwrite(&fileSize,sizeof(int),1, file);
    fwrite(&reserved,sizeof(int),1,file);
    fwrite(&offBytes,sizeof(int),1, file);


    //Output dei dati dell'infoheader

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

    //Output della palette

    fwrite(PALETTE, sizeof(char), offBytes-headerSize,file);

    fclose(file);

}

//Funzione che calcola il numero di byte di padding
int BmpImage::getPadding(){
    int byteWidth = width*(bpp/8);

    int extraBytes = 0;
    for (;(byteWidth+extraBytes)%4 != 0; extraBytes++);

    return extraBytes;
}

void BmpImage::printInfo(){
    cout << "  ########  FILE HEADER  ########" << endl<<endl;
    cout << "Tipo:                        " << type << endl;
    cout << "Dimensione file:             " << fileSize << endl;
    cout << "Riservato:                   " << reserved << endl;
    cout << "Offset immagine:             " << offBytes << endl<<endl;

    cout << "  ########  INFO HEADER  ########" << endl<<endl;
    cout << "Dimensione info: :           " << infoSize << endl;
    cout << "Larghezza px:                " << width << endl;
    cout << "Altezza px:                  " << height << endl;
    cout << "Piani:                       " << planes << endl;
    cout << "BPP:                         " << bpp << endl;
    cout << "Compressione:                " << compression << endl;
    cout << "Dimensione immagine:         " << imageSize << endl;
    cout << "Risoluzione x:               " << xResolution << endl;
    cout << "Risoluzione y:               " << yResolution << endl;
    cout << "Colori utilizzati:           " << usedColors << endl;
    cout << "Colori principali:           " << importantColors << endl<<endl;
}

//Funzione che corregge i dati di resize nell'header
void BmpImage::resize(const unsigned int& newWidth,const unsigned int& newHeight){
    width = newWidth;
    height = newHeight;
    int bpr = width*bpp+getPadding();
    fileSize = offBytes + height*bpr;
    imageSize = fileSize - offBytes;
}



