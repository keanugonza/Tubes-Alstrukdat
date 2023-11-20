#ifndef listutas_H
#define listutas_H

#include <stdlib.h>
#include "wordmachine.h"
#include "boolean.h"
#include "utas.h"

/*  Kamus Umum */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/

typedef Utas ElType; /* type elemen list */
typedef int IdxType;
typedef struct
{
    ElType *buffer; /* memori tempat penyimpan elemen (container) */
    int nEff;       /* >=0, banyaknya elemen efektif */
    int capacity;   /* ukuran elemen */
} ListUtas;

#define NEFF(l) (l).nEff
#define BUFFER(l) (l).buffer
#define ELMT(l, i) (l).buffer[i]
#define CAPACITY(l) (l).capacity


void CreateListDinUtas(ListUtas *lu, int capacity);
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */

void dealocateListUtas(ListUtas *lu);
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLengthUtas(ListUtas lu);
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */

/* *** Selektor INDEKS *** */
IdxType getFirstIdxUtas(ListUtas lu);
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
IdxType getLastIdxUtas(ListUtas lu);
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmptyUtas(ListUtas lu);
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
boolean isFullUtas(ListUtas lu);
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValidUtas(ListUtas lu, IdxType i);
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxEffUtas(ListUtas lu, IdxType i);
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */

boolean isInListUtas(ListUtas lu, int id);
/* Mengirimkan true jika id terdapat dalam list utas */


/* *** Menambahkan elemen terakhir *** */
void insertLastUtas(ListUtas *lu, ElType val);
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandListUtas(ListUtas *lu, int num);
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

#endif