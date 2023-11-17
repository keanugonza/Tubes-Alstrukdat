
#ifndef STACKDRAF_H
#define STACKDRAF_H

#include "boolean.h"
#include "kicauan.h"

/*  Kamus Umum */
#define Nil -1


typedef int IdxType;
typedef int address;
typedef Kicauan ELType;
typedef struct
{
    Kicauan *buffer; /* memori tempat penyimpan Kicauan (container) */
    int capacity;\
    address TOP;   /* alamat TOP */
} StackDraf;


/* ********** SELEKTOR ********** */
#define addrTOP(s) (s).TOP
#define BUFFER(s) (s).buffer
#define KICAUAN(s, i) (s).buffer[i]
#define CAPACITY(s) (s).capacity

/* ********** KONSTRUKTOR ********** */

void CreateStackDraf(StackDraf *s, int capacity);
/* I.S. s sembarang, capacity > 0 */
/* F.S. Terbentuk Stack dinamis s kosong dengan kapasitas capacity */

void dealocateStackDraf(StackDraf *l);
/* I.S. s terdefinisi; */
/* F.S. (s) dikembalikan ke system, CAPACITY(s)=0; addrTOP(s)=Nil */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int stackLengthDraf(StackDraf l);
/* Mengirimkan banyaknya elemen efektif Stack */
/* Mengirimkan nol jika Stack s kosong */
/* *** Daya tampung container *** */

boolean isEmptyDraf(StackDraf l);
/* Mengirimkan true jika Stack s kosong, mengirimkan false jika tidak */
boolean isFullDraf(StackDraf l);
/* Mengirimkan true jika Stack s penuh, mengirimkan false jika tidak */
void pushDraf(StackDraf *l, Kicauan val);
/* Proses: Menambahkan val sebagai elemen terakhir Stack */
/* I.S. Stack s boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir s yang baru */
void popDraf(StackDraf *l, Kicauan *val);
/* Proses : Menghapus elemen terakhir Stack */
/* I.S. Stack tidak kosong */
/* F.S. val adalah nilai elemen terakhir s sebelum penghapusan, */
/*      Banyaknya elemen Stack berkurang satu */
/*      Stack s mungkin menjadi kosong */
void copyStackDraf(StackDraf sIn, StackDraf *sOut);
    /* I.S. sIn terdefinisi tidak kosong, sOut sembarang */
    /* F.S. sOut berisi salinan dari sIn (identik, nEff dan capacity sama) */
    /* Proses : Menyalin isi sIn ke sOut */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandStackDraf(StackDraf *l, int num);
/* Proses : Menambahkan capacity s sebanyak num */
/* I.S. Stack sudah terdefinisi */
/* F.S. Ukuran Stack bertambah sebanyak num */

#endif