//
// Created by biggeb4 on 08/09/16.
//

#include "bpmFactory.h"
#include "bmp8bpp.h"
#include "bmp24bpp.h"

bpmFactory::bpmFactory() {}
BmpImage* bpmFactory::buildImg(const char *Path) {
    FILE *file;
    // apertura del file e controllo esistenza
    if ((file=fopen(Path,"rb"))==NULL ){
        cout << "File not found" << endl;
        exit(1);
    }
    short bpp;
    fseek(file,28,0);
    fread(&bpp,sizeof(short),1, file);
    switch (bpp){
        case 8:{
            return new Bmp8bpp(Path);
        }
        case 24:{
            return new Bmp24bpp(Path);
        }
        default: {
            cout << bpp << " bpp format unsupported ";
            exit(1);
        }
    }
}
