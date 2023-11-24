#include "subprogram/data.h"
#include <stdio.h>
#include "subprogram/perintahDraf.c"
#include "subprogram/perintahKicauan.c"
#include "subprogram/perintahpengguna.c"
#include "subprogram/perintahPermintaanPertemanan.c"
#include "subprogram/perintahprofil.c"
#include "subprogram/perintahTeman.c"
#include "subprogram/perintahUtas.c"
#include "subprogram/perintahBalasan.c"
#include "subprogram/inisialisasi.c"
#include "../ADT/balasan.c"
#include "../ADT/charmachine.c"
#include "../ADT/datetime.c"
#include "../ADT/foto.c"
#include "../ADT/friends.c"
#include "../ADT/kicauan.c"
#include "../ADT/listdinKicauan.c"
#include "../ADT/ListDinOfUtas.c"
#include "../ADT/liststatikpengguna.c"
#include "../ADT/pengguna.c"
#include "../ADT/prioqueue.c"
#include "../ADT/stackDraf.c"
#include "../ADT/utas.c"
#include "../ADT/wordmachine.c"
#include "../ADT/pcolor.c"

int main(){
    pesanpembuka();
    progIdPengguna = -1;
    for(int i=0; i<20; i ++){
        CreateStackDraf(&progStackDraf[i]);
    }
    for(int j=0; j<20; j ++){
        createFriendReqList(&progQueue[j]);
    }
    createListPengguna(&progListPengguna);
    CreateListDinKicauan(&progListDinKicau,1);
    CreateListDinUtas(&progListDinUtas,1);
    createPertemanan(&progFriends);

    Word perintah[3];
    printf(">> ");
    STARTWORD();
    perintah[0] = currentWord;
    while(!(isWordEqual(perintah[0],stringToWord("TUTUP_PROGRAM")))){
        if(isWordEqual(perintah[0],stringToWord("DAFTAR"))){
            if(progIdPengguna != -1){
                printf("\nAnda harus keluar dahulu.\n");
            } else{
                daftar(&progListPengguna);
            }
        } 
        else if (isWordEqual(perintah[0],stringToWord("MASUK"))){
            if(progIdPengguna == -1){
                printf("\nAnda belum masuk, masuk terlebih dahulu!\n");
            } else{
                masuk(&progListPengguna, &progIdPengguna);
            }
        } 
        else if (isWordEqual(perintah[0],stringToWord("GANTI_PROFIL"))){
            if(progIdPengguna == -1){
                printf("\nAnda belum masuk, masuk terlebih dahulu!\n");
            } else{
                gantiprofil(&progListPengguna, &progIdPengguna);
            }
        } 
        else if (isWordEqual(perintah[0],stringToWord("LIHAT_PROFIL"))){
            if(progIdPengguna == -1){
                printf("\nAnda belum masuk, masuk terlebih dahulu!\n");
            } else{
                ADVWORD();
                perintah[1] = currentWord;
                lihatprofil(&progListPengguna, perintah[1]);
            }
            
        } 
        else if (isWordEqual(perintah[0],stringToWord("ATUR_JENIS_AKUN"))){
            if(progIdPengguna == -1){
                printf("\nAnda belum masuk, masuk terlebih dahulu!\n");
            } else{
                aturjenisakun(&progListPengguna, &progIdPengguna);
            }
        } 
        else if (isWordEqual(perintah[0],stringToWord("UBAH_FOTO_PROFIL"))){
            if(progIdPengguna == -1){
                printf("\nAnda belum masuk, masuk terlebih dahulu!\n");
            } else{
                ubahfotoprofil(&progListPengguna, &progIdPengguna);
            }
        } 
        else if (isWordEqual(perintah[0],stringToWord("DAFTAR_TEMAN"))){
            if(progIdPengguna == -1){
                printf("\nAnda belum masuk, masuk terlebih dahulu!\n");
            } else{
                Pengguna user = ELMT_LP(progListPengguna, progIdPengguna);
                DAFTAR_TEMAN(user, progListPengguna, progFriends);
            }
        } 
        else if (isWordEqual(perintah[0],stringToWord("HAPUS_TEMAN"))){
            if(progIdPengguna == -1){
                printf("\nAnda belum masuk, masuk terlebih dahulu!\n");
            } else{
                Pengguna user = ELMT_LP(progListPengguna, progIdPengguna);
                HAPUS_TEMAN(user, progListPengguna, &progFriends);
            }
        } 
        else if (isWordEqual(perintah[0],stringToWord("TAMBAH_TEMAN"))){
            if(progIdPengguna == -1){
                printf("\nAnda belum masuk, masuk terlebih dahulu!\n");
            } else{
                Pengguna user = ELMT_LP(progListPengguna, progIdPengguna);
                addFriendReq(user, progFriends, progListPengguna);
            }
        } 
        else if (isWordEqual(perintah[0],stringToWord("DAFTAR_PERMINTAAN_PERTEMANAN"))){
            if(progIdPengguna == -1){
                printf("\nAnda belum masuk, masuk terlebih dahulu!\n");
            } else{
            displayFriendReqList(progQueue[progIdPengguna]);
            }
        } 
        else if (isWordEqual(perintah[0],stringToWord("SETUJUI_PERTEMANAN"))){
            if(progIdPengguna == -1){
                printf("\nAnda belum masuk, masuk terlebih dahulu!\n");
            } else{
                Pengguna user = ELMT_LP(progListPengguna, progIdPengguna);
                accFriendReq(user, &progFriends,progListPengguna);
            }
        } 
        else if (isWordEqual(perintah[0],stringToWord("KICAU"))){
            if(progIdPengguna == -1){
                printf("\nAnda belum masuk, masuk terlebih dahulu!\n");
            } else{
                Pengguna user = ELMT_LP(progListPengguna, progIdPengguna);
                printf("\n");
                KICAU(&progListDinKicau, user);
            }
        } 
        else if (isWordEqual(perintah[0],stringToWord("KICAUAN"))){
            if(progIdPengguna == -1){
                printf("\nAnda belum masuk, masuk terlebih dahulu!\n");
            } else{
                Pengguna user = ELMT_LP(progListPengguna, progIdPengguna);
                allKICAUAN(&progListDinKicau, user, progListPengguna,progFriends);
            }
        } 
        else if (isWordEqual(perintah[0],stringToWord("SUKA_KICAUAN"))){
            if(progIdPengguna == -1){
                printf("\nAnda belum masuk, masuk terlebih dahulu!\n");
            } else{
                Pengguna user = ELMT_LP(progListPengguna, progIdPengguna);
                ADVWORD();
                perintah[1] = currentWord;
                int idKicau = wordToInt(perintah[1]);
                SUKA_KICAUAN(&progListDinKicau, idKicau,user,progListPengguna,progFriends);
            }
        } 
        else if (isWordEqual(perintah[0],stringToWord("UBAH_KICAUAN"))){
            if(progIdPengguna == -1){
                printf("\nAnda belum masuk, masuk terlebih dahulu!\n");
            } else{
                Pengguna user = ELMT_LP(progListPengguna, progIdPengguna);
                ADVWORD();
                perintah[1] = currentWord;
                int idKicau = wordToInt(perintah[1]);
                UBAH_KICAUAN(&progListDinKicau, idKicau, user);
            }
        } 
        else if (isWordEqual(perintah[0],stringToWord("BALAS"))){
            if(progIdPengguna == -1){
                printf("\nAnda belum masuk, masuk terlebih dahulu!\n");
            } else{
                ADVWORD();
                perintah[1] = currentWord;
                int idKicau = wordToInt(perintah[1]);
                ADVWORD();
                perintah[2] = currentWord;
                int idBalas = wordToInt(perintah[2]);
                BALAS(idKicau, idBalas, progListPengguna, &progListDinKicau, progIdPengguna, progFriends);
            } 
        } 
        else if (isWordEqual(perintah[0],stringToWord("BALASAN"))){
            if(progIdPengguna == -1){
                printf("\nAnda belum masuk, masuk terlebih dahulu!\n");
            } else{
                ADVWORD();
                perintah[1] = currentWord;
                int idKicau = wordToInt(perintah[1]);
                BALASAN(progIdPengguna, idKicau, progListDinKicau, progListPengguna, progFriends);
            }
        } 
        else if (isWordEqual(perintah[0],stringToWord("HAPUS_BALASAN"))){
            if(progIdPengguna == -1){
                printf("\nAnda belum masuk, masuk terlebih dahulu!\n");
            } else{
                ADVWORD();
                perintah[1] = currentWord;
                int idKicau = wordToInt(perintah[1]);
                ADVWORD();
                perintah[2] = currentWord;
                int idHapus = wordToInt(perintah[2]);
                HAPUSBALAS(idKicau, idHapus, progListPengguna, &progListDinKicau, progIdPengguna);
            }
        } 
        else if (isWordEqual(perintah[0],stringToWord("BUAT_DRAF"))){
            if(progIdPengguna == -1){
                printf("\nAnda belum masuk, masuk terlebih dahulu!\n");
            } else{
                Pengguna user = ELMT_LP(progListPengguna, progIdPengguna);
                BUAT_DRAF(&progStackDraf[progIdPengguna], &progListDinKicau, user);
            }
        } 
        else if (isWordEqual(perintah[0],stringToWord("LIHAT_DRAF"))){
            if(progIdPengguna == -1){
                printf("\nAnda belum masuk, masuk terlebih dahulu!\n");
            } else{
                Pengguna user = ELMT_LP(progListPengguna, progIdPengguna);
                LIHAT_DRAF(&progStackDraf[progIdPengguna], &progListDinKicau, user);
            }
        } 
        else if (isWordEqual(perintah[0],stringToWord("UTAS"))){
            if(progIdPengguna == -1){
                printf("\nAnda belum masuk, masuk terlebih dahulu!\n");
            } else{
                Pengguna user = ELMT_LP(progListPengguna, progIdPengguna);
                ADVWORD();
                perintah[1] = currentWord;
                int idKicau = wordToInt(perintah[1]);
                UTAS(&progListDinUtas, progListDinKicau, user, idKicau);
            }
        } 
        else if (isWordEqual(perintah[0],stringToWord("SAMBUNG_UTAS"))){
            if(progIdPengguna == -1){
                printf("\nAnda belum masuk, masuk terlebih dahulu!\n");
            } else{
                Pengguna user = ELMT_LP(progListPengguna, progIdPengguna);
                ADVWORD();
                perintah[1] = currentWord;
                int idUtas = wordToInt(perintah[1]);
                ADVWORD();
                perintah[2] = currentWord;
                int idx = wordToInt(perintah[2]);
                SAMBUNG_UTAS(&progListDinUtas, user, idUtas, idx);
            }
        } 
        else if (isWordEqual(perintah[0],stringToWord("HAPUS_UTAS"))){
            if(progIdPengguna == -1){
                printf("\nAnda belum masuk, masuk terlebih dahulu!\n");
            } else{
                Pengguna user = ELMT_LP(progListPengguna, progIdPengguna);
                ADVWORD();
                perintah[1] = currentWord;
                int idUtas = wordToInt(perintah[1]);
                ADVWORD();
                perintah[2] = currentWord;
                int idx = wordToInt(perintah[2]);
                HAPUS_UTAS(&progListDinUtas,user,idUtas,idx);
            }
        } 
        else if (isWordEqual(perintah[0],stringToWord("CETAK_UTAS"))){
            if(progIdPengguna == -1){
                printf("\nAnda belum masuk, masuk terlebih dahulu!\n");
            } else{
                Pengguna user = ELMT_LP(progListPengguna, progIdPengguna);
                ADVWORD();
                perintah[1] = currentWord;
                int idUtas = wordToInt(perintah[1]);
                CETAK_UTAS(progListDinUtas, progFriends, progListPengguna,user,idUtas, progListDinKicau);
            }
        } 
        else if (isWordEqual(perintah[0],stringToWord("KELUAR"))){
            keluar(&progIdPengguna);
        } 
        else if (isWordEqual(perintah[0],stringToWord("SIMPAN"))){
            // SIMPAN();
        } 
        else if (isWordEqual(perintah[0],stringToWord("MUAT"))){
            // MUAT();
        } else{
            printf("\nTidak ada perintah tersebut!\n");
        }
        // displayWord(perintah[0]);
        printf("\n");
        printf(">> ");
        ADVWORD();
        perintah[0] = currentWord;
    }
    printf("\nAnda telah keluar dari program BurBir.\nSampai jumpa di penjelajahan berikutnya.\n\n");
}
