#include "../ListDinOfUtas.h"
#include <stdio.h>

boolean EndWord;
Word currentWord;
int main(){
    Word asep;
    asep.TabWord[0] = 'a';
    asep.TabWord[1] = 's';
    asep.TabWord[2] = 'e';
    asep.TabWord[3] = 'p';
    asep.Length = 4;
    Utas u,v, w;
    printf("Masukkan isi utas: ");
    STARTWORD();
    DATETIME now;
    BacaDATETIME(&now);
    u = newNodeUtas(1, asep, now, currentWord);
    displayUtas(u);
    printf("Masukkan isi balasan: ");
    ADVWORD_takeBlank();
    v = newNodeUtas(1, asep, now, currentWord);
    displayUtas(v);
    printf("\n");
    sambungBelakangUtas(&u,v);
    printf("Masukkan isi balasan: ");
    ADVWORD_takeBlank();
    w = newNodeUtas(1, asep, now, currentWord);
    displayUtas(w);
    printf("\n");
    sambungBelakangUtas(&u,w);
    displayUtas(u);
}