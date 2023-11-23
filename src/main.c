#include "subprogram/data.h"
#include "..\ADT\wordmachine.h"


int main(){
    Word perintah[3];
    ADVWORD();
    perintah[0] = currentWord;
    while(!IsWordEqual(perintah[0],stringToWord("TUTUP_PROGRAM"))){
        if(isWordEqual(perintah[0],stringToWord("DAFTAR"))){
            daftar(&progListPengguna);
        } 
        else if (isWordEqual(perintah[0],stringToWord("MASUK"))){
            masuk(&progListPengguna, &progIdPengguna);
        } 
        else if (isWordEqual(perintah[0],stringToWord("GANTI_PROFIL"))){
            gantiprofil(&progListPengguna, &progIdPengguna);
        } 
        else if (isWordEqual(perintah[0],stringToWord("LIHAT_PROFIL"))){
            ADVWORD();
            perintah[1] = currentWord;
            lihatprofil(&progListPengguna, perintah[1]);
        } 
        else if (isWordEqual(perintah[0],stringToWord("ATUR_JENIS_AKUN"))){
            aturjenisakun(&progListPengguna, &progIdPengguna);
        } 
        else if (isWordEqual(perintah[0],stringToWord("UBAH_FOTO_PROFIL"))){
            ubahfotoprofil(&progListPengguna, &progIdPengguna);
        } 
        else if (isWordEqual(perintah[0],stringToWord("DAFTAR_TEMAN"))){
            Pengguna user = ELMT_LP(progListPengguna, progIdPengguna);
            DAFTAR_TEMAN(user, progListPengguna, progFriends);
        } 
        else if (isWordEqual(perintah[0],stringToWord("HAPUS_TEMAN"))){
            Pengguna user = ELMT_LP(progListPengguna, progIdPengguna);
            HAPUS_TEMAN(user, progListPengguna, progFriends);
        } 
        else if (isWordEqual(perintah[0],stringToWord("TAMBAH_TEMAN"))){
            addFriendReq(&progQueue[progIdPengguna]);
        } 
        else if (isWordEqual(perintah[0],stringToWord("DAFTAR_PERMINTAAN_TEMAN"))){
            displayFriendReqList(progQueue[progIdPengguna]);
        } 
        else if (isWordEqual(perintah[0],stringToWord("SETUJUI_PERTEMANAN"))){
            accFriendReq(&progQueue[progIdPengguna]);
        } 
        else if (isWordEqual(perintah[0],stringToWord("KICAU"))){
            Pengguna user = ELMT_LP(progListPengguna, progIdPengguna);
            KICAU(&progListDinKicau, user);
        } 
        else if (isWordEqual(perintah[0],stringToWord("KICAUAN"))){
            Pengguna user = ELMT_LP(progListPengguna, progIdPengguna);
            allKICAUAN(&progListDinKicau, user, progListPengguna,progFriends);
        } 
        else if (isWordEqual(perintah[0],stringToWord("SUKA_KICAUAN"))){
            Pengguna user = ELMT_LP(progListPengguna, progIdPengguna);
            ADVWORD();
            perintah[1] = currentWord;
            int idKicau = wordToInt(perintah[1]);
            SUKA_KICAUAN(&progListDinKicau, idKicau,user,progListPengguna,progFriends);
        } 
        else if (isWordEqual(perintah[0],stringToWord("UBAH_KICAUAN"))){
            Pengguna user = ELMT_LP(progListPengguna, progIdPengguna);
            ADVWORD();
            perintah[1] = currentWord;
            int idKicau = wordToInt(perintah[1]);
            UBAH_KICAUAN(&progListDinKicau, idKicau, user);
        } 
        else if (isWordEqual(perintah[0],stringToWord("BALAS"))){
            ADVWORD();
            perintah[1] = currentWord;
            ADVWORD();
            perintah[2] = currentWord;
            BALAS();
        } 
        else if (isWordEqual(perintah[0],stringToWord("BALASAN"))){
            ADVWORD();
            perintah[1] = currentWord;
            BALASAN();
        } 
        else if (isWordEqual(perintah[0],stringToWord("HAPUS_BALASAN"))){
            ADVWORD();
            perintah[1] = currentWord;
            ADVWORD();
            perintah[2] = currentWord;
            HAPUS_BALASAN();
        } 
        else if (isWordEqual(perintah[0],stringToWord("BUAT_DRAF"))){
            Pengguna user = ELMT_LP(progListPengguna, progIdPengguna);
            BUAT_DRAF(&progStackDraf[progIdPengguna], &progListDinKicau, user);
        } 
        else if (isWordEqual(perintah[0],stringToWord("LIHAT_DRAF"))){
            Pengguna user = ELMT_LP(progListPengguna, progIdPengguna);
            LIHAT_DRAF(&progStackDraf[progIdPengguna], &progListDinKicau, user);
        } 
        else if (isWordEqual(perintah[0],stringToWord("UTAS"))){
            Pengguna user = ELMT_LP(progListPengguna, progIdPengguna);
            ADVWORD();
            perintah[1] = currentWord;
            int idKicau = wordToInt(perintah[1]);
            UTAS(&progUtas, progListDinKicau, user, idKicau);
        } 
        else if (isWordEqual(perintah[0],stringToWord("SAMBUNG_UTAS"))){
            Pengguna user = ELMT_LP(progListPengguna, progIdPengguna);
            ADVWORD();
            perintah[1] = currentWord;
            int idUtas = wordToInt(perintah[1]);
            ADVWORD();
            perintah[2] = currentWord;
            int idx = wordToInt(perintah[2]);
            SAMBUNG_UTAS(progListDinUtas, user, idUtas, idx);
        } 
        else if (isWordEqual(perintah[0],stringToWord("HAPUS_UTAS"))){
            Pengguna user = ELMT_LP(progListPengguna, progIdPengguna);
            ADVWORD();
            perintah[1] = currentWord;
            int idUtas = wordToInt(perintah[1]);
            ADVWORD();
            perintah[2] = currentWord;
            int idx = wordToInt(perintah[2]);
            HAPUS_UTAS(progListDinUtas,user,idUtas,idx);
        } 
        else if (isWordEqual(perintah[0],stringToWord("CETAK_UTAS"))){
            Pengguna user = ELMT_LP(progListPengguna, progIdPengguna);
            ADVWORD();
            perintah[1] = currentWord;
            int idUtas = wordToInt(perintah[1]);
            CETAK_UTAS(progListDinUtas, progFriends, progListPengguna,user,idUtas);
        } 
        else if (isWordEqual(perintah[0],stringToWord("SIMPAN"))){
            SIMPAN();
        } 
        else if (isWordEqual(perintah[0],stringToWord("MUAT"))){
            MUAT();
        }
    }
}
