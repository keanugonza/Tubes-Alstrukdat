#include <stdio.h>
#include <stdlib.h>
#include "utas.h"

Address newNode(Word w){
    Address p = (Address) malloc(sizeof(Node));
    if(p != NULL){
        WORD(p) = w;
        NEXT(p) = NULL;
    }
    return p;
}

void sambungUtas(int idUtas, int idx);

void hapusUtas(int idUtas, int idx);

void cetakUtas(Utas *u);

void panjangUtas(Utas u);

