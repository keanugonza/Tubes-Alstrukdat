#include <stdio.h>
#include <stdlib.h>
#include "utas.h"

AddressToUtas newNode(int id, Word author, DATETIME dt, Word isi){
    AddressToUtas p = (AddressToUtas) malloc(sizeof(Node));
    if(p != NULL){
        AUTHOR_UTAS(p) = author;
        DATETIME_UTAS(p) = dt;
        ISI_UTAS(p) = isi;
        NEXT_UTAS(p) = NULL;
    }
    return p;
}

boolean isEmptyUtas(Utas u){
    return u == NULL;
}

boolean onlyKicauanUtama(Utas u){
    return !isEmptyUtas(u) && NEXT_UTAS(u) == NULL;
}

int panjangUtas(Utas u){
    AddressToUtas p;
    int count;
    if(onlyKicauanUtama(u)){
        return 1;
    }else{
        p = KICAUANUTAMA(u);
        count = 1;
        while (NEXT_UTAS(p) != NULL){
            count +=1;
            p = NEXT_UTAS(p);
        }
        return count;
    }
}

int getCurrIDX(Utas utama, Utas u){
    AddressToUtas p = KICAUANUTAMA(u);
    Word isi =ISI_UTAS(u);
    int idx = 0;
    boolean found = false;
    while (!found){
        if(isWordEqual(ISI_UTAS(p),isi)){
            found = true;
        }else{
            idx +=1;
        }
    }
    return idx;
    
}

void sambungDepanUtas(Utas *utama, Utas uIn){
    AddressToUtas kicUtama = KICAUANUTAMA(*utama);
    AddressToUtas next_NEXT_UTAS = NEXT_UTAS(kicUtama);
    NEXT_UTAS(kicUtama) = uIn;
    NEXT_UTAS(uIn) = next_NEXT_UTAS;
}

void sambungBelakangUtas(Utas *utama, Utas uIn){
    if(onlyKicauanUtama(*utama)){
        NEXT_UTAS(*utama) = uIn;
    }else{
        AddressToUtas p = KICAUANUTAMA(*utama);
        while (NEXT_UTAS(p) != NULL){
            p = NEXT_UTAS(p);
        }
        NEXT_UTAS(p) = uIn;
    }
}

void sambungUtasAt(Utas *utama, Utas uIn, int idx){
    if(idx == 1){
        sambungDepanUtas(utama,uIn);
    }else{
        int counter = 0;
        AddressToUtas p = KICAUANUTAMA(*utama);
        while (counter < idx-1){
            counter +=1;
            p = NEXT_UTAS(p);
        }
        NEXT_UTAS(uIn) = NEXT_UTAS(p);
        NEXT_UTAS(p) = uIn;
    }
}

void hapusDepanUtas(Utas *utama){
    if(!onlyKicauanUtama(*utama)){
        AddressToUtas kicUtama = KICAUANUTAMA(*utama);
        AddressToUtas del = NEXT_UTAS(kicUtama);
        NEXT_UTAS(kicUtama) = NEXT_UTAS(del);
        NEXT_UTAS(del) = NULL;
        free(del);
    }
}

void hapusBelakangUtas(Utas *utama){
    if(onlyKicauanUtama(*utama)){
        hapusDepanUtas(*utama);
    }else{
        AddressToUtas del = KICAUANUTAMA(*utama);
        AddressToUtas prev = NULL;
        while (NEXT_UTAS(del) != NULL){
            prev = del;
            del = NEXT_UTAS(del);
        }
        NEXT_UTAS(prev) = NULL;
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
        AddressToUtas loc = KICAUANUTAMA(*utama);
        while (counter < idx-1){
            counter +=1;
            loc = NEXT_UTAS(loc);
        }
        AddressToUtas p = NEXT_UTAS(loc);
        NEXT_UTAS(loc) = NEXT_UTAS(p);
        free(p);
    }
}

void displayUtas(Utas u){
    AddressToUtas p = KICAUANUTAMA(u);
    printf("| ID =%d\n", ID(p));
    printf("| ");// author
    displayWord(AUTHOR_UTAS(u));
    printf("\n");
    printf("| ");
    TulisDATETIME(DATETIME_UTAS(u));
    printf("\n");
    printf("| ");//isi
    displayWord(ISI_UTAS(u));
    printf("\n");
    if(NEXT_UTAS(p) != NULL){
        printf("    | INDEX =%d\n",getCurrIDX(u,p));
        printf("    | "); // author
        displayWord(AUTHOR_UTAS(u));
        printf("\n");
        printf("    | ");
        TulisDATETIME(DATETIME_UTAS(u));
        printf("    | "); //isi
        displayWord(ISI_UTAS(u));
        printf("\n");
    }
}

