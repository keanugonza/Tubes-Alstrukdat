#include <stdio.h>
#include "..\..\ADT\pengguna.h"
#include "..\..\ADT\liststatikpengguna.h"
#include "..\..\ADT\wordmachine.h"
#include "..\..\ADT\charmachine.h"

gantiprofil(ListPengguna *LP, int *tempIDpengguna){
    Word listWeton[5];
    listWeton[0] = stringToWord("Pahing");
    listWeton[1] = stringToWord("Kliwon");
    listWeton[2] = stringToWord("Wage");
    listWeton[3] = stringToWord("Pon");
    listWeton[4] = stringToWord("Legi");
    Word kosong;
    kosong.TabWord[0] = "";
    kosong.Length = 1;
    printInfoPengguna(*LP, tempIDpengguna);
    printf("\nMasukkan Bio Akun:\n");
    Word bio;
    STARTWORD_takeBlank();
    bio = currentWord;
    ELMT_LP(*LP, *tempIDpengguna).bio = bio;
    printf("\nMasukkan No HP:\n");
    Word hp;
    STARTWORD_takeBlank();
    hp = currentWord;
    int i = 0;
    boolean state = false;
    while (state = false){
        boolean status = true;
        while(i < hp.Length && status == true){
            if (hp.TabWord[i] != '0' || hp.TabWord[i] != '1' || hp.TabWord[i] != '2' || hp.TabWord[i] != '3' || hp.TabWord[i] != '4' || hp.TabWord[i] != '5'|| hp.TabWord[i] != '6'|| hp.TabWord[i] != '7'|| hp.TabWord[i] != '8'|| hp.TabWord[i] != '9' ){
                status = false;
            }
            else
            {
                i++;
            }
        }
        if (status == true){
            state = true;
        } else {
            printf("\nNo HP tidak valid. Masukkan lagi yuk!\n");
            STARTWORD_takeBlank();
            hp = currentWord;
        }
    }
    printf("\nMasukkan Weton:\n");
    Word weton;
    STARTWORD_takeBlank();
    weton = currentWord;
    boolean statusWeton = false;
    while(statusWeton == false){
        if(isWordEqual(weton, listWeton[0]) || isWordEqual(weton, listWeton[1]) || isWordEqual(weton, listWeton[2]) || isWordEqual(weton, listWeton[3]) || isWordEqual(weton, listWeton[4]) || isWordEqual(weton, kosong)){
            statusWeton = true;
        } else {
            printf("\nWeton anda tidak valid.\n");
            STARTWORD_takeBlank();
        weton = currentWord;
        }
    }
    printf("\nProfil Anda sudah berhasil diperbarui!\n");
}

lihatprofil(ListPengguna *LP, Word val){
    int i = idxPengguna(*LP, val);
    if (ELMT_LP(*LP,i).jenis == false){
        printInfoPengguna(*LP, i);
        displayProfil(*LP, i);
    }
    else 
    {
        printf("\nWah, akun %s diprivat nih. Ikuti dulu yuk untuk bisa melihat profil %s!\n", val, val);
    }
}

aturjenisakun(ListPengguna *LP, int *tempIDpengguna){
    Word conf[2];
    conf[0] = stringToWord("YA");
    conf[1] = stringToWord("TIDAK");
    boolean type = ELMT_LP(*LP,*tempIDpengguna).jenis;
    if (type == false){
        printf("\nSaat ini, akun Anda adalah akun Publik. \nIngin mengubah ke akun Privat? \n(YA/TIDAK)\n");
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

ubahfotoprofil(ListPengguna *LP, int *tempIDpengguna){
    printf("Foto profil Anda saat ini adalah\n");
    displayProfil(*LP, *tempIDpengguna);
    printf("Masukkan foto profil yang baru\n");
    for(int i = 0; i < 5; i++){
        Word temp;
        ADVWORD_takeBlank();
        temp = currentWord;
        int k = 0;
        for(int j = 0; j < 5; j++){
            ELMT_FT((ELMT_LP(*LP, *tempIDpengguna).color), i, j) = stringToWord(temp.TabWord[k]);
            k += 4;
        }
        k = 2;
        for(int j = 0; j < 5; j++){
            ELMT_FT((ELMT_LP(*LP, *tempIDpengguna).simbol), i, j) = stringToWord(temp.TabWord[k]);
            k += 4;
        }
    }
}

