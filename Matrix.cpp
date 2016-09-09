//
// Created by biggeb4 on 05/09/16.
//

#include "Matrix.h"

Matrix::Matrix() {}

/*  Edge detection 1. Esempio matrice di raggio 2
 *
 * -1  0  0  0  1
 *  0 -1  0  1  0
 *  0  0  0  0  0
 *  0  1  0 -1  0
 *  1  0  0  0 -1
*/
int** Matrix::getEdgeDetection1(int range) {
    // controllo il raggio
    if(range < 1){
        cout << "matrix range must be greater than zero";
    }
    // calcolo la dimensione
    int size=range*2+1;
    // inizializzazione matrice
    int** matrix=new int*[size];
    // scorro le righe
    for(int j=0; j<size;j++){
        // inizializzo le righe
        matrix[j]=new int[size];
        // scorro le colonne
        for(int i=0; i<size; i++){
            // inizializzo l'intera riga a 0
            matrix[j][i] = 0;
        }
        // imposto a -1 l'elemento sulla diagonale
        matrix[j][j] = -1;
        // imposto a 1 l'elemento simmetricamente opposto
        matrix[j][range*2 -j]= 1;
    }
    // imposto il centro della matrice a 0
    matrix[range][range] = 0;
    // ritorno la matrice
    return matrix;
}

/*  Edge detection 2. Esempio matrice di raggio 2
 *
 *  0  0 -1  0  0
 *  0  0 -1  0  0
 * -1 -1  8 -1 -1
 *  0  0 -1  0  0
 *  0  0 -1  0  0
*/
int** Matrix::getEdgeDetection2(int range) {
    // controllo il raggio
    if(range < 1){
        cout << "matrix range must be greater than zero";
    }
    // calcolo la dimensione
    int size=range*2+1;
    // inizializzazione matrice
    int** matrix=new int*[size];
    // scorro le righe
    for(int j=0; j<size;j++){
        // inizializzo le righe
        matrix[j]=new int[size];
        // se la riga corrente non è la riga di mezzo
        if(j!=range){
            // imposto l'intera riga a 0
            for(int i=0; i<size;i++){
                matrix[j][i] = 0;
            }
            // imposto a -1 l'elemento centrale
            matrix[j][range]= -1;
        }
        // se la riga corrente è la riga di mezzo
        else{
            // imposto l'intera riga a -1
            for(int i=0; i<size;i++){
                matrix[j][i] = -1;
            }
            // imposto l'elemento centrale opposto alla somma degli elementi negativi
            matrix[j][range] = 4*range;
        }
    }
    // ritorno la matrice
    return matrix;
}


/*  Edge detection 3. Esempio matrice di raggio 2
 *
 *  -1 -1 -1 -1 -1
 *  -1 -1 -1 -1 -1
 *  -1 -1 26 -1 -1
 *  -1 -1 -1 -1 -1
 *  -1 -1 -1 -1 -1
*/

int** Matrix::getEdgeDetection3(int range) {
    // controllo il raggio
    if(range < 1){
        cout << "matrix range must be greater than zero";
    }
    // calcolo la dimensione
    int size=range*2+1;
    // inizializzazione matrice
    int** matrix=new int*[size];
    // scorro le righe
    for(int j=0; j<size;j++){
        // inizializzo le righe
        matrix[j]=new int[size];
        // imposto l'intera riga a -1
        for(int i=0; i<size;i++){
            matrix[j][i] = -1;
        }
    }
    // imposto l'elemento centrale opposto alla somma degli elementi negativi più uno
    matrix[range][range]=size*size-1;
    // ritorno la matrice
    return matrix;
}


/*  Blur 1. Esempio matrice di raggio 2
 *
 *  1  1  1  1  1
 *  1  1  1  1  1
 *  1  1  1  1  1
 *  1  1  1  1  1
 *  1  1  1  1  1
*/
int** Matrix::getBlur1(int range) {
    // controllo il raggio
    if(range < 1){
        cout << "matrix range must be greater than zero";
    }
    // calcolo la dimensione
    int size=range*2+1;
    // inizializzazione matrice
    int** matrix=new int*[size];
    // scorro le righe
    for(int j=0; j<size;j++){
        // inizializzo le righe
        matrix[j]=new int[size];
        // imposto l'intera riga a 1
        for(int i=0; i<size;i++){
            matrix[j][i] = 1;
        }
    }
    // ritorno la matrice
    return matrix;
}

/*  Blur 2. Esempio matrice di raggio 2
 *
 *  1  1  1  1  1
 *  1  0  0  0  1
 *  1  0  0  0  1
 *  1  0  0  0  1
 *  1  1  1  1  1
*/
int** Matrix::getBlur2(int range) {
    // controllo il raggio
    if(range < 1){
        cout << "matrix range must be greater than zero";
    }
    // calcolo la dimensione
    int size=range*2+1;
    // esponente
    int centerExp = range*2;
    // inizializzazione matrice
    int** matrix=new int*[size];
    // scorro le righe
    for(int j=0; j<size;j++){
        // inizializzo le righe
        matrix[j]=new int[size];
        // scorro le colonne
        for(int i=0; i<size;i++){
          // se è la prima o l'ultima riga imposto tutti gli elementi a uno
          if(j == 0 || j == size-1){
              matrix[j][i]=1;
          }
          // altrimenti
          else{
            // inizializzo tutta la riga a 0
            matrix[j][i]=0;
            // inizializzo il primo e l'ultimo elemento a 1
            matrix[j][0]=1;
            matrix[j][size-1] = 1;
          }
        }

    }

    // ritorno la matrice
    return matrix;
}




/*  Sharp 1. Esempio matrice di raggio 1
 *
 *  0 -1  0
 * -1  5 -1
 *  0 -1  0
*/

int** Matrix::getSharp1(int range) {
    // controllo il raggio
    if(range < 1){
        cout << "matrix range must be greater than zero";
    }
    // calcolo la dimensione
    int size=range*2+1;
    // inizializzazione matrice
    int** matrix=new int*[size];
    // scorro le righe
    for(int j=0; j<size;j++){
        // inizializzo le righe
        matrix[j]=new int[size];
        // se la riga non è quella di mezzo
        if(j != range){
            // inizializzo tutti gli elementi a 0
            for(int i=0; i<size;i++){
                matrix[j][i] = 0;
            }
            // imposto a -1 l'elemento centrale
            matrix[j][range] = -1;
        }
        // se la riga è quella centrale
        else{
            // inizializzo tutti gli elementi a -1
            for(int i=0; i<size;i++){
                matrix[j][i] = -1;
            }
        }
    }
    // l'elemento centrale è opposto alla somma degli elementi e maggiorato di 1
    matrix[range][range] = 4*range+1;
    //ritorno la matrice
    return matrix;
}


/*  Edge detection 2. Esempio matrice di raggio 2
 *
 * -1 -1 -1
 * -1  9 -1
 * -1 -1 -1
*/

int** Matrix::getSharp2(int range) {
    // controllo il raggio
    if(range < 1){
        cout << "matrix range must be greater than zero";
    }
    // calcolo la dimensione
    int size=range*2+1;
    // inizializzazione matrice
    int** matrix=new int*[size];
    // scorro le righe
    for(int j=0; j<size;j++){
        // inizializzo le righe
        matrix[j]=new int[size];
        // inizializzo tutti gli elementi a -1
        for(int i=0; i<size;i++){
            matrix[j][i] = -1;
        }
    }
    // l'elemento centrale è opposto alla somma degli elementi e maggiorato di 1
    matrix[range][range] = size*size;
    // ritorno la matrice
    return matrix;
}

