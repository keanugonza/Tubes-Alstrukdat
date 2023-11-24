#include "../ADT/wordmachine.h"
#include "../ADT/stackDraf.h"
#include "../ADT/liststatikpengguna.h"
#include  "../src/subprogram/data.h"

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

void readConfigDraf(Word wpath, ListPengguna progListPengguna, StackDraf *progStackDraf[20]){
    STARTREADCONFIG(wpath);
    int jumlahUserDraf = wordToInt(currentWord);
    for(int i=0; i< jumlahUserDraf; i ++){
        ADVWORD_takeBlank();
        Word author = takeNama(currentWord);
        int jumlahDraf = takeIntLast(currentWord);

        int idx_pengguna = idxPengguna(progListPengguna, author);
        CreateStackDraf(progStackDraf[idx_pengguna]);
        
        StackDraf temp;
        CreateStackDraf(&temp);

        Draf draf;
        for(int i =0; i< jumlahDraf; i++){
            ADVWORD_takeBlank();
            DATETIME d = wordToDATETIME(currentWord);

            ADVWORD_takeBlank();
            Word text = currentWord;

            createDraf(&draf, text);
            pushDraf(&temp, draf);

        }
        while(!isEmptyDraf(temp)){
            Draf tempDraf;
            popDraf(&temp, &tempDraf);
            pushDraf(progStackDraf[idx_pengguna], tempDraf);
        }
    }
}