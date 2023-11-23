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

typedef int IdxType;
typedef struct
{
    Utas *buffer_utas; /* memori tempat penyimpan elemen (container) */
    int nEff_utas;       /* >=0, banyaknya elemen efektif */
    int capacity_utas;   /* ukuran elemen */
} ListUtas;

#define NEFF_UTAS(l) (l).nEff_utas
#define BUFFER_UTAS(l) (l).buffer_utas
#define ELMT_UTAS(l, i) (l).buffer_utas[i]
#define CAPACITY_UTAS(l) (l).capacity_utas


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
boolean isEmptyListUtas(ListUtas lu);
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
boolean isFullListUtas(ListUtas lu);
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValidListUtas(ListUtas lu, IdxType i);
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxEffUtas(ListUtas lu, IdxType i);
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */

boolean isInListUtas(ListUtas lu, int id);
/* Mengirimkan true jika id terdapat dalam list utas */


/* *** Menambahkan elemen terakhir *** */
void insertLastUtas(ListUtas *lu, Utas val);
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */

void copyListUtas(ListUtas lIn, ListUtas *lOut);
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandListUtas(ListUtas *lu, int num);
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

#endif