#include "kicauan.h"
#include "wordmachine.h"


/* ********** KONSTRUKTOR ********** */
boolean EndWord;
Word currentWord;
void createKicauan(Kicauan *K, int id, Word text, int like, Pengguna user){
    DATETIME T;
    BacaDATETIME(&T);
    ID_KICAUAN(*K) = id;
    TEXT_KICAUAN(*K) = text;
    LIKE_KICAUAN(*K) = like;
    AUTHOR_KICAUAN(*K) = user.nama;
    DATETIME_KICAUAN(*K) = T;
    PRIVAT_KICAUAN(*K) = user.jenis;
}


void displayKicauan(Kicauan K){
    // printf("Selamat! kicauan telah diterbitkan!\n");
    // printf("Detil kicauan:\n");
    printf("| ID = %d\n", ID_KICAUAN(K));
    printf("| ");
    displayWord(AUTHOR_KICAUAN(K));
    printf("\n");
    printf("| ");
    TulisDATETIME(DATETIME_KICAUAN(K));
    printf("| ");
    displayWord(TEXT_KICAUAN(K));
    printf("\n");
    printf("| Disukai: %d\n", LIKE_KICAUAN(K));
}


void tambahLike(Kicauan *K, int like){
    LIKE_KICAUAN(*K) = LIKE_KICAUAN(*K) + like;
}

void ubahTeksKicauan(Kicauan *K){
    Word text;
    STARTWORD_takeBlank();
    text = currentWord;
    TEXT_KICAUAN(*K) = text;
}