#include <stdio.h>
#include "boolean.h"
#include "datetime.h"
#include "wordmachine.h"
#include "pengguna.h"


#ifndef KICAUAN_H
#define KICAUAN_H


/* Definisi elemen dan koleksi objek */
typedef struct
{
    int id;
    Word text;
    int like; 
    Word author;  
    DATETIME T;
    boolean Privat;
} Kicauan;


/* ********** SELEKTOR ********** */
#define ID_KICAUAN(K) (K).id
#define TEXT_KICAUAN(K) (K).text
#define LIKE_KICAUAN(K) (K).like
#define AUTHOR_KICAUAN(K) (K).author
#define DATETIME_KICAUAN(K) (K).T
#define PRIVAT_KICAUAN(K) (K).Privat

/* ********** KONSTRUKTOR ********** */

void createKicauan(Kicauan *K, int id, Word text, int like, Pengguna user);

void displayKicauan(Kicauan K);

void tambahLike(Kicauan *K, int like);

void ubahTeksKicauan(Kicauan *K);

#endif