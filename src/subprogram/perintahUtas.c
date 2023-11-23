#include "../../ADT/ListDinOfUtas.h"
#include "../../ADT/listdinKicauan.h"
#include "../../ADT/wordmachine.h"
#include "../../ADT/friends.h"
#include "../../ADT/liststatikpengguna.h"
#include <stdio.h>

void UTAS(ListUtas *lu, ListDinKicauan lk, Pengguna user, int idKicauan){
    Word ya,tidak;
    int idKicauan = idKicauan -1;
    ya.TabWord[0] = 'Y';
    ya.TabWord[1] = 'A';
    ya.Length = 2;
    tidak.TabWord[0] = 'T';
    tidak.TabWord[1] = 'I';
    tidak.TabWord[2] = 'D';
    tidak.TabWord[3] = 'A';
    tidak.TabWord[4] = 'K';
    tidak.Length = 5;
    if((idKicauan) > NEFF_Kicauan(lk)){ // cek apakah kicauan terdapat di list kicauan
        printf("Kicauan tidak ditemukan.\n");
    }else{
        if(isWordEqual(AUTHOR_KICAUAN(KICAUAN(lk,idKicauan)), Nama(user)) ){ // cek apakah kicauan milik user
            DATETIME currDatetime;
            BacaDATETIME(&currDatetime);
            AddressToUtas kicUtama = newNodeUtas(idKicauan, AUTHOR_KICAUAN(KICAUAN(lk,idKicauan)), currDatetime, TEXT_KICAUAN(KICAUAN(lk,idKicauan)));
            if(isFullListUtas(*lu)){
                expandListUtas(lu,2);
            }
            insertLastUtas(lu, kicUtama);
            printf("Utas berhasil dibuat!\n");
            printf("\n");
            boolean selesai = false;
            AddressToUtas new;
            do{ // lakukan masukkan kicauan hingga di input TIDAK
                printf("Masukkan kicauan:\n");
                ADVWORD_takeBlank();
                BacaDATETIME(&currDatetime);
                new = newNodeUtas(1,Nama(user),currDatetime,currentWord);
                sambungBelakangUtas(&kicUtama, new);
                for(;;){ // cek input agar YA atau TIDAK
                    printf("Apakah Anda ingin melanjutkan utas ini? (YA/TIDAK)\n");
                    ADVWORD_takeBlank();
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
    if(isIdxEffUtas(lu,idx)){ // cek apakah utas terdapat di list
        if(isWordEqual(AUTHOR_UTAS(ELMT_UTAS(lu,idx)), Nama(user))){ // cek apakah utas dimiliki pengguna
            AddressToUtas kicUtama = ELMT_UTAS(lu,idx);
            if(idx < panjangUtas(kicUtama)){ //cek apakah terdapat index idx di utas
                printf("Masukkan kicauan:\n");
                //insert word
                DATETIME currDatetime;
                BacaDATETIME(&currDatetime);
                AddressToUtas insert = newNodeUtas(idx, Nama(user), currDatetime, currentWord);
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
    if(idx != 0){ // cek apakah ingin menghapus selain kicauan utama
        if(isIdxEffUtas(lu,idx)){ // cek apakah utas terdapat di list utas
            if(isWordEqual(AUTHOR_UTAS(ELMT_UTAS(lu,idx)), Nama(user))){ // cek apakah utas dimiliki pengguna
                AddressToUtas kicUtama = ELMT_UTAS(lu,idx);
                if(idx<panjangUtas(kicUtama)){ // cek apakah idx merupakan index di utas
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
    if(isIdxEffUtas(lu,idUtas-1)){ // cek apakah terdapat utas dengan idUtas
        int idxP = idxPengguna(lp, AUTHOR_UTAS(ELMT_UTAS(lu,idUtas-1)));
        Pengguna authorUtas = ELMT_LP(lp,idxP);
        if(Jenis(authorUtas)){
            if(isFriend(graphTeman, idxPengguna(lp, AUTHOR_UTAS(ELMT_UTAS(lu,idUtas-1))), idxPengguna(lp,Nama(user)))){ // cek apakah user dan author utas merupakan teman
                displayUtas(ELMT_UTAS(lu,idUtas-1));
            }else{
                printf("Akun yang membuat utas ini adalah akun privat! Ikuti dahulu akun ini untuk melihat utasnya!\n");
            }
        }else{
            displayUtas(ELMT_UTAS(lu,idUtas-1));
        }
        
    }else{
        printf("Utas tidak ditemukan!\n");
    }
}

