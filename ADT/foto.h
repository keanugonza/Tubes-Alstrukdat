#ifndef FOTO_H
#define FOTO_H
#include "boolean.h"
#include "wordmachine.h"
#include "charmachine.h"

#define ROW_CAP 5
#define COL_CAP 5

typedef int IdxType; /* Index baris, kolom */
typedef Word ElType;
typedef struct
{
   ElType mem[ROW_CAP][COL_CAP];
} Matrix;

#define ELMT_FT(M, i, j) (M).mem[(i)][(j)]

void createMatrixColor(Matrix *M);

void createMatrixSimbol(Matrix *M);

void displayMatrix(Matrix m);
#endif