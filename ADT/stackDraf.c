#include "stackDraf.h" 
#include <stdlib.h>

void CreateStackDraf(StackDraf *s, int capacity){
    CAPACITY(*s) = capacity;
    BUFFER(*s) = (Kicauan *)malloc(capacity * sizeof(Kicauan));
    addrTOP(*s) = Nil;
}
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */

void dealocateStackDraf(StackDraf *s){
    addrTOP(*s) = 0;
    CAPACITY(*s) = 0;
    free(BUFFER(*s));
}
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int stackLengthDraf(StackDraf s){
    return addrTOP(s) + 1;
}
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */

boolean isEmptyDraf(StackDraf s){
    return(stackLengthDraf(s) == 0);
}
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
boolean isFullDraf(StackDraf s){
    return(stackLengthDraf(s) == CAPACITY(s));
}
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
void pushDraf(StackDraf *s, Kicauan val){
    KICAUAN(*s,addrTOP(*s)+1) = val;
    addrTOP(*s) += 1;
}
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void popDraf(StackDraf *s, Kicauan *val){
    *val = KICAUAN(*s,addrTOP(*s));
    addrTOP(*s) -= 1;
}
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */
void copyStackDraf(StackDraf sIn, StackDraf *sOut){
    /* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
    /* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
    /* Proses : Menyalin isi lIn ke lOut */
    int i;
    CreateStackDraf(sOut, CAPACITY(sIn));
    addrTOP(*sOut) = addrTOP(sIn);
    for(i = 0; i <= addrTOP(sIn); i++){
       KICAUAN(*sOut,i) = KICAUAN(sIn,i);
    }   
}
/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandStackDraf(StackDraf *s, int num){
    StackDraf stemp;
    int i;
    CreateStackDraf(&stemp, CAPACITY(*s) + num);
    for(i = 0; i <= addrTOP(*s); i++){
       KICAUAN(stemp,i) = KICAUAN(*s,i);
    }
    addrTOP(stemp) = addrTOP(*s);
    dealocateStackDraf(s);
    copyStackDraf(stemp,s);
}
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
