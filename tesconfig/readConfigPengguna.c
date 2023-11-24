#include "wordmachine.h"  
#include <stdio.h> 
#include "../ADT/pengguna.h"
#include "../ADT/liststatikpengguna.h"
#include "../ADT/permintaan_pertemanan.h"

extern ListPengguna progListPengguna;
extern Friends progFriends;
extern Queue progQueue[20];

void readConfigPengguna(Word wpath){
    int nPengguna, h, curIdx1, curIdx2, nPermintaan;
    Word CurNama, CurPassword, CurBio, CurNoHP, CurWeton;
    boolean CurJenis;
    Matrix CurWarnaProfil;
    Matrix CurSimbolProfil;
    Word wpath;
    createListPengguna(&progListPengguna);
    STARTREADCONFIG(wpath);
    nPengguna = wordToInt(currentWord);
    for(h = 0; h < nPengguna; h++){
        Pengguna User;
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
        if (isWordEqual(currentWord,stringToWord("Privat"))){
            CurJenis = false;
        } else {
            CurJenis = true;
        }
        for(int i = 0; i < 5; i++){
            Word temp;
            ADVWORD_takeBlank();
            temp = currentWord;
            int k = 0;
            for(int j = 0; j < 5; j++){
                ELMT_FT(CurWarnaProfil, i, j) = charToWord(temp.TabWord[k]);
                k += 4;
            }
            k = 2;
            for(int j = 0; j < 5; j++){
                ELMT_FT(CurSimbolProfil, i, j) = charToWord(temp.TabWord[k]);
                k += 4;
            }
        }
        createPengguna(&User, h, CurNama, CurPassword, CurBio, CurNoHP, CurWeton, CurJenis, CurWarnaProfil, CurSimbolProfil);
        ELMT_LP(progListPengguna, h) = User;
    }
}

void readConfigPermintaanPertemanan(Word wpath){
    infotype dum;
    int nPermintaan, idx;
    ADVWORD();
    nPermintaan = wordToInt(currentWord);
    for(int j=0; j<20; j++){
        createFriendReqList(&progQueue[j]);
    }
    for(int i = 0; i < nPermintaan; i++){
        ADVWORD();
        Info(dum) = Nama(ELMT_LP(progListPengguna, wordToInt(currentWord)));
        ADVWORD();
        idx = wordToInt(currentWord);
        ADVWORD();
        Prio(dum) = wordToInt(currentWord);
        Enqueue(&progQueue[idx], dum);
    }
}

// int main(){
//         displayWord(CurNama);
//         printf("\n");
//         displayWord(CurPassword);
//         printf("\n");
//         displayWord(CurBio);
//         printf("\n");
//         displayWord(CurNoHP);
//         printf("\n");
//         displayWord(CurWeton);
//         printf("\n");
//         if(Jenis) printf("privat\n");
//         else printf("gaprivat\n");
//         for(curIdx1 = 0; curIdx1<5 ;curIdx1++){
//             for(curIdx2 = 0; curIdx2<5 ;curIdx2++){
//                 printf("%c",curWarnaProfil[curIdx1][curIdx2]);
//                 printf("%c",curCharProfil[curIdx1][curIdx2]);
//             }
//             printf("\n");
//         }
//     }
//     for(curIdx1 = 0; curIdx1<20 ;curIdx1++){
//         for(curIdx2 = 0; curIdx2<20 ;curIdx2++){
//             curPertemanan[curIdx1][curIdx2] = 0;
//         }
//     }
//     for(curIdx1 = 0; curIdx1<nPengguna ;curIdx1++){
//         for(curIdx2 = 0; curIdx2<nPengguna ;curIdx2++){
//             ADVWORD();
//             curPertemanan[curIdx1][curIdx2] = wordToInt(currentWord);
//         }
//     }
//     for(curIdx1 = 0; curIdx1<20 ;curIdx1++){
//         for(curIdx2 = 0; curIdx2<20 ;curIdx2++){
//             printf("%d",curPertemanan[curIdx1][curIdx2]);
//         }
//         printf("\n");
//     }
//     ADVWORD();
//     nPermintaan = wordToInt(currentWord);
//     for(i = 0;i<nPermintaan;i++){
//         ADVWORD();
//         curPermintaan[0] = wordToInt(currentWord);
//         ADVWORD();
//         curPermintaan[1] = wordToInt(currentWord);
//         ADVWORD();
//         curPermintaan[2] = wordToInt(currentWord);
//         printf("%d ",curPermintaan[0]);
//         printf("%d ",curPermintaan[1]);
//         printf("%d\n",curPermintaan[2]);
//     }
// }