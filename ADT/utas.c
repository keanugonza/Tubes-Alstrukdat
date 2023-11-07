#ifndef utas_H
#define utas_H

#include "ADTDasar/wordmachine.h"

/* Definisi Node : */
typedef struct node* Address;
typedef struct node {
    Word info;
    Address next;
} Node;

typedef Address Utas;

void createUtas(Utas *u);

void sambungUtas(int idUtas, int idx);

void hapusUtas(int idUtas, int idx);

void cetakUtas(Utas *u);

#endif