#include <math.h>
#include "imageresizer.h"

ImageResizer::ImageResizer(){

}

void ImageResizer::resize(BmpImage *image, const int &newWidth, const int &newHeight) {
    Bmp24bpp* image24Bpp= dynamic_cast < Bmp24bpp* > ( image );
    Bmp8bpp* image8Bpp=dynamic_cast < Bmp8bpp* > ( image );
    if(image24Bpp!= NULL){
        resize(image24Bpp,newWidth,newHeight);
    }else{
        if(image8Bpp!= NULL){
            resize(image8Bpp,newWidth,newHeight);
        }else{
            cout<<"unsupported image type";
            exit(0);
        }

    }
}

void ImageResizer::resize(Bmp24bpp* image,const int& newWidth ,const int& newHeight){
if(newWidth <=0 || newHeight<=0){
    cout << "New sizes must be greater than zero" << endl;
}
else{
    // Mappa originale
    unsigned char***Src = image->getMap();

    double prevW = image->getWidth();
    double prevH = image->getHeight();

    // fattore < 1 significa allargamento
    double factorW = prevW/newWidth;
    double factorH = prevH/newHeight;

    unsigned char*** Temp = new unsigned char **[newHeight];
    for(int j=0; j<newHeight;j++){
        Temp[j] = new unsigned char*[newWidth];
        int up = floor(j*factorH);
        int down = ceil((j+1)*factorH);
      //  cout << "UP " << up << " Down " <<down<<endl;
        for(int i=0; i< newWidth ;i++){
            Temp[j][i] = new unsigned char[3];
            int sx = floor(i*factorW);
            int dx = ceil((i+1)*factorW);
         //   cout << "DX " << dx << " SX " <<sx << endl;

            for(int p=0; p<3; p++){
                int num = 0;
                int sum =0;
                for(int y=up; y<down; y++){
                    for(int x=sx; x<dx; x++){
                        num++;
                        sum += Src[y][x][p];
                    }
                }
                sum = sum/num;

                Temp[j][i][p]=sum;
            }
        }
    }

    image->resize(newWidth,newHeight);

    image->editPMap(Temp);
}
}

void ImageResizer::resize(Bmp8bpp* image,const int& newWidth ,const int& newHeight){
if(newWidth <=0 || newHeight<=0){
cout << "New sizes must be greater than zero" << endl;
}
else{
    // Mappa originale
    unsigned char**Src = image->getMap();

    double prevW = image->getWidth();
    double prevH = image->getHeight();

    // fattore < 1 significa allargamento
    double factorW = prevW/newWidth;
    double factorH = prevH/newHeight;

    unsigned char** Temp = new unsigned char *[newHeight];
    for(int j=0; j<newHeight;j++){
        Temp[j] = new unsigned char[newWidth];
        int up = floor(j*factorH);
        int down = ceil((j+1)*factorH);
        for(int i=0; i< newWidth ;i++){
            int sx = floor(i*factorW);
            int dx = ceil((i+1)*factorW);

            int num = 0;
            int sum =0;
            for(int y=up; y<down; y++){
                for(int x=sx; x<dx; x++){
                    num++;
                    sum += Src[y][x];
                }
            }
            sum = sum/num;

            Temp[j][i]=sum;
        }
    }

    image->resize(newWidth,newHeight);

    image->editPMap(Temp);
}
}
