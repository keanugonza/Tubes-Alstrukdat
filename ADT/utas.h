#ifndef utas_H
#define utas_H

#include "wordmachine.h"
#include "ADTDasar/datetime.h"

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


#endif