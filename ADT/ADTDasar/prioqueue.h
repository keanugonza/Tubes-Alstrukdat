/* File : prioqueue.h */
/* Definisi ADT Queue versi 3 dengan representasi array secara eksplisit dan alokasi statik */
/* Model Implementasi Versi III dengan circular buffer */
/* Elemen queue terurut mengecil berdasarkan elemen prio */

#ifndef prioqueue_H
#define prioqueue_H

#include "../boolean.h"

#define IDX_UNDEF -1
#define CAPACITY 20

typedef struct{
    int prio; /* [1..3], prioritas dengan nilai 1..3 (3 adalah prioritas tertinggi) */
    int info; /* nilai elemen */
} infotype;
typedef struct{
    infotype buffer[CAPACITY];  /* tabel penyimpan elemen */
    int idxHead; /* index penghapusan */
    int idxTail; /* index penambahan */
} Queue;

/* ********* AKSES (Selektor) ********* */
/* Jika q adalah Queue, maka akses elemen : */
#define Prio(e) (e).prio
#define Info(e) (e).info
#define IDX_HEAD(Q) (Q).idxHead
#define IDX_TAIL(Q) (Q).idxTail
#define HEAD(Q) (Q).buffer[(Q).idxHead]
#define TAIL(Q) (Q).buffer[(Q).idxTail]
#define Elmt(Q, i) (Q).buffer[(i)]

/* ********* Prototype ********* */
/* Mengirim true jika Q kosong: IDX_HEAD dan IDX_TAIL bernilai IDX_UNDEF */
boolean IsEmpty(Queue Q);

/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak CAPACITY*/
boolean IsFull(Queue Q);

/* *** Kreator *** */

/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dengan kondisi sbb: */
/* Proses : Membuat sebuah Q kosong */
void CreateEmpty(Queue *Q);

/* *** Primitif Add/Delete *** */

/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi IDX_TAIL yang baru, IDX_TAIL "maju" dengan mekanisme circular buffer;
        elemen baru disisipkan pada posisi yang tepat sesuai dengan prioritas */
void Enqueue(Queue *Q, infotype X);

/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen IDX_HEAD pd I.S., IDX_HEAD "maju" dengan mekanisme circular buffer;
Q mungkin kosong */
void Dequeue(Queue *Q, infotype *X);

/* Operasi Tambahan */

/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/
void PrintQueue(Queue Q);

#endif