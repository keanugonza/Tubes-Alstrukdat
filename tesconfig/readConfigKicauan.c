#include "../ADT/wordmachine.h"
#include "../ADT/kicauan.h"
#include "../ADT/listdinKicauan.h"
#include  "../src/subprogram/data.h"

void readConfigKicau(Word wpath, ListDinKicauan *progListDinKicau){
    Kicauan K;
    STARTREADCONFIG(wpath);
    int jumlahKicauan = wordToInt(currentWord);
    CreateListDinKicauan(progListDinKicau, jumlahKicauan);
    for(int i=0; i< jumlahKicauan; i++){
        ADVWORD_takeBlank();
        int idKicau = wordToInt(currentWord);
        ID_KICAUAN(K) = idKicau;

        ADVWORD_takeBlank();
        Word text = currentWord;
        TEXT_KICAUAN(K)= text;

        ADVWORD_takeBlank();
        int like = wordToInt(currentWord);
        LIKE_KICAUAN(K)= like;

        ADVWORD_takeBlank();
        Word author = currentWord;
        AUTHOR_KICAUAN(K) = author;

        ADVWORD_takeBlank();
        DATETIME d = wordToDATETIME(currentWord);
        DATETIME_KICAUAN(K) = d;

        ANAK_KICAU(K) = NULL;

        insertKicauan(progListDinKicau, K);
    }
}