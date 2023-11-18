#include <stdio.h>
#include "C:\Users\Keanu\Documents\GitHub\Tubes-Alstrukdat\ADT\kicauan.h"
#include "C:\Users\Keanu\Documents\GitHub\Tubes-Alstrukdat\ADT\listdinKicauan.h"
#include "C:\Users\Keanu\Documents\GitHub\Tubes-Alstrukdat\ADT\wordmachine.h"
#include "C:\Users\Keanu\Documents\GitHub\Tubes-Alstrukdat\ADT\charmachine.h"
#include "C:\Users\Keanu\Documents\GitHub\Tubes-Alstrukdat\ADT\boolean.h"
#include "C:\Users\Keanu\Documents\GitHub\Tubes-Alstrukdat\ADT\datetime.h"

#include "C:\Users\Keanu\Documents\GitHub\Tubes-Alstrukdat\ADT\kicauan.c"
#include "C:\Users\Keanu\Documents\GitHub\Tubes-Alstrukdat\ADT\listdinKicauan.c"
#include "C:\Users\Keanu\Documents\GitHub\Tubes-Alstrukdat\ADT\wordmachine.c"
#include "C:\Users\Keanu\Documents\GitHub\Tubes-Alstrukdat\ADT\charmachine.c"
#include "C:\Users\Keanu\Documents\GitHub\Tubes-Alstrukdat\ADT\datetime.c"




boolean EndWord;
Word currentWord;

// boolean isTeman(Word a, Word b){
//     return false;
// }

void KICAU(ListDinKicauan *l, boolean privat, Word author){
    Word text;
    Kicauan k;

    printf("Masukkan kicauan:\n");
    STARTWORD_takeBlank();
    text = currentWord;
    // if (isBlank(text)){
    //     printf("Kicauan tidak boleh hanya berisi spasi!\n");
    // } else{
        int id = listLengthKicauan(*l) + 1;
        int like =0;
        createKicauan(&k, id, text, like, author, privat);
        insertKicauan(l,k);
        printf("\n");
        printf("Selamat! kicauan telah diterbitkan!\n");
        printf("Detil kicauan:\n");
        displayKicauan(k);
    // }
}

void allKICAUAN(ListDinKicauan *l, Word author){
    for (int i=0; i < listLengthKicauan(*l); i++){
        Kicauan k = KICAUAN(*l,i);
        Word pemilikKicauan = AUTHOR_KICAUAN(k);
        if((isWordEqual(author, pemilikKicauan)) || isTeman(author,pemilikKicauan)){
            displayKicauan(k);
        }
        printf("\n");
    }
}

void SUKA_KICAUAN(ListDinKicauan *l, int idKICAU, Word author){
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
            if(isWordEqual(author, authorLIKE) || isTeman(author,authorLIKE)){
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

void UBAH_KICAUAN(ListDinKicauan *l, int idKICAU, Word author){
    int idx = idKICAU -1;
    if(idx > listLengthKicauan(*l)-1 || idx<0){
        printf("Tidak ditemukan kicauan dengan ID = %d\n", idKICAU);
    } else{
        Kicauan k;
        k = KICAUAN(*l,idx);

        if(isWordEqual(AUTHOR_KICAUAN(k),author)){
            printf("Masukkan kicauan baru:\n");
            ubahTeksKicauan(&k);
            setKicauan(l, k, idx);
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
