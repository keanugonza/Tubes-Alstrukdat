#include "../wordmachine.h"
#include <stdio.h>

Word w;

int main(){
    printf("tes masukkan 1 kata\n");
    STARTWORD_takeBlank();
    w = currentWord;
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
    w = currentWord;
    printf("kata1: ");
    displayWord(w);
    printf("\n");
    ADVWORD_takeBlank();
    printf("current word: ");
    displayWord(currentWord);
    printf("\n");
    w = currentWord;
    printf("kata2: ");
    displayWord(w);
    printf("\n");
    ADVWORD_takeBlank();
    printf("current word: ");
    displayWord(currentWord);
    printf("\n");
    w = currentWord;
    printf("kata3: ");
    displayWord(w);
    printf("\n");
    printf("tes masukan langsung ;\n");
    ADVWORD_takeBlank();
    printf("current word: ");
    displayWord(currentWord);
    printf("\n");
    w = currentWord;
    printf("kata: ");
    displayWord(w);
    printf("\n");
    char* str;
    str = wordToString(w);
    printf("Ini stringnya: ");
    int i = 0;
    while(str[i] != '\0'){
        printf("%c", str[i]);
        i ++;
    }
}