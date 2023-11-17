#ifndef utas_H
#define utas_H

#include "wordmachine.h"
#include "ADTDasar/datetime.h"

/* Definisi Node : */
typedef struct node* Address;
typedef struct node {
    int id;
    Word author;
    DATETIME datetime;
    Word isi;
    Address next;
} Node;

#define KICAUANUTAMA(p) p
#define ID(p) (p)->id
#define AUTHOR(p) (p)->author
#define NEXT(p) (p)->next
#define DATETIME(p) (p)->datetime
#define ISI(p) (p)->isi

typedef Address Utas;

Address newNode(int id, Word author, DATETIME dt, Word isi);
/*Membuat node utas baru*/

boolean isEmptyUtas(Utas u);

boolean onlyKicauanUtama(Utas u);
/*Utas memiliki kicauan utama saja jika NEXT(u) = NULL*/

int panjangUtas(Utas u);
/*Mengembalikkan panjang utas*/

void sambungDepanUtas(Utas *utama, Utas uIn);
/*I.S Utas terdefinisi*/
/*F.S Utas telah ditambahkan uIn di depan kicauan utama*/

void sambungBelakangUtas(Utas *utama, Utas uIn);
/*I.S Utas terdefinisi*/
/*F.S Utas telah ditambahkan uIn di paling belakang*/

void sambungUtasAt(Utas *utama, Utas uIn, int idx);
/*I.S Utas terdefinisi dan idx dipastikan valid dalam utas*/
/*F.S Utas telah ditambahkan uIn di indeks idx*/

void hapusDepanUtas(Utas *utama);
/*I.S Utas terdefinisi*/
/*F.S Utas setelah kicauan utama telah dihapus*/

void hapusBelakangUtas(Utas *utama);
/*I.S Utas terdefinisi*/
/*F.S Utas di paling belakang dihapus*/

void hapusUtasAt(Utas *utama, int idx);
/*I.S Utas terdefinisi dan idx merupakan index valid dalam utas*/
/*F.S Utas pada indeks idx dihapus*/

void displayUtas(Utas u);
/*I.S Utas memiliki kicauan utama*/
/*F.S Menampilkan utas secara keseluruhan dengan tampilan kicauan utama*/
/*  | ID = 15  //idKicau
    | John Doe //author
    | 14/10/2023 11:09:18 //datetime
    | Hello BurBir! //isi kicauan
    dan tampilan kicauan balasan dalam utas
    | INDEX = 1 //index balasan
    | John Doe // author
    | 29/07/2023 00:01:53 // datetime
    | Mari menyambung BurBir! //isi kicauan

*/

#endif