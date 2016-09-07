#include "bmp24bpp.h"

Bmp24bpp::Bmp24bpp(const char *Path): BmpImage(Path){

    PixelMap = new unsigned char**[height];

    FILE *file;
    // apertura del file e controllo esistenza
    if ((file=fopen(Path,"rb"))==NULL ){
        exit(1);
    }

    fseek(file,offBytes,0);

    char paddingByte;

    for(int j=0; j<height; j++){
        PixelMap[j] = new unsigned char *[width];
        for(int i=0; i<width; i++){
            PixelMap[j][i]= new unsigned char[3];
            for(int p=0; p<3; p++){
                fread(&PixelMap[j][i][p],sizeof(char),1,file);
            }
        }
        fread(&paddingByte,sizeof(char),getPadding(),file);
       // fseek(file,getPadding(),SEEK_CUR);
    }
    fclose(file);
    //    M = new unsigned char[width*height*3];
     //   fread(M,sizeof(char),width*height*3,file);

}

void Bmp24bpp::save(const char *Path){
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
            for(int p=0; p<3; p++){
                fwrite(&PixelMap[j][i][p],sizeof(char),1,file);
            }
        }
        fwrite(&paddingByte,sizeof(char),getPadding(),file);
    }
    fclose(file);
}
/*
void Bmp24bpp::resize(unsigned int newWidth, unsigned int newHeight){

    for(int j =0; j<height; j++){
        for(int i =0; i<width; i++){
            delete[] PixelMap[j][i];
        }
        delete[]PixelMap[j];
    }
    delete[] PixelMap;

    BmpImage::resize(newWidth,newHeight);

    PixelMap = new unsigned char **[height];
    for(int j=0; j<height; j++){
        PixelMap[j]=new unsigned char *[width];
        for(int i=0; i< width; i++){
            PixelMap[j][i] = new unsigned char[3];
        }
    }

}*/



