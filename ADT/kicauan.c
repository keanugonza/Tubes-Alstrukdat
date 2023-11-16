#include "kicauan.h"


/* ********** KONSTRUKTOR ********** */

void createKicauan(Kicauan *K, int id, Word text, int like, Word author, DATETIME D, boolean Privat){
    ID(*K) = id;
    TEXT(*K) = text;
    LIKE(*K) = like;
    AUTHOR(*K) = author;
    DATETIME(*K) = D;
    PRIVAT(*K) = Privat;
}


void printKicauan(Kicauan *K){
    printf("Selamat! kicauan telah diterbitkan!\n");
    printf("Detil kicauan:\n");
    printf("| ID = %d\n", ID(*K));
    printf("| ini author\n");
    printf("| ");
    TulisDATETIME(DATETIME(*K));
    printf("| ini isi kicauan\n");
    printf("| Disukai: %d\n", LIKE(*K));
}


void tambahLike(Kicauan *K, int like){
    LIKE(*K) = LIKE(*K) + like;
}