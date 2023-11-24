#include <stdio.h>
#include "../data.h"

extern ListPengguna progListPengguna;
extern Friends progFriends;
extern Queue progQueue[20];
extern Friends progFriends;
extern StackDraf progStackDraf[20];

void readConfigPermintaanPertemanan(){
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

void readConfigPengguna(Word wpath){
    int nPengguna, h, curIdx1, curIdx2, nPermintaan;
    Word CurNama, CurPassword, CurBio, CurNoHP, CurWeton;
    boolean CurJenis;
    Matrix CurWarnaProfil;
    Matrix CurSimbolProfil;
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
        insertLastPengguna(&progListPengguna, User);
    }
    for(int i = 0;i<20;i++){
        for(int j = 0; j<20;j++){
            NODE_TEMAN(progFriends,i,j) = 0;
        }
    }
    for(int i = 0;i<nPengguna;i++){
        for(int j = 0; j<nPengguna;j++){
            ADVWORD();
            NODE_TEMAN(progFriends,i,j) = wordToInt(currentWord);
        }
    }
    readConfigPermintaanPertemanan();
}


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
            curBalasDibalas = wordToInt(currentWord);
            ADVWORD();
            curIdBalasan = wordToInt(currentWord);
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
                    ANAK_KICAU(KICAUAN(*progListKicau, curIdKicauDibalas-1)) = curTempBalasan;
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
                newChildBalasan(curParBalasan, curTempBalasan);
            }
        }
    }
}

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

void readConfigDraf(Word wpath){
    STARTREADCONFIG(wpath);
    int jumlahUserDraf = wordToInt(currentWord);
    for(int i=0; i< jumlahUserDraf; i ++){
        ADVWORD_takeBlank();
        Word author = takeNama(currentWord);
        int jumlahDraf = takeIntLast(currentWord);

        int idx_pengguna = idxPengguna(progListPengguna, author);
        CreateStackDraf(&progStackDraf[idx_pengguna]);
        
        StackDraf temp;
        CreateStackDraf(&temp);

        Draf draf;
        for(int i =0; i< jumlahDraf; i++){

            ADVWORD_takeBlank();
            Word text = currentWord;

            ADVWORD_takeBlank();
            DATETIME d = wordToDATETIME(currentWord);

            createDrafConfig(&draf, text, d);
            pushDraf(&temp, draf);

        }
        while(!isEmptyDraf(temp)){
            Draf tempDraf;
            popDraf(&temp, &tempDraf);
            pushDraf(&progStackDraf[idx_pengguna], tempDraf);
        }
    }
}

void readConfigUtas(Word wpath, ListPengguna lp, ListUtas *lu, ListDinKicauan lk){
    CreateListDinUtas(lu, 100);
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
        AddressToUtas utasutama = newNodeUtas(CurID, AUTHOR_KICAUAN(KICAUAN(lk,CurID-1)), DATETIME_KICAUAN(KICAUAN(lk,CurID-1)), TEXT_KICAUAN(KICAUAN(lk,CurID-1)));
        insertLastUtas(lu, utasutama);
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
            sambungUtasAt(&utasutama, new, j+1);
        }
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