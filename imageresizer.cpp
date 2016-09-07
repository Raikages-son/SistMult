#include <math.h>
#include "imageresizer.h"

ImageResizer::ImageResizer(){

}

void ImageResizer::resize(Bmp24bpp* image,const int& newWidth ,const int& newHeight){
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
