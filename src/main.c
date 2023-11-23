#include "subprogram/data.h"
#include "..\ADT\wordmachine.h"


int main(){
    Word perintah[3];
    ADVWORD();
    perintah[0] = currentWord;
    while(!IsWordEqual(perintah[0],stringToWord("TUTUP_PROGRAM"))){
        if(isWordEqual(perintah[0],stringToWord("DAFTAR"))){
            daftar(&progListPengguna);
        } else if (isWordEqual(perintah[0],stringToWord("MASUK"))){
            masuk(&progListPengguna, &progIdPengguna);
        } else if (isWordEqual(perintah[0],stringToWord("GANTI_PROFIL"))){
            gantiprofil(&progListPengguna, &progIdPengguna);
        } else if (isWordEqual(perintah[0],stringToWord("LIHAT_PROFIL"))){
            ADVWORD();
            perintah[1] = currentWord;
            lihatprofil(&progListPengguna, perintah[1]);
        } else if (isWordEqual(perintah[0],stringToWord("ATUR_JENIS_AKUN"))){
            aturjenisakun(&progListPengguna, &progIdPengguna);
        } else if (isWordEqual(perintah[0],stringToWord("UBAH_FOTO_PROFIL"))){
            ubahfotoprofil(&progListPengguna, &progIdPengguna);
        } else if (isWordEqual(perintah[0],stringToWord("DAFTAR_TEMAN"))){
            Pengguna user = ELMT_LP(progListPengguna, progIdPengguna);
            DAFTAR_TEMAN();
        } else if (isWordEqual(perintah[0],stringToWord("HAPUS_TEMAN"))){
            HAPUS_TEMAN();
        } else if (isWordEqual(perintah[0],stringToWord("TAMBAH_TEMAN"))){
            TAMBAH_TEMAN();
        } else if (isWordEqual(perintah[0],stringToWord("DAFTAR_PERMINTAAN_TEMAN"))){
            DAFTAR_PERMINTAAN_TEMAN();
        } else if (isWordEqual(perintah[0],stringToWord("SETUJUI_PERTEMANAN"))){
            SETUJUI_PERTEMANAN();
        } else if (isWordEqual(perintah[0],stringToWord("KICAU"))){
            KICAU();
        } else if (isWordEqual(perintah[0],stringToWord("KICAUAN"))){
            ALLKICAUAN();
        } else if (isWordEqual(perintah[0],stringToWord("SUKA_KICAUAN"))){
            ADVWORD();
            perintah[1] = currentWord;
            SUKA_KICAUAN();
        } else if (isWordEqual(perintah[0],stringToWord("UBAH_KICAUAN"))){
            ADVWORD();
            perintah[1] = currentWord;
            UBAH_KICAUAN();
        } else if (isWordEqual(perintah[0],stringToWord("BALAS"))){
            ADVWORD();
            perintah[1] = currentWord;
            ADVWORD();
            perintah[2] = currentWord;
            BALAS();
        } else if (isWordEqual(perintah[0],stringToWord("BALASAN"))){
            ADVWORD();
            perintah[1] = currentWord;
            BALASAN();
        } else if (isWordEqual(perintah[0],stringToWord("HAPUS_BALASAN"))){
            ADVWORD();
            perintah[1] = currentWord;
            ADVWORD();
            perintah[2] = currentWord;
            HAPUS_BALASAN();
        } else if (isWordEqual(perintah[0],stringToWord("BUAT_DRAF"))){
            BUAT_DRAF();
        } else if (isWordEqual(perintah[0],stringToWord("LIHAT_DRAF"))){
            LIHAT_DRAF();
        } else if (isWordEqual(perintah[0],stringToWord("UTAS"))){
            ADVWORD();
            perintah[1] = currentWord
            UTAS();
        } else if (isWordEqual(perintah[0],stringToWord("SAMBUNG_UTAS"))){
            ADVWORD();
            perintah[1] = currentWord
            ADVWORD();
            perintah[2] = currentWord
            SAMBUNG_UTAS();
        } else if (isWordEqual(perintah[0],stringToWord("HAPUS_UTAS"))){
            ADVWORD();
            perintah[1] = currentWord
            ADVWORD();
            perintah[2] = currentWord
            HAPUS_UTAS();
        } else if (isWordEqual(perintah[0],stringToWord("CETAK_UTAS"))){
            ADVWORD();
            perintah[1] = currentWord
            CETAK_UTAS();
        } else if (isWordEqual(perintah[0],stringToWord("SIMPAN"))){
            SIMPAN();
        } else if (isWordEqual(perintah[0],stringToWord("MUAT"))){
            MUAT();
        }
    }
}
