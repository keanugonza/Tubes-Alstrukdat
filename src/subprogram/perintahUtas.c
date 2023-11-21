#include "../../ADT/utas.h"
#include "../../ADT/ListDinOfUtas.h"
#include "../../ADT/listdinKicauan.h"
#include "../../ADT/pengguna.h"
#include <stdio.h>


void UTAS(){

}

void SAMBUNG_UTAS(ListUtas *lu, ListDinKicauan lk, Pengguna user, int idUtas, int idx){
    if(isInListUtas(*lu, idUtas)){
        if((idx+1) > NEFF_Kicauan(lk)){
            printf("Kicauan tidak ditemukan.");
        }else{
            if(isWordEqual(AUTHOR_KICAUAN(KICAUAN(lk,idx)), Nama(user)) ){
                DATETIME currDatetime;
                BacaDATETIME(&currDatetime);
                AddressToUtas new = newNode(idx, AUTHOR_KICAUAN(KICAUAN(lk,idx)), currDatetime, TEXT_KICAUAN(KICAUAN(lk,idx)));
                if(isFullListUtas(*lu)){
                    expandListUtas(lu,2);
                }
                insertLastUtas(lu, new);
                printf("Utas berhasil dibuat!\n");
                printf("\n");
                printf("\n");
                boolean selesai = false;
                printf("Masukkan kicauan:\n");

                printf("Apakah Anda ingin melanjutkan utas ini? (YA/TIDAK)\n");
                
                if(isWordEqual(currentWord, "TIDAK")){
                    selesai = false;
                }else if(!isWordEqual(currentWord, "YA") || !isWordEqual(currentWord,"TIDAK")){
                    
                }
                while(!selesai){
                    
                }
                printf("Masukkan kicauan:\n");

                


            }else{
                printf("Utas ini bukan milik anda!\n");
            }
        }
    }else{
        printf("Utas tidak ditemukan!\n");
    }
}

void HAPUS_UTAS();

void CETAK_UTAS();

