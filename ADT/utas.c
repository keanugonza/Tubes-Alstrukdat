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

void panjangUtas(Utas u){
    Address p;
    int counter;
    if (isEmpty(u)){
        return 0;
    }else{
        p = FIRST(u);
        counter = 0;
        while (NEXT(p) != NULL){
            counter +=1;
            p = NEXT(p);
        }
        return counter;
    }
}

