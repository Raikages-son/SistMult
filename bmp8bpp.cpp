#include "bmp8bpp.h"

Bmp8bpp::Bmp8bpp(const char *Path): BmpImage(Path){

    FILE *file;
    // apertura del file e controllo esistenza
    if ((file=fopen(Path,"rb"))==NULL ){
        exit(1);
    }

    fseek(file,offBytes,0);

    char paddingByte;

    PixelMap = new unsigned char*[height];
    for(int j=0; j<height; j++){
        PixelMap[j] = new unsigned char[width];
        for(int i=0; i<width; i++){
            fread(&PixelMap[j][i],sizeof(char),1,file);
        }
        fread(&paddingByte,sizeof(char),getPadding(),file);
       // fseek(file,getPadding(),SEEK_CUR);
    }
    fclose(file);
}

void Bmp8bpp::save(const char *Path){
    BmpImage::save(Path);
    FILE *file = fopen(Path, "ab");
    if(file == NULL) {
        cout << "Can't create file" << endl;
        exit(1);
    }

    // byte di padding
    char paddingByte = 0;

    for(int j=0; j<height; j++){
        for(int i=0; i<width; i++){
            fwrite(&PixelMap[j][i],sizeof(char),1,file);
        }
        fwrite(&paddingByte,sizeof(char),getPadding(),file);
    }
    fclose(file);
}
