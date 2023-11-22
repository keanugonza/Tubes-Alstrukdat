/*File : Pengguna.h*/
/*Definisi ADT PENGGUNA*/

#ifndef PENGGUNA_H
#define PENGGUNA_H

// #include "boolean...."
#include "wordmachine.h"
#include "ADTDasar\matrix.h"
#include "boolean.h"

typedef struct
{
    int id;                 /* ID Pengguna */
    Word nama;              /* Nama Pengguna */
    Word kata_sandi;        /* Kata Sandi Pengguna */
    Word bio;               /* Bio Pengguna */
    Word noHP;               /* Nomor HP Pengguna */
    Word weton;             /* Weton Pengguna */
    boolean jenis;             /* Jenia Akun Pengguna */
    Matrix foto;            /* Foto Pengguna */
} Pengguna;

/* SELEKTOR Pengguna */

#define Id(User) (User).id
#define Nama(User) (User).nama
#define Kata_sandi(User) (User).kata_sandi
#define Bio(User) (User).bio
#define NoHP(User) (User).noHP
#define Weton(User) (User).weton
#define Jenis(User) (User).jenis
#define Foto(User) (User).foto

/* PROTOTYPE Pengguna */

void createPengguna(Pengguna *User, int id, Word nama, Word kata_sandi, Word bio, Word noHP, Word weton, boolean jenis, Matrix foto);

#endif