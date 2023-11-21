#include <stdio.h>
#include "..\..\ADT\kicauan.h"
#include "..\..\ADT\stackDraf.h"
#include "..\..\ADT\wordmachine.h"
#include "..\..\ADT\charmachine.h"
#include "..\..\ADT\boolean.h"
#include "..\..\ADT\datetime.h"
#include "..\..\ADT\listdinKicauan.h"
#include "..\..\ADT\stackDraf.c"



void SIMPAN(StackDraf*s, Word text){
    Draf d;
    createDraf(&d, text);
    pushDraf(s,d);
    printf("Draf telah berhasil disimpan!\n");
}

void TERBIT(ListDinKicauan *l, Word text, boolean privat, Word author){
    Kicauan k;
    int id = listLengthKicauan(*l) + 1;
    int like =0;
    createKicauan(&k, id, text, like, author, privat);
    insertKicauan(l,k);
    printf("\n");
    printf("Selamat! kicauan telah diterbitkan!\n");
    printf("Detil kicauan:\n");
    displayKicauan(k);
}


void BUAT_DRAF(StackDraf *s, ListDinKicauan *l, boolean privat, Word author){
    Word text;
    int pilihan;
    // printf("Masukkan draf:\n");
    STARTWORD_takeBlank();
    text = currentWord;
    
    printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?\n");
    scanf("%d", &pilihan);
    if(pilihan == 1){ //HAPUS
        printf("Draf telah berhasil dihapus!\n");
    } else if(pilihan == 2){ //SIMPAN
        SIMPAN(s, text);
    } else if (pilihan ==3){ //TERBIT
        TERBIT(l, text, privat, author);
    }
}

void UBAH(StackDraf *s, ListDinKicauan *l, boolean privat, Word author){
    printf("Masukkan draf yang baru:\n");
    BUAT_DRAF( s, l, privat, author);
}

void LIHAT_DRAF(StackDraf *s, ListDinKicauan *l, boolean privat, Word author){
    int pilihan;
    if (isEmptyDraf(*s)){
        printf("Yah, anda belum memiliki draf apapun! Buat dulu ya :D\n");
    } else{
        printf("Ini draf terakhir anda:\n");
        Draf d;
        popDraf(s, &d);
        displayDraf(d);
        printf("\nApakah anda ingin mengubah, menghapus, atau menerbitkan draf ini? (KEMBALI jika ingin kembali)\n");
        scanf("%d", &pilihan);
        if (pilihan == 1){//ubah
            UBAH(s,l,privat,author);
        } else if (pilihan == 2){ // hapus
            printf("Draf telah berhasil dihapus!\n");
        } else if (pilihan == 3){ //Terbit
            TERBIT(l,TEXT_DRAF(d),privat,author);
        }
    }
}



// int main(){
//     StackDraf s;
//     CreateStackDraf(&s);
//     ListDinKicauan l;
//     CreateListDinKicauan(&l, 2);
//     boolean privat = false;
//     Word author;

//     author.Length = 5;
//     author.TabWord[0] = 'G';
//     author.TabWord[1] = 'O';
//     author.TabWord[2] = 'N';
//     author.TabWord[3] = 'Z';
//     author.TabWord[4] = 'A';

//     displayWord(author);
//     BUAT_DRAF(&s,&l,privat,author); //terbit
//     BUAT_DRAF(&s,&l,privat,author); //simpan
//     BUAT_DRAF(&s,&l,privat,author); //hapus
//     BUAT_DRAF(&s,&l,privat,author); //simpan
//     LIHAT_DRAF(&s,&l,privat,author); //hapus
//     LIHAT_DRAF(&s,&l,privat,author); //ubah
//     LIHAT_DRAF(&s,&l,privat,author); //terbit
//     LIHAT_DRAF(&s,&l,privat,author); //cek
// }


