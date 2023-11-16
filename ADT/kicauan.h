#include <stdio.h>
#include "boolean.h"
#include "ADTDasar/datetime.h"
#include "wordmachine.h"


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
#define ID(K) (K).id
#define TEXT(K) (K).text
#define LIKE(K) (K).like
#define AUTHOR(K) (K).author
#define DATETIME(K) (K).T
#define PRIVAT(K) (K).Privat

/* ********** KONSTRUKTOR ********** */

void createKicauan(Kicauan *K, int id, Word text, int like, Word author, DATETIME T, boolean Privat);

void printKicauan(Kicauan *K);

void tambahLike(Kicauan *K, int like);

void ubahKicauan(Kicauan *K, Word text);



#endif