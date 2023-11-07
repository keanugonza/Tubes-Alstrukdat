#ifndef utas_H
#define utas_H

#include "ADTDasar/wordmachine.h"

/* Definisi Node : */
typedef struct node* Address;
typedef struct node {
    Word word;
    DATETIME datetime;
    Address next;
} Node;

#define WORD(p) (p)->word
#define NEXT(p) (p)->next

typedef Address Utas;

void sambungUtas(int idUtas, int idx);

void hapusUtas(int idUtas, int idx);

void cetakUtas(Utas *u);

void panjangUtas(Utas u);

#endif