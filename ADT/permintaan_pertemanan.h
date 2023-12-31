#include "prioqueue.h"
#include "friends.h"
#include "pengguna.h"
#include "liststatikpengguna.h"

/* Membuat Daftar Permintaan Pertemanan */
void createFriendReqList(Queue *q);

/* Mengecek apakah current user sudah mengirimkan permintaan pertemanan dan belum direspons */
boolean hasSentFriendReq(Queue q, Word nama);

/* Meminta Permintaan Pertemanan dengan Pengguna Lain*/
void addFriendReq(Pengguna currUser, Friends FriendReq, ListPengguna ListPenggunaFriendReq);

/* Mencetak Daftar Permintaan Pertemanan Milik User */
void displayFriendReqList(Queue q);

/* Menerima Permintaan Pertemanan dari User Lain */
void accFriendReq(Pengguna currUser, Friends *FriendReq, ListPengguna ListPenggunaFriendReq);