#include "wordmachine.h"
#include "datetime.h"
#include <stdio.h>
int takeIntLast(Word word){
    int banyak = 0;
    for(int i =word.Length -1; i >= 0; i--){
        if(word.TabWord[i] != ' '){
            banyak++;
        }
        if(word.TabWord[i] == ' '){
            break;
        }
    }
    Word out;
    out.Length = banyak;

    int idxStart = word.Length - banyak;
    int k = 0;
    for(int j = idxStart; j < word.Length;j++){
        out.TabWord[k] = word.TabWord[j];
        k++;
    }

    int hasil = wordToInt(out);

    return hasil;
}

Word takeNama(Word word){
    int banyak = 0;
    for(int i =word.Length -1; i >= 0; i--){
        if(word.TabWord[i] != ' '){
            banyak++;
        }
        if(word.TabWord[i] == ' '){
            break;
        }
    }

    Word out;
    out.Length = word.Length - banyak -1;
    for(int j = 0; j < out.Length;j++){
        out.TabWord[j] = word.TabWord[j];
    }

    return out;
}

int main(){
    STARTWORD();
    Word text = currentWord;
    displayWord(text);

    ADVWORD_takeBlank();
    int hasil = takeIntLast(currentWord);
    printf("%d", hasil);
    Word Nama= takeNama(currentWord);
    displayWord(Nama);
    printf("test");
}