#include <stdio.h>
#include "..\..\ADT\kicauan.h"
#include "..\..\ADT\listdinKicauan.h"
#include "..\..\ADT\wordmachine.h"
#include "..\..\ADT\charmachine.h"
#include "..\..\ADT\boolean.h"
#include "..\..\ADT\boolean.h"
#include "..\..\ADT\friends.h"
#include "..\..\ADT\pengguna.h"
#include "..\..\ADT\liststatikpengguna.h"




boolean EndWord;
Word currentWord;

boolean isBlank(Word text){
    for(int i=0; i<text.Length; i++){
        if (text.TabWord[i] != ' '){
            return false;
        }
    }
    return true;
}

void KICAU(ListDinKicauan *l, Pengguna user){
    Word text;
    Kicauan k;

    printf("Masukkan kicauan:\n");
    STARTWORD_takeBlank();
    text = currentWord;
    if (isBlank(text)){
        printf("\nKicauan tidak boleh hanya berisi spasi!\n");
    } else{
        int id = listLengthKicauan(*l) + 1;
        int like =0;
        createKicauan(&k, id, text, like, user);
        insertKicauan(l,k);
        printf("\n");
        printf("Selamat! kicauan telah diterbitkan!\n");
        printf("Detil kicauan:\n");
        displayKicauan(k);
    }
}

void allKICAUAN(ListDinKicauan *l, Pengguna user, ListPengguna LP, Friends f){
    for (int i=listLengthKicauan(*l)-1; i >= 0; i--){
        Kicauan k = KICAUAN(*l,i);
        Word pemilikKicauan = AUTHOR_KICAUAN(k);
        int idx_pengguna = idxPengguna(LP, pemilikKicauan);
        if((isWordEqual(user.nama, pemilikKicauan)) || isFriend(f, user.id, idx_pengguna)){
            displayKicauan(k);
            printf("\n");
        }
    }
}

void SUKA_KICAUAN(ListDinKicauan *l, int idKICAU, Pengguna user, ListPengguna LP, Friends f){
    int idx = idKICAU -1;
    if(idx > listLengthKicauan(*l)-1 || idx<0){
        printf("Tidak ditemukan kicauan dengan ID = %d\n", idKICAU);
    } else{
        Kicauan k;
        k = KICAUAN(*l,idx);

        if (!PRIVAT_KICAUAN(k)){
            tambahLike(&k,1);
            setKicauan(l, k, idx);
            printf("Selamat! kicauan telah disukai!\n");
            printf("Detil kicauan:\n");
            displayKicauan(k);
        } else{
            Word authorLIKE = AUTHOR_KICAUAN(k);
            int idx_pengguna = idxPengguna(LP, authorLIKE);
            if(isWordEqual(user.nama, authorLIKE) || isFriend(f, user.id, idx_pengguna)){
                tambahLike(&k,1);
                setKicauan(l, k, idKICAU-1);
                printf("Selamat! kicauan telah disukai!\n");
                printf("Detil kicauan:\n");
                displayKicauan(k);
            } else{
                printf("Wah, kicauan tersebut dibuat oleh akun privat! Ikuti akun itu dulu ya\n");
            }
        }
    }
}

void UBAH_KICAUAN(ListDinKicauan *l, int idKICAU, Pengguna user){
    int idx = idKICAU -1;
    if(idx > listLengthKicauan(*l)-1 || idx<0){
        printf("Tidak ditemukan kicauan dengan ID = %d\n", idKICAU);
    } else{
        Kicauan k;
        k = KICAUAN(*l,idx);

        if(isWordEqual(AUTHOR_KICAUAN(k),user.nama)){
            printf("Masukkan kicauan baru:\n");
            ubahTeksKicauan(&k);
            setKicauan(l, k, idx);
            printf("\n");
            printf("Selamat! kicauan telah diterbitkan!\n");
            printf("Detil kicauan:\n");
            displayKicauan(k);

        } else{
            printf("Kicauan dengan ID = %d bukan milikmu!\n", idKICAU);
        }
    }
}

// int main(){
//     Word author;
//     ListDinKicauan l;
//     boolean privat;
//     int intprivat;
//     CreateListDinKicauan(&l,1);
//     int end;
//     boolean isEnd = false;


//     while (!isEnd){
//     printf("Masukan nama author: ");
//     STARTWORD_takeBlank();
//     author = currentWord;
//     scanf("%d", &intprivat);
//     if(intprivat==0){
//         privat = false;
//     } else{
//         privat = true;
//     }
//         KICAU(&l, privat, author);
//         printf("END??");
//         scanf("%d", &end);
//         if (end == 1){
//             isEnd = true;
//         }
//     }

//     allKICAUAN(&l,author);

//     SUKA_KICAUAN(&l,2,author);
//     allKICAUAN(&l,author);
// }
