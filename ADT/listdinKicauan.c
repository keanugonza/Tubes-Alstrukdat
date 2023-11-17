#include "listdinKicauan.h"
#include <stdlib.h>

void CreateListDinKicauan(ListDinKicauan *l, int capacity){
    CAPACITY(*l) = capacity;
    BUFFER(*l) = (Kicauan *)malloc(capacity * sizeof(Kicauan));
    NEFF(*l) = 0;
}
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */

void dealocateListKicauan(ListDinKicauan *l){
    NEFF(*l) = 0;
    CAPACITY(*l) = 0;
    free(BUFFER(*l));
}
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLengthKicauan(ListDinKicauan l){
    return NEFF(l);
}
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */

boolean isEmptyKicauan(ListDinKicauan l){
    return(listLengthKicauan(l) == 0);
}
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
boolean isFullKicauan(ListDinKicauan l){
    return(listLengthKicauan(l) == CAPACITY(l));
}
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
void insertKicauan(ListDinKicauan *l, Kicauan val){
    KICAUAN(*l,NEFF(*l)) = val;
    NEFF(*l) += 1;
}
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */

void copyListKicauan(ListDinKicauan lIn, ListDinKicauan *lOut){
    int i;
    CreateListDinKicauan(lOut, CAPACITY(lIn));
    NEFF(*lOut) = NEFF(lIn);
    for(i = 0; i < NEFF(lIn); i++){
       KICAUAN(*lOut,i) = KICAUAN(lIn,i);
    } 
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandListKicauan(ListDinKicauan *l, int num){
    ListDinKicauan ltemp;
    int i;
    CreateListDinKicauan(&ltemp, CAPACITY(*l) + num);
    for(i = 0; i < NEFF(*l); i++){
       KICAUAN(ltemp,i) = KICAUAN(*l,i);
    }
    NEFF(ltemp) = NEFF(*l);
    dealocateListKicauan(l);
    copyListKicauan(ltemp,l);
}
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

