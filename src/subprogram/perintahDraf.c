#include <stdio.h>
#include "..\..\ADT\kicauan.h"
#include "..\..\ADT\stackDraf.h"
#include "..\..\ADT\wordmachine.h"
#include "..\..\ADT\charmachine.h"
#include "..\..\ADT\boolean.h"
#include "..\..\ADT\datetime.h"
#include "..\..\ADT\listdinKicauan.h"
#include "..\..\ADT\pengguna.h"


void SIMPAN(StackDraf*s, Word text){
    Draf d;
    createDraf(&d, text);
    pushDraf(s,d);
    printf("Draf telah berhasil disimpan!\n");
}

void TERBIT(ListDinKicauan *l, Word text, Pengguna user){
    Kicauan k;
    int id = listLengthKicauan(*l) + 1;
    int like =0;
    createKicauan(&k, id, text, like, user);
    insertKicauan(l,k);
    printf("\n");
    printf("Selamat! kicauan telah diterbitkan!\n");
    printf("Detil kicauan:\n");
    displayKicauan(k);
}


void BUAT_DRAF(StackDraf *s, ListDinKicauan *l, Pengguna user){
    Word text;
    Word WORD_HAPUS = stringToWord("HAPUS");
    Word WORD_SIMPAN = stringToWord("SIMPAN");
    Word WORD_TERBIT = stringToWord("TERBIT");

    printf("Masukkan draf:\n");
    STARTWORD_takeBlank();
    text = currentWord;
    
    printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?\n");
    if(isWordEqual(currentWord, WORD_HAPUS)){ //HAPUS
        printf("Draf telah berhasil dihapus!\n");
    } else if(isWordEqual(currentWord, WORD_SIMPAN)){ //SIMPAN
        SIMPAN(s, text);
    } else if (isWordEqual(currentWord, WORD_TERBIT)){ //TERBIT
        TERBIT(l, text, user);
    }
}

void UBAH(StackDraf *s, ListDinKicauan *l, Pengguna user){
    printf("Masukkan draf yang baru:\n");
    BUAT_DRAF( s, l, user);
}

void LIHAT_DRAF(StackDraf *s, ListDinKicauan *l, Pengguna user){
    Word WORD_UBAH = stringToWord("UBAH");
    Word WORD_HAPUS = stringToWord("HAPUS");
    Word WORD_TERBIT = stringToWord("TERBIT");
    if (isEmptyDraf(*s)){
        printf("Yah, anda belum memiliki draf apapun! Buat dulu ya :D\n");
    } else{
        printf("Ini draf terakhir anda:\n");
        Draf d;
        popDraf(s, &d);
        displayDraf(d);
        printf("\nApakah anda ingin mengubah, menghapus, atau menerbitkan draf ini? (KEMBALI jika ingin kembali)\n");
        if (isWordEqual(currentWord, WORD_UBAH)){//ubah
            UBAH(s,l,user);
        } else if (isWordEqual(currentWord, WORD_HAPUS)){ // hapus
            printf("Draf telah berhasil dihapus!\n");
        } else if (isWordEqual(currentWord, WORD_TERBIT)){ //Terbit
            TERBIT(l,TEXT_DRAF(d),user);
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



