#include <stdio.h>
#include "..\..\ADT\pengguna.h"
#include "..\..\ADT\liststatikpengguna.h"
#include "..\..\ADT\wordmachine.h"
#include "..\..\ADT\charmachine.h"
#include "..\..\ADT\foto.h"


void masuk(ListPengguna *LP, int *tempIDpengguna){
    if (*tempIDpengguna != -1)
    {
        printf("\nWah Anda sudah masuk. Keluar dulu yuk!\n");
    } 
    else
    {
        printf("\nMasukkan nama:\n");
    STARTWORD_takeBlank();
    Word nama = currentWord;
    while(isMember(*LP, nama) == false){
        printf("\nWah, nama yang Anda cari tidak ada. Masukkan nama lain!\n");
        printf("Masukkan nama:\n");
        STARTWORD_takeBlank();
        nama = currentWord;
    }
    *tempIDpengguna = idxPengguna(*LP, nama);
    printf("\nMasukkan kata sandi:\n");
    STARTWORD_takeBlank();
    Word sandi = currentWord;
    while(isWordEqual(ELMT_LP(*LP,idxPengguna(*LP, nama)).kata_sandi, sandi) == false){
        printf("\nWah, kata sandi yang Anda masukkan belum tepat. Periksa kembali kata sandi Anda!\n");
        printf("Masukkan nama:\n");
        STARTWORD_takeBlank();
        sandi = currentWord;
    }
    printf("\nAnda telah berhasil masuk dengan nama pengguna Tuan Bri. Mari menjelajahi BurBir bersama Ande-Ande Lumut!\n");
    }
}

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
    Word kosong = stringToWord("");
    Pengguna User;
    int id = lenListPengguna(*LP);
    boolean privat = false;
    Matrix formatcolor, formatsimbol;
    createMatrixColor(&formatcolor);
    createMatrixSimbol(&formatsimbol);
    createPengguna(&User, id, nama, sandi, kosong, kosong, kosong, privat, formatcolor, formatsimbol);
    insertLastPengguna(LP, User);
}

void keluar(int *tempIDpengguna){
    if (*tempIDpengguna == -1)
    {
        printf("\nAnda belum login! Masuk terlebih dahulu\n");
    } 
    else 
    {
        *tempIDpengguna = -1;
        printf("\nAnda berhasil logout. Sampai jumpa di pertemuan berikutnya!\n");
    }
}
