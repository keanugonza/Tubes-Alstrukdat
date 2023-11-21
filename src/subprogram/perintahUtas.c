#include "../../ADT/ListDinOfUtas.h"
#include "../../ADT/listdinKicauan.h"
#include "../../ADT/liststatikpengguna.h"
#include "../../ADT/friends.h"
#include <stdio.h>

void UTAS(ListUtas *lu, ListDinKicauan lk, Pengguna user, int idUtas, int idKicauan){
    Word ya,tidak;
    ya.TabWord[0] = 'Y';
    ya.TabWord[1] = 'A';
    ya.Length = 2;
    tidak.TabWord[0] = 'T';
    tidak.TabWord[1] = 'I';
    tidak.TabWord[2] = 'D';
    tidak.TabWord[3] = 'A';
    tidak.TabWord[4] = 'K';
    tidak.Length = 5;
    if((idKicauan) > NEFF_Kicauan(lk)){
        printf("Kicauan tidak ditemukan.\n");
    }else{
        if(isWordEqual(AUTHOR_KICAUAN(KICAUAN(lk,idKicauan)), Nama(user)) ){
            DATETIME currDatetime;
            BacaDATETIME(&currDatetime);
            AddressToUtas new = newNode(idKicauan, AUTHOR_KICAUAN(KICAUAN(lk,idKicauan)), currDatetime, TEXT_KICAUAN(KICAUAN(lk,idKicauan)));
            if(isFullListUtas(*lu)){
                expandListUtas(lu,2);
            }
            insertLastUtas(lu, new);
            printf("Utas berhasil dibuat!\n");
            printf("\n");
            printf("\n");
            boolean selesai = false;
            do{
                printf("Masukkan kicauan:\n");
                //input word
                for(;;){
                    printf("Apakah Anda ingin melanjutkan utas ini? (YA/TIDAK)\n");
                    //input word
                    if(isWordEqual(currentWord,ya) || isWordEqual(currentWord,tidak)){
                        break;
                    }else{
                        printf("Silahkan ulangi input anda!\n");
                    }
                }

                if(isWordEqual(currentWord,tidak)){
                    selesai = true;
                }
            }while(!selesai);
            printf("Utas selesai!\n");

        }else{
            printf("Utas ini bukan milik anda!\n");
        }
    }
}

void SAMBUNG_UTAS(ListUtas lu, Pengguna user, int idUtas, int idx){
    if(isIdxEffUtas(lu,idx)){
        if(isWordEqual(AUTHOR_UTAS(ELMT_UTAS(lu,idx)), Nama(user))){
            AddressToUtas kicUtama = ELMT_UTAS(lu,idx);
            if(idx < panjangUtas(kicUtama)){
                printf("Masukkan kicauan:\n");
                //insert word
                DATETIME currDatetime;
                BacaDATETIME(&currDatetime);
                AddressToUtas insert = newNode(idx, Nama(user), currDatetime, currentWord);
                sambungUtasAt(&kicUtama, insert, idx);
                printf("Utas berhasil disambung.\n");
            }else{
                printf("Index terlalu tinggi!\n");
            }
        }else{
            printf("Anda tidak bisa menyambung utas ini!\n");
        }
    }else{
        printf("Utas tidak ditemukan!\n");
    }
}

void HAPUS_UTAS(ListUtas lu, Pengguna user, int idUtas, int idx){
    if(idx != 0){
        if(isIdxEffUtas(lu,idx)){
            if(isWordEqual(AUTHOR_UTAS(ELMT_UTAS(lu,idx)), Nama(user))){
                AddressToUtas kicUtama = ELMT_UTAS(lu,idx);
                if(idx<panjangUtas(kicUtama)){
                    hapusUtasAt(&kicUtama, idx);
                    printf("Kicauan sambungan berhasil dihapus!\n");
                }else{
                    printf("Kicauan sambungan dengan index %d tidak ditemukan pada utas!\n", idx);
                }
            }else{
                printf("Anda tidak bisa menghapus kicauan dalam utas ini!\n");
            }
        }else{
            printf("Utas tidak ditemukan!\n");
        }
    }else{
        printf("Anda tidak bisa menghapus kicauan utama!\n");
    }
}

void CETAK_UTAS(ListUtas lu, Friends graphTeman, ListPengguna lp, Pengguna user,int idUtas){
    if(isIdxEffUtas(lu,idUtas-1)){
        if(isFriend(graphTeman, idxPengguna(lp, AUTHOR_UTAS(ELMT_UTAS(lu,idUtas-1))), idxPengguna(lp,Nama(user)))){
            displayUtas(ELMT_UTAS(lu,idUtas-1));
        }else{
            printf("Akun yang membuat utas ini adalah akun privat! Ikuti dahulu akun ini untuk melihat utasnya!\n");
        }
    }else{
        printf("Utas tidak ditemukan!\n");
    }
}

