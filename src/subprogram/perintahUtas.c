#include "../../ADT/ListDinOfUtas.h"
#include "../../ADT/listdinKicauan.h"
#include "../../ADT/wordmachine.h"
#include "../../ADT/friends.h"
#include "../../ADT/liststatikpengguna.h"
#include <stdio.h>

void UTAS(ListUtas *lu, ListDinKicauan lk, Pengguna user, int idKicauan){
    Word ya = stringToWord("YA");
    Word tidak = stringToWord("TIDAK");
    if((idKicauan) > NEFF_Kicauan(lk)){ // cek apakah kicauan terdapat di list kicauan
        printf("\nKicauan tidak ditemukan.\n\n");
    }else{
        if(!isInListUtas(*lu,idKicauan)){
            idKicauan = idKicauan -1;
            if(isWordEqual(AUTHOR_KICAUAN(KICAUAN(lk,idKicauan)), Nama(user)) ){ // cek apakah kicauan milik user
                DATETIME currDatetime;
                AddressToUtas kicUtama = newNodeUtas(idKicauan+1, AUTHOR_KICAUAN(KICAUAN(lk,idKicauan)), DATETIME_KICAUAN(KICAUAN(lk,idKicauan)), TEXT_KICAUAN(KICAUAN(lk,idKicauan)));
                if(isFullListUtas(*lu)){
                    expandListUtas(lu,2);
                }
                insertLastUtas(lu, kicUtama);
                printf("\nUtas berhasil dibuat!\n");
                boolean selesai = false;
                AddressToUtas new;
                do{ // lakukan masukkan kicauan hingga di input TIDAK
                    printf("\nMasukkan kicauan:\n");
                    ADVWORD_takeBlank();
                    BacaDATETIME(&currDatetime);
                    new = newNodeUtas(1,Nama(user),currDatetime,currentWord);
                    sambungBelakangUtas(&kicUtama, new);
                    for(;;){ // cek input agar YA atau TIDAK
                        printf("\nApakah Anda ingin melanjutkan utas ini? (YA/TIDAK) ");
                        ADVWORD_takeBlank();
                        if(isWordEqual(currentWord,ya) || isWordEqual(currentWord,tidak)){
                            break;
                        }else{
                            printf("\nSilahkan ulangi input anda!\n\n");
                        }
                    }
                    if(isWordEqual(currentWord,tidak)){
                        selesai = true;
                    }
                }while(!selesai);
                printf("\nUtas selesai!\n\n");

            }else{
                printf("\nUtas ini bukan milik anda!\n\n");
            }
        }else{
            printf("\nKicauan ini sudah dibuat menjadi utas!\n\n");
        }
    }
}

void SAMBUNG_UTAS(ListUtas *lu, Pengguna user, int idUtas, int idx){
    if(isIdxEffUtas(*lu,idUtas-1)){ // cek apakah utas terdapat di list
        if(isWordEqual(AUTHOR_UTAS(ELMT_UTAS(*lu,idUtas-1)), Nama(user))){ // cek apakah utas dimiliki pengguna
            AddressToUtas kicUtama = ELMT_UTAS(*lu,idUtas-1);
            if(idx <= panjangUtas(kicUtama)){ //cek apakah terdapat index idx di utas
                printf("\nMasukkan kicauan:\n");
                ADVWORD_takeBlank();
                DATETIME currDatetime;
                BacaDATETIME(&currDatetime);
                AddressToUtas insert = newNodeUtas(idx, Nama(user), currDatetime, currentWord);
                sambungUtasAt(&kicUtama, insert, idx);
                printf("\nUtas berhasil disambung.\n\n");
            }else{
                printf("\nIndex terlalu tinggi!\n\n");
            }
        }else{
            printf("\nAnda tidak bisa menyambung utas ini!\n\n");
        }
    }else{
        printf("\nUtas tidak ditemukan!\n\n");
    }
}

void HAPUS_UTAS(ListUtas *lu, Pengguna user, int idUtas, int idx){
    if(idx != 0){ // cek apakah ingin menghapus selain kicauan utama
        if(isIdxEffUtas(*lu,idUtas-1)){ // cek apakah utas terdapat di list utas
            if(isWordEqual(AUTHOR_UTAS(ELMT_UTAS(*lu,idUtas-1)), Nama(user))){ // cek apakah utas dimiliki pengguna
                AddressToUtas kicUtama = ELMT_UTAS(*lu,idUtas-1);
                if(idx<panjangUtas(kicUtama)){ // cek apakah idx merupakan index di utas
                    hapusUtasAt(&kicUtama, idx);
                    printf("\nKicauan sambungan berhasil dihapus!\n");
                }else{
                    printf("\nKicauan sambungan dengan index %d tidak ditemukan pada utas!\n\n", idx);
                }
            }else{
                printf("\nAnda tidak bisa menghapus kicauan dalam utas ini!\n\n");
            }
        }else{
            printf("\nUtas tidak ditemukan!\n\n");
        }
    }else{
        printf("\nAnda tidak bisa menghapus kicauan utama!\n\n");
    }
}

void CETAK_UTAS(ListUtas lu, Friends graphTeman, ListPengguna lp, Pengguna user,int idUtas, ListDinKicauan lk){
    if(isIdxEffUtas(lu,idUtas-1)){ // cek apakah terdapat utas dengan idUtas
        int idxP = idxPengguna(lp, AUTHOR_UTAS(ELMT_UTAS(lu,idUtas-1)));
        Pengguna authorUtas = ELMT_LP(lp,idxP);
        if(Jenis(authorUtas)){
            if(isFriend(graphTeman, idxPengguna(lp, AUTHOR_UTAS(ELMT_UTAS(lu,idUtas-1))), idxPengguna(lp,Nama(user)))){ // cek apakah user dan author utas merupakan teman
                displayUtas(ELMT_UTAS(lu,idUtas-1));
            }else{
                printf("\nAkun yang membuat utas ini adalah akun privat! Ikuti dahulu akun ini untuk melihat utasnya!\n");
            }
        }else{
            displayUtas(ELMT_UTAS(lu,idUtas-1));
        }
        
    }else{
        printf("\nUtas tidak ditemukan!\n\n");
    }
}

