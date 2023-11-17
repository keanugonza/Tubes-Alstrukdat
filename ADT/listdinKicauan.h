
#ifndef LISTDINKICAUAN_H
#define LISTDINKICAUAN_H

#include "boolean.h"
#include "kicauan.h"

/* Definisi elemen dan koleksi objek */

typedef int IdxType;
typedef Kicauan ELType;
typedef struct
{
    Kicauan *buffer_Kicauan; /* memori tempat penyimpan elemen (container) */
    int nEff_Kicauan;       /* >=0, banyaknya elemen efektif */
    int capacity_Kicauan;   /* ukuran elemen */
} ListDinKicauan;


/* ********** SELEKTOR ********** */
#define NEFF_Kicauan(l) (l).nEff_Kicauan
#define BUFFER_Kicauan(l) (l).buffer_Kicauan
#define KICAUAN(l, i) (l).buffer_Kicauan[i]
#define CAPACITY_Kicauan(l) (l).capacity_Kicauan

/* ********** KONSTRUKTOR ********** */

void CreateListDinKicauan(ListDinKicauan *l, int capacity);
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */

void dealocateListKicauan(ListDinKicauan *l);
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLengthKicauan(ListDinKicauan l);
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */

boolean isEmptyKicauan(ListDinKicauan l);
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
boolean isFullKicauan(ListDinKicauan l);
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
void setKicauan(ListDinKicauan *l, Kicauan k, IdxType idx);

void insertKicauan(ListDinKicauan *l, Kicauan val);
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void copyListKicauan(ListDinKicauan lIn, ListDinKicauan *lOut);
/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandListKicauan(ListDinKicauan *l, int num);
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

#endif