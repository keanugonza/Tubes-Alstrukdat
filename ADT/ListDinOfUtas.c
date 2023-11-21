#include "ListDinOfUtas.h"

void CreateListDinUtas(ListUtas *lu, int capacity){
    /* I.S. l sembarang, capacity > 0 */
    /* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
    CAPACITY_UTAS(*lu) = capacity;
    BUFFER_UTAS(*lu) = (Utas *)malloc(capacity * sizeof(Utas));
    NEFF_UTAS(*lu) = 0;
}

void dealocateListUtas(ListUtas *lu){
    /* I.S. l terdefinisi; */
    /* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */
    NEFF_UTAS(*lu) = 0;
    CAPACITY_UTAS(*lu) = 0;
    free(BUFFER_UTAS(*lu));
}

int listLengthUtas(ListUtas lu){
    /* Mengirimkan banyaknya elemen efektif list */
    /* Mengirimkan nol jika list l kosong */
    /* *** Daya tampung container *** */
    return NEFF_UTAS(lu);
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
boolean isEmptyListUtas(ListUtas lu){
    /* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
    /* *** Test list penuh *** */
    return(listLengthUtas(lu) == 0);
}

boolean isFullListUtas(ListUtas lu){
    /* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
    return(listLengthUtas(lu) == CAPACITY(lu));
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValidListUtas(ListUtas lu, IdxType i){
    /* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
    /* yaitu antara indeks yang terdefinisi utk container*/
    return (i>=getFirstIdx(lu)) && (i< CAPACITY(lu));
}

boolean isIdxEffUtas(ListUtas lu, IdxType i){
    /* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
    /* yaitu antara 0..NEFF(l) */
    return (i>=getFirstIdxUtas(lu)) && (i<=NEFF_UTAS(lu));
}

boolean isInListUtas(ListUtas lu, int id){
    boolean found = false;
    int i = 0;
    while (!found && i<listLengthUtas(lu)){
        if(ID(ELMT(lu,i)) == id) {
            found = true;
        }else{
            i+=1;
        }
    }
    return found;
}

void insertLastUtas(ListUtas *lu, Utas val){
    /* Proses: Menambahkan val sebagai elemen terakhir list */
    /* I.S. List l boleh kosong, tetapi tidak penuh */
    /* F.S. val adalah elemen terakhir l yang baru */
    ELMT_UTAS(*lu,NEFF_UTAS(*lu)) = val;
    NEFF_UTAS(*lu) += 1;
}

void expandListUtas(ListUtas *lu, int num){
    /* Proses : Menambahkan capacity l sebanyak num */
    /* I.S. List sudah terdefinisi */
    /* F.S. Ukuran list bertambah sebanyak num */
    ListUtas ltemp;
    int i;
    CreateListDin(&ltemp, CAPACITY(*lu) + num);
    for(i = 0; i < NEFF_UTAS(*lu); i++){
       ELMT_UTAS(ltemp,i) = ELMT_UTAS(*lu,i);
    }
    NEFF_UTAS(ltemp) = NEFF_UTAS(*lu);
    dealocateListUtas(lu);
    copyList(ltemp,lu);
}