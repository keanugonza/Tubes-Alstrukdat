#include <stdio.h>
#include "../../ADT/pengguna.h"
#include "../../ADT/liststatikpengguna.h"
#include "../../ADT/wordmachine.h"
#include "../../ADT/charmachine.h"
#include "../../ADT/pcolor.h"

boolean isInt(Word HP){
    for (int i = 0; i< HP.Length; i++){
        if (HP.TabWord[i] < '0' || HP.TabWord[i] > '9'){
            return false;
        }
    }
    return true;
}

void gantiprofil(ListPengguna *LP, int *tempIDpengguna){
    Word listWeton[6];
    listWeton[0] = stringToWord("Pahing");
    listWeton[1] = stringToWord("Kliwon");
    listWeton[2] = stringToWord("Wage");
    listWeton[3] = stringToWord("Pon");
    listWeton[4] = stringToWord("Legi");
    listWeton[5] = stringToWord("");
    Word kosong = stringToWord("");
    printInfoPengguna(*LP, *tempIDpengguna);
    printf("\n\nMasukkan Bio Akun:\n");
    Word bio;
    ADVWORD_takeBlank();
    bio = currentWord;
    if (isWordEqual(bio, kosong) == false){
        while (bio.Length > 135){
            printf("\nBio anda terlalu panjang\n");
            printf("Masukkan Bio Akun:\n");
            ADVWORD_takeBlank();
            bio = currentWord;
        }
        ELMT_LP(*LP, *tempIDpengguna).bio = bio;
    }
    printf("\nMasukkan No HP:\n");
    Word hp;
    ADVWORD_takeBlank();
    hp = currentWord;
    if (isWordEqual(bio, kosong) == false){
        while (!(hp.Length < 20 && isInt(hp))){
            printf("No HP tidak valid. Masukkan lagi yuk!");
            printf("\nMasukkan No HP:\n");
            ADVWORD_takeBlank();
            hp = currentWord;
        }
        ELMT_LP(*LP, *tempIDpengguna).noHP = hp;
    }
    printf("\nMasukkan Weton:\n");
    Word weton;
    ADVWORD_takeBlank();
    weton = currentWord;
    if (isWordEqual(hp, kosong) == false){
        boolean statusWeton = false;
        while(statusWeton == false){
            if(isWordEqual(weton, listWeton[0]) || isWordEqual(weton, listWeton[1]) || isWordEqual(weton, listWeton[2]) || isWordEqual(weton, listWeton[3]) || isWordEqual(weton, listWeton[4]) || isWordEqual(weton, listWeton[5])){
                statusWeton = true;
            } else {
                printf("\nWeton anda tidak valid.\n");
                printf("Masukkan Weton:\n");
                ADVWORD_takeBlank();
            weton = currentWord;
            }
        }
        ELMT_LP(*LP, *tempIDpengguna).weton = weton;
        printf("\nProfil Anda sudah berhasil diperbarui!\n");
    }
}

void lihatprofil(ListPengguna *LP, Word val){
    if (isMember(*LP, val) == false){
        printf("Tidak ada pengguna dengan nama tersebut\n");
    } else {
        int i = idxPengguna(*LP, val);
        if (ELMT_LP(*LP,i).jenis == false){
            printInfoPengguna(*LP, i);
            printf("\n\n");
            displayProfil(*LP, i);
        } else {
            if (progIdPengguna == i){
                printInfoPengguna(*LP, i);
                printf("\n\n");
                displayProfil(*LP, i);
            } else {
                printf("\nWah, akun ");
                displayWord(val);
                printf(" diprivat nih. Ikuti dulu yuk untuk bisa melihat profil ");
                displayWord(val);
                printf("!\n");
            }
        }
    }
}

void aturjenisakun(ListPengguna *LP, int *tempIDpengguna){
    Word conf[2];
    conf[0] = stringToWord("YA");
    conf[1] = stringToWord("TIDAK");
    boolean type = ELMT_LP(*LP,*tempIDpengguna).jenis;
    if (type == false){
        printf("\nSaat ini, akun Anda adalah akun Publik. \nIngin mengubah ke akun Privat? \n(YA/TIDAK)\n");
        printf("\nKonfirmasi: \n");
        Word confirm;
        ADVWORD_takeBlank();
        confirm = currentWord;
        if (isWordEqual(confirm, conf[0])){
            ELMT_LP(*LP,*tempIDpengguna).jenis = true;
            printf("\nAkun anda sudah diubah menjadi akun Privat.\n");
        } else if (isWordEqual(confirm, conf[1])){
            printf("\nAkun anda tetap Publik.\n");
        }
        
    } else {
        printf("\nSaat ini, akun Anda adalah akun Privat. \nIngin mengubah ke akun Publik? \n(YA/TIDAK)\n");
        Word confirm;
        ADVWORD_takeBlank();
        confirm = currentWord;
        if (isWordEqual(confirm, conf[0])){
            ELMT_LP(*LP,*tempIDpengguna).jenis = false;
            printf("\nAkun anda sudah diubah menjadi akun Publik.\n");
        } else if (isWordEqual(confirm, conf[1])){
            printf("\nAkun anda tetap Privat.\n");
        }
    }
}

void ubahfotoprofil(ListPengguna *LP, int *tempIDpengguna){
    printf("Foto profil Anda saat ini adalah\n");
    displayProfil(*LP, *tempIDpengguna);
    printf("Masukkan foto profil yang baru\n");
    for(int i = 0; i < 5; i++){
        Word temp;
        ADVWORD_takeBlank();
        temp = currentWord;
        int k = 0;
        for(int j = 0; j < 5; j++){
            ELMT_FT((ELMT_LP(*LP, *tempIDpengguna).color), i, j) = charToWord(temp.TabWord[k]);
            k += 4;
        }
        k = 2;
        for(int j = 0; j < 5; j++){
            ELMT_FT((ELMT_LP(*LP, *tempIDpengguna).simbol), i, j) = charToWord(temp.TabWord[k]);
            k += 4;
        }
    }
}

