/*File : list_pengguna.h*/
/*Definisi ADT LIST PENGGUNA*/

#ifndef LISTPENGGUNA_H
#define LISTPENGGUNA_H

#include "pengguna.h"
#include "boolean.h"
#include "wordmachine.h"

/*  Kamus Umum */
#define CAPACITY_LPENGGUNA 20
/* Kapasitas penyimpanan */
#define IDX_MIN_LPENGGUNA 0
/* Indeks minimum list */
#define IDX_UNDEF_LPENGGUNA -1
/* Indeks tak terdefinisi*/

typedef Pengguna eltype; /* type elemen List */
typedef int IdxType;
typedef struct
{
   eltype contents[CAPACITY_LPENGGUNA]; /* memori tempat penyimpan elemen (container) */
   int len;
} ListPengguna;

/* SELEKTOR List Pengguna */

#define ELMT_LP(l, i) (l).contents[(i)]
#define lenListPengguna(l) (l).len

/* PROTOTYPE List Pengguna */

void createListPengguna(ListPengguna *LP);

#endif