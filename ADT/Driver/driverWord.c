#include "../wordmachine.h"
#include <stdio.h>

Word w;

int main(){
    printf("tes masukkan 1 kata\n");
    STARTWORD_takeBlank();
    ambilWord(&w);
    printf("current word: ");
    displayWord(currentWord);
    printf("\n");
    printf("kata ");
    displayWord(w);
    printf("\n");
    printf("tes masukkan 3 kata\n");
    ADVWORD_takeBlank();
    printf("current word: ");
    displayWord(currentWord);
    printf("\n");
    ambilWord(&w);
    printf("kata1: ");
    displayWord(w);
    printf("\n");
    ADVWORD_takeBlank();
    printf("current word: ");
    displayWord(currentWord);
    printf("\n");
    ambilWord(&w);
    printf("kata2: ");
    displayWord(w);
    printf("\n");
    ADVWORD_takeBlank();
    printf("current word: ");
    displayWord(currentWord);
    printf("\n");
    ambilWord(&w);
    printf("kata3: ");
    displayWord(w);
    printf("\n");
    printf("tes masukan langsung ;\n");
    ADVWORD_takeBlank();
    printf("current word: ");
    displayWord(currentWord);
    printf("\n");
    ambilWord(&w);
    printf("kata: ");
    displayWord(w);
    printf("\n");
}