/*File : list_pengguna.h*/
/*Definisi ADT LIST PENGGUNA*/

#ifndef LISTSTATIKPENGGUNA_H
#define LISTSTATIKPENGGUNA_H

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
/* I.S. LP sembarang */
/* F.S. Terbentuk List LP kosong dengan kapasitas CAPACITY_LPENGGUNA */
/* Proses: Inisialisasi semua elemen List LP dengan MARK */

void insertPengguna(ListPengguna *LP, eltype val);
/* I.S. LP sembarang */
/* F.S. List LP dengan elemen terakhir yaitu val */
/* Proses: Menambahkan val ke dalam LP*/

boolean isMember(ListPengguna LP, Word val);
/* Prekondisi LP sembarang */
/* Mengembalikan nilai true jika val terdapat dalam list */

int idxPengguna(ListPengguna LP, Word val);
/* Prekondisi LP sembarang */
/* Mengembalika id Pengguna berdasarkan nama*/

void printInfoPengguna(ListPengguna LP, int id);
/* I.S. LP sembarang */
/* F.S. Menampilkan info pengguna */
/* Proses: Menampilkan info pengguna*/

void displayProfil(ListPengguna LP, int id);

#endif