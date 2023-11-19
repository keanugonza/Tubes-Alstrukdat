/*File : Pengguna.c*/
/*Implementasi ADT PENGGUNA*/

#include "pengguna.h"
#include "wordmachine.h"

/* KONSTRUKTOR Pengguna*/

void createPengguna(int id, Word nama, Word kata_sandi, Word bio, Word noHP, Word weton, Word jenis, Matrix foto){
    Pengguna User;
    Id(User) = id;
    Nama(User) = nama;
    Kata_sandi(User) = kata_sandi;
    Bio(User) = bio;
    NoHP(User) = noHP;
    Weton(User) = weton;
    Jenis(User) = jenis;
    Foto(User) = foto;
}

