#include "wordmachine.h"  
#include <stdio.h> 

int main(){
    int nPengguna, i, curIdx1, curIdx2, nPermintaan;
    Word CurNama, CurPassword, CurBio, CurNoHP, CurWeton;
    boolean Jenis;
    char curWarnaProfil[5][5];
    int curPermintaan[3];
    char curCharProfil[5][5];
    int curPertemanan[20][20];
    Word wpath;
    STARTWORD();
    wpath = currentWord;
    wpath.TabWord[wpath.Length] = '\0';
    STARTREADCONFIG(wpath);
    nPengguna = wordToInt(currentWord);
    for(i=0;i<nPengguna;i++){
        ADVWORD_takeBlank();
        CurNama = currentWord;
        ADVWORD_takeBlank();
        CurPassword = currentWord;
        ADVWORD_takeBlank();
        CurBio = currentWord;
        ADVWORD_takeBlank();
        CurNoHP = currentWord;
        ADVWORD_takeBlank();
        CurWeton = currentWord;
        ADVWORD_takeBlank();
        if(isWordEqual(currentWord,stringToWord("Privat"))) Jenis = true;
        else Jenis = false;
        for(curIdx1 = 0; curIdx1<5 ;curIdx1++){
            for(curIdx2 = 0; curIdx2<5 ;curIdx2++){
                ADVWORD();
                curWarnaProfil[curIdx1][curIdx2] = currentWord.TabWord[0];
                ADVWORD();
                curCharProfil[curIdx1][curIdx2] = currentWord.TabWord[0];
            }
        }
        displayWord(CurNama);
        printf("\n");
        displayWord(CurPassword);
        printf("\n");
        displayWord(CurBio);
        printf("\n");
        displayWord(CurNoHP);
        printf("\n");
        displayWord(CurWeton);
        printf("\n");
        if(Jenis) printf("privat\n");
        else printf("gaprivat\n");
        for(curIdx1 = 0; curIdx1<5 ;curIdx1++){
            for(curIdx2 = 0; curIdx2<5 ;curIdx2++){
                printf("%c",curWarnaProfil[curIdx1][curIdx2]);
                printf("%c",curCharProfil[curIdx1][curIdx2]);
            }
            printf("\n");
        }
    }
    for(curIdx1 = 0; curIdx1<20 ;curIdx1++){
        for(curIdx2 = 0; curIdx2<20 ;curIdx2++){
            curPertemanan[curIdx1][curIdx2] = 0;
        }
    }
    for(curIdx1 = 0; curIdx1<nPengguna ;curIdx1++){
        for(curIdx2 = 0; curIdx2<nPengguna ;curIdx2++){
            ADVWORD();
            curPertemanan[curIdx1][curIdx2] = wordToInt(currentWord);
        }
    }
    for(curIdx1 = 0; curIdx1<20 ;curIdx1++){
        for(curIdx2 = 0; curIdx2<20 ;curIdx2++){
            printf("%d",curPertemanan[curIdx1][curIdx2]);
        }
        printf("\n");
    }
    ADVWORD();
    nPermintaan = wordToInt(currentWord);
    for(i = 0;i<nPermintaan;i++){
        ADVWORD();
        curPermintaan[0] = wordToInt(currentWord);
        ADVWORD();
        curPermintaan[1] = wordToInt(currentWord);
        ADVWORD();
        curPermintaan[2] = wordToInt(currentWord);
        printf("%d ",curPermintaan[0]);
        printf("%d ",curPermintaan[1]);
        printf("%d\n",curPermintaan[2]);
    }
}