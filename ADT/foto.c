#include <stdio.h>
#include "foto.h"

void createMatrixColor(Matrix *M)
{
    Word formatcolor;
    formatcolor.TabWord[0] = 'R';
    formatcolor.Length = 1;
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            ELMT_FT(*M, i, j) = formatcolor;
        }
    }
}

void createMatrixSimbol(Matrix *M)
{
    Word formatsimbol;
    formatsimbol.TabWord[0] = '*';
    formatsimbol.Length = 1;
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            ELMT_FT(*M, i, j) = formatsimbol;
        }
    }
}

void displayMatrix(Matrix m){
    int i, j;
    for (i = 0; i < 5; i++){
        for (j = 0; j < 5; j++){
            if (j == (5 - 1)){
                if (i == (5 - 1)){ /* Element pojok kanan bawah */
                    printf("%d\n", ELMT_FT(m, i, j)); 
                } else { /* Element pinggir kanan*/
                    printf("%d\n", ELMT_FT(m, i, j)); 
                }
            } else { /* Element selain pinggir kanan*/
                printf("%d ", ELMT_FT(m, i, j)); 
            }
        }
    }
}
