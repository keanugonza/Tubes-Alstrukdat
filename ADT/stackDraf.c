#include "stackDraf.h"



void createDraf(Draf *d, Word text){
    DATETIME T;
    BacaDATETIME(&T);
    DATETIME_DRAF(*d) = T;
    TEXT_DRAF(*d) = text;
}


void displayDraf(Draf d){
    printf("| ");
    TulisDATETIME(DATETIME_DRAF(d));
    printf("| ");
    displayWord(TEXT_DRAF(d));
    printf("\n");
}
 
/* Prototype manajemen memori */
AddressDraf newNodeDraf(Draf d){
    AddressDraf p;
    p = (AddressDraf) malloc(sizeof(Node));

    if(p != NIL){
        INFO_Draf(p)  = d;
        NEXT_Draf(p) = NIL;
    }
    return p;
}
/* Mengembalikan alamat sebuah Node hasil alokasi dengan info = x, 
   atau 
   NULL jika alokasi gagal */   

/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
boolean isEmptyDraf(StackDraf s){
    return (ADDR_TOP_Draf(s) == NIL);
}
/* Mengirim true jika Stack kosong: TOP(s) = NIL */

int lengthDraf(StackDraf s){
    AddressDraf p;
    int i = 0;
    if(!isEmptyDraf(s)){
        p = ADDR_TOP_Draf(s);

        while(p != NIL){
            i++;
            p = NEXT_Draf(p);
        }
    }

    return i;
}
/* Mengirimkan banyaknya elemen stack. Mengirimkan 0 jika Stack s kosong */

void CreateStackDraf(StackDraf *s){
    ADDR_TOP_Draf(*s) = NIL;
}
/* I.S. sembarang */ 
/* F.S. Membuat sebuah stack s yang kosong */

void pushDraf(StackDraf *s, Draf d){
    AddressDraf p = newNodeDraf(d);

    if(p!=NIL){
        NEXT_Draf(p) = ADDR_TOP_Draf(*s);
        ADDR_TOP_Draf(*s) = p;
    }
}
/* Menambahkan x sebagai elemen Stack s */
/* I.S. s mungkin kosong, x terdefinisi */
/* F.S. x menjadi Top yang baru jika alokasi x berhasil, */
/*      jika tidak, s tetap */
/* Pada dasarnya adalah operasi insertFirst pada list linier */

void popDraf(StackDraf *s, Draf *d){
    AddressDraf p;

    *d = TOP_Draf(*s);
    p = ADDR_TOP_Draf(*s);

    if(lengthDraf(*s) == 1){
        ADDR_TOP_Draf(*s) = NIL;
    } else{
        ADDR_TOP_Draf(*s) = NEXT_Draf(p);
    }

    free(p);
}
/* Menghapus Top dari Stack s */
/* I.S. s tidak kosong */
/* F.S. x adalah nilai elemen Top yang lama, */
/*      elemen Top yang lama didealokasi */
/* Pada dasarnya adalah operasi deleteFirst pada list linier */