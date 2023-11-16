#include <stdio.h>
#include <stdlib.h>
#include "utas.h"

Address newNode(int id, Word author, DATETIME dt, Word isi){
    Address p = (Address) malloc(sizeof(Node));
    if(p != NULL){
        ID(p) = id;
        AUTHOR(p) = author;
        DATETIME(p) = dt;
        ISI(p) = isi;
        NEXT(p) = NULL;
    }
    return p;
}

boolean isEmptyUtas(Utas u){
    return u == NULL;
}

boolean onlyKicauanUtama(Utas u){
    return !isEmptyUtas(u) && NEXT(u) == NULL;
}

int panjangUtas(Utas u){
    Address p;
    int count;
    if(onlyKicauanUtama(u)){
        return 1;
    }else{
        p = KICAUANUTAMA(u);
        count = 1;
        while (NEXT(p) != NULL){
            count +=1;
            p = NEXT(p);
        }
        return count;
    }
}

void sambungDepanUtas(Utas *utama, Utas uIn){
    Address kicUtama = KICAUANUTAMA(*utama);
    Address next = NEXT(kicUtama);
    NEXT(kicUtama) = uIn;
    NEXT(uIn) = next;
}

void sambungBelakangUtas(Utas *utama, Utas uIn){
    if(onlyKicauanUtama(*utama)){
        NEXT(*utama) = uIn;
    }else{
        Address p = KICAUANUTAMA(*utama);
        while (NEXT(p) != NULL){
            p = NEXT(p);
        }
        NEXT(p) = uIn;
    }
}

void sambungUtasAt(Utas *utama, Utas uIn, int idx){
    if(idx == 1){
        sambungDepanUtas(utama,uIn);
    }else{
        int counter = 0;
        Address p = KICAUANUTAMA(*utama);
        while (counter < idx-1){
            counter +=1;
            p = NEXT(p);
        }
        NEXT(uIn) = NEXT(p);
        NEXT(p) = uIn;
    }
}

void hapusDepanUtas(Utas *utama){
    if(!onlyKicauanUtama(*utama)){
        Address kicUtama = KICAUANUTAMA(*utama);
        Address del = NEXT(kicUtama);
        NEXT(kicUtama) = NEXT(del);
        NEXT(del) = NULL;
        free(del);
    }
}

void hapusBelakangUtas(Utas *utama){
    if(onlyKicauanUtama(*utama)){
        hapusDepanUtas(*utama);
    }else{
        Address del = KICAUANUTAMA(*utama);
        Address prev = NULL;
        while (NEXT(del) != NULL){
            prev = del;
            del = NEXT(del);
        }
        NEXT(prev) = NULL;
        free(del);
    }
}

void hapusUtasAt(Utas *utama, int idx){
    if(idx == 1){
        hapusDepanUtas(utama);
    }else if(idx == panjangUtas(*utama)){
        hapusBelakangUtas(utama);
    }else{
        int counter = 0;
        Address loc = KICAUANUTAMA(*utama);
        while (counter < idx-1){
            counter +=1;
            loc = NEXT(loc);
        }
        Address p = NEXT(loc);
        NEXT(loc) = NEXT(p);
        free(p);
    }
}

void displayUtas(Utas u){
    Address p = KICAUANUTAMA(u);
    printf("| ID =%d\n",ID(u));
    printf("| ");// author
    printf("| ");
    TulisDATETIME(DATETIME(u));
    printf("| ");//isi
    if(NEXT(u) != NULL){
        printf("    | INDEX =%d\n",ID(u));
        printf("    | "); // author
        printf("    | ");
        TulisDATETIME(DATETIME(u));
        printf("    | "); //isi
    }
}

