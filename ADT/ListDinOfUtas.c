#include "ListDinOfUtas.h"

void CreateListDinUtas(ListUtas *lu, int capacity){
    /* I.S. l sembarang, capacity > 0 */
    /* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
    CAPACITY(*lu) = capacity;
    BUFFER(*lu) = (ElType *)malloc(capacity * sizeof(ElType));
    NEFF(*lu) = 0;
}

void dealocateListUtas(ListUtas *lu){
    /* I.S. l terdefinisi; */
    /* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */
    NEFF(*lu) = 0;
    CAPACITY(*lu) = 0;
    free(BUFFER(*lu));
}

int listLengthUtas(ListUtas lu){
    /* Mengirimkan banyaknya elemen efektif list */
    /* Mengirimkan nol jika list l kosong */
    /* *** Daya tampung container *** */
    return NEFF(lu);
}

/* *** Selektor INDEKS *** */
IdxType getFirstIdxUtas(ListUtas lu){
    /* Prekondisi : List l tidak kosong */
    /* Mengirimkan indeks elemen l pertama */
    return IDX_MIN;
}

IdxType getLastIdxUtas(ListUtas lu){
    /* Prekondisi : List l tidak kosong */
    /* Mengirimkan indeks elemen l terakhir */
    return(IdxType)(listLength(lu)-1);
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmptyUtas(ListUtas lu){
    /* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
    /* *** Test list penuh *** */
    return(listLength(lu) == 0);
}

boolean isFullUtas(ListUtas lu){
    /* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
    return(listLength(lu) == CAPACITY(lu));
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValidUtas(ListUtas lu, IdxType i){
    /* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
    /* yaitu antara indeks yang terdefinisi utk container*/
    return (i>=getFirstIdx(lu)) && (i< CAPACITY(lu));
}

boolean isIdxEffUtas(ListUtas lu, IdxType i){
    /* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
    /* yaitu antara 0..NEFF(l) */
    return (i>=getFirstIdx(lu)) && (i<=NEFF(lu));
}

void insertLastUtas(ListUtas *lu, ElType val){
    /* Proses: Menambahkan val sebagai elemen terakhir list */
    /* I.S. List l boleh kosong, tetapi tidak penuh */
    /* F.S. val adalah elemen terakhir l yang baru */
    ELMT(*lu,NEFF(*lu)) = val;
    NEFF(*lu) += 1;
}

void expandListUtas(ListUtas *lu, int num){
    /* Proses : Menambahkan capacity l sebanyak num */
    /* I.S. List sudah terdefinisi */
    /* F.S. Ukuran list bertambah sebanyak num */
    ListUtas ltemp;
    int i;
    CreateListDin(&ltemp, CAPACITY(*lu) + num);
    for(i = 0; i < NEFF(*lu); i++){
       ELMT(ltemp,i) = ELMT(*lu,i);
    }
    NEFF(ltemp) = NEFF(*lu);
    dealocateList(lu);
    copyList(ltemp,lu);
}