#include "subprogram/data.h"

#include "subprogram/perintahDraf.c"
#include "subprogram/perintahKicauan.c"
#include "subprogram/perintahpengguna.c"
#include "subprogram/perintahPermintaanPertemanan.c"
#include "subprogram/perintahprofil.c"
#include "subprogram/perintahTeman.c"
#include "subprogram/perintahUtas.c"
#include "subprogram/perintahBalasan.c"
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
    for(int i=0; i<20; i ++){
        CreateStackDraf(&progStackDraf[i]);
    }
    // for(int i=0; i<20; i ++){
    //     createFriendReqList(&progQueue[i]);
    // }
    createListPengguna(&progListPengguna);
    CreateListDinKicauan(&progListDinKicau,1);
    CreateListDinUtas(&progListDinUtas,1);
    // createPertemanan(&progFriends);

    Word perintah[3];
    STARTWORD();
    perintah[0] = currentWord;
    while(!(isWordEqual(perintah[0],stringToWord("TUTUP_PROGRAM")))){
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
            HAPUS_TEMAN(user, progListPengguna, &progFriends);
        } 
        else if (isWordEqual(perintah[0],stringToWord("TAMBAH_TEMAN"))){
            Pengguna user = ELMT_LP(progListPengguna, progIdPengguna);
            addFriendReq(&progQueue[progIdPengguna], user, progFriends, progListPengguna);
        } 
        else if (isWordEqual(perintah[0],stringToWord("DAFTAR_PERMINTAAN_TEMAN"))){
            displayFriendReqList(progQueue[progIdPengguna]);
        } 
        else if (isWordEqual(perintah[0],stringToWord("SETUJUI_PERTEMANAN"))){
            Pengguna user = ELMT_LP(progListPengguna, progIdPengguna);
            accFriendReq(&progQueue[progIdPengguna], user, &progFriends,progListPengguna);
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
            int idKicau = wordToInt(perintah[1]);
            ADVWORD();
            perintah[2] = currentWord;
            int idBalas = wordToInt(perintah[2]);
            BALAS(idKicau, idBalas, progListPengguna, &progListDinKicau, progIdPengguna, progFriends);
        } 
        else if (isWordEqual(perintah[0],stringToWord("BALASAN"))){
            ADVWORD();
            perintah[1] = currentWord;
            int idKicau = wordToInt(perintah[1]);
            BALASAN(progIdPengguna, idKicau, progListDinKicau, progListPengguna, progFriends);
        } 
        else if (isWordEqual(perintah[0],stringToWord("HAPUS_BALASAN"))){
            ADVWORD();
            perintah[1] = currentWord;
            int idKicau = wordToInt(perintah[1]);
            ADVWORD();
            perintah[2] = currentWord;
            int idHapus = wordToInt(perintah[2]);
            HAPUSBALAS(idKicau, idHapus, progListPengguna, &progListDinKicau, progIdPengguna);
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
            UTAS(&progListDinUtas, progListDinKicau, user, idKicau);
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
            // SIMPAN();
        } 
        else if (isWordEqual(perintah[0],stringToWord("MUAT"))){
            // MUAT();
        }
        // displayWord(perintah[0]);
        ADVWORD();
        perintah[0] = currentWord;
    }
}
