#ifndef STACKDRAF_H
#define STACKDRAF_H

#include "boolean.h"
#include "datetime.h"
#include "wordmachine.h"
#include <stdlib.h>

#define NIL NULL
/* Deklarasi infotype */
/* Stack dengan representasi berkait dengan pointer */

typedef struct {
    DATETIME T;
    Word text;  
} Draf;

typedef struct nodeDraf* AddressDraf;
typedef struct nodeDraf { 
    Draf d;
    AddressDraf nextDraf; 
} NodeDraf; 

/* Type stack dengan ciri Top: */
typedef struct { 
    AddressDraf addrTopDraf; /* alamat Top: elemen puncak */
} StackDraf;

/* Selektor */
#define DATETIME_DRAF(d) (d).T
#define     TEXT_DRAF(d) (d).text
#define     NEXT_Draf(p) (p)->nextDraf
#define     INFO_Draf(p) (p)->d
#define ADDR_TOP_Draf(s) (s).addrTopDraf
#define      TOP_Draf(s) (s).addrTopDraf->d



void createDraf(Draf *d, Word text);
void createDrafConfig(Draf *d, Word text, DATETIME inpdt);
void displayDraf(Draf d);

/* Prototype manajemen memori */
AddressDraf newNodeDraf(Draf d);
/* Mengembalikan alamat sebuah Node hasil alokasi dengan info = x, 
   atau 
   NULL jika alokasi gagal */   

/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
boolean isEmptyDraf(StackDraf s);
/* Mengirim true jika Stack kosong: TOP(s) = NIL */

int lengthDraf(StackDraf s);
/* Mengirimkan banyaknya elemen stack. Mengirimkan 0 jika Stack s kosong */

void CreateStackDraf(StackDraf *s);
/* I.S. sembarang */ 
/* F.S. Membuat sebuah stack s yang kosong */

void pushDraf(StackDraf *s, Draf d);
/* Menambahkan x sebagai elemen Stack s */
/* I.S. s mungkin kosong, x terdefinisi */
/* F.S. x menjadi Top yang baru jika alokasi x berhasil, */
/*      jika tidak, s tetap */
/* Pada dasarnya adalah operasi insertFirst pada list linier */

void popDraf(StackDraf *s, Draf *d);
/* Menghapus Top dari Stack s */
/* I.S. s tidak kosong */
/* F.S. x adalah nilai elemen Top yang lama, */
/*      elemen Top yang lama didealokasi */
/* Pada dasarnya adalah operasi deleteFirst pada list linier */

#endif