#include <stdio.h>
#include "..\..\ADT\pengguna.h"
#include "..\..\ADT\liststatikpengguna.h"
#include "..\..\ADT\wordmachine.h"
#include "..\..\ADT\charmachine.h"

void daftar(ListPengguna *LP){
    printf("\nMasukkan nama:\n");
    STARTWORD_takeBlank();
    Word nama = currentWord;
    while(isMember(*LP, nama) == true){
        printf("\nWah, sayang sekali nama tersebut telah diambil.\n");
        printf("Masukkan nama:\n");
        STARTWORD_takeBlank();
        nama = currentWord;
    }
    printf("\nMasukkan kata sandi:\n");
    STARTWORD_takeBlank();
    Word sandi = currentWord;
    while(sandi.Length > 20){
        printf("\nWah, kata sandi anda terlalu panjang.\n");
        printf("Masukkan kata sandi:\n");
        STARTWORD_takeBlank();
        sandi = currentWord;
    }
    Word kosong;
    kosong.TabWord[0] = " ";
    kosong.Length = 1;
    Pengguna User;
    int id = lenListPengguna(*LP);
    boolean privat = false;
    // createPengguna(&User, id, nama, sandi, kosong, kosong, kosong, privat, foto);
    insertLastPengguna(&LP, User);
}

void masuk(){
    printf("\nMasukkan nama:\n");
    STARTWORD_takeBlank();
    Word nama = currentWord;
    while(isMember(*LP, nama) == true){
        printf("\nWah, sayang sekali nama tersebut telah diambil.\n");
        printf("Masukkan nama:\n");
        STARTWORD_takeBlank();
        nama = currentWord;
    }
    prin
}

void gantiprofil();
