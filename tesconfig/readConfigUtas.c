#include <stdio.h>
#include "data.h"

void readConfigUtas(Word wpath, ListPengguna lp, ListUtas lu, ListDinKicauan lk){
    STARTREADCONFIG(wpath);
    int i,j,nBalas, nUtas = wordToInt(currentWord);
    int CurID;
    AddressToUtas new;
    Kicauan kicauan;
    Word tempIsi, tempAuthor;
    DATETIME tempDate;
    for(i = 0; i < nUtas; i ++){
        ADVWORD_takeBlank();
        CurID = wordToInt(currentWord);
        AddressToUtas new = newNodeUtas(CurID, AUTHOR_KICAUAN(KICAUAN(lk,CurID-1)), DATETIME_KICAUAN(KICAUAN(lk,CurID-1)), TEXT_KICAUAN(KICAUAN(lk,CurID-1)));
        ADVWORD_takeBlank();
        nBalas = wordToInt(currentWord);
        for(j = 0; j < nBalas; j++){
            ADVWORD_takeBlank();
            tempIsi = currentWord;
            ADVWORD_takeBlank();
            tempAuthor = currentWord;
            ADVWORD_takeBlank();
            tempDate = wordToDATETIME(currentWord);
            new = newNodeUtas(0,tempAuthor,tempDate,tempIsi);
        }
    }
}