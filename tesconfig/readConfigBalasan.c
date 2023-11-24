#include "data.h"

void readConfigBalasan(Word wpath, ListDinKicauan* progListKicau){
    int nKicauDibalas, curIdKicauDibalas, curJumlahbalasan, curBalasDibalas, curIdBalasan;
    Word namaPembalas, isiBalasan;
    DATETIME dtBalasan;
    Balasan curTempBalasan, par, curParBalasan;
    STARTREADCONFIG(wpath);
    nKicauDibalas = wordToInt(currentWord);
    while(nKicauDibalas--){
        ADVWORD();
        curIdKicauDibalas = wordToInt(currentWord);
        ADVWORD();
        curJumlahbalasan = wordToInt(currentWord);
        par = ANAK_KICAU(KICAUAN(*progListKicau, curIdKicauDibalas-1));
        while(curJumlahbalasan--){
            ADVWORD();
            curBalasDibalas = wordToString(currentWord);
            ADVWORD();
            curIdBalasan = wordToString(currentWord);
            ADVWORD_takeBlank();
            isiBalasan = currentWord;
            ADVWORD_takeBlank();
            namaPembalas = currentWord;
            ADVWORD_takeBlank();
            dtBalasan = wordToDATETIME(currentWord);
            curTempBalasan = newNodeBalasan(curIdBalasan, isiBalasan, namaPembalas, dtBalasan);
            if (curBalasDibalas == -1)
            {
                if (par == NULL)
                {
                    par = curTempBalasan;
                }
                else
                {
                    while (SIBLINGBALASAN(par) != NULL)
                    {
                        par = SIBLINGBALASAN(par);
                    }
                    SIBLINGBALASAN(par) = curTempBalasan;
                }
            }
            else
            {   
                curParBalasan = findByIdBalasan(par, curBalasDibalas);
                newChildBalasan(curBalasDibalas, curTempBalasan);
            }
        }
    }
}