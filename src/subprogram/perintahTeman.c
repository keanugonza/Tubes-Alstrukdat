#include "../../ADT/liststatikpengguna.h"
#include "../../ADT/friends.h"
#include "../../ADT/wordmachine.h"

void DAFTAR_TEMAN(Pengguna user, ListPengguna lp, Friends f){
    int length = lenListPengguna(lp);
    int i;
    int jumlahTeman = friendCount(Id(user));
    if(jumlahTeman > 0){
        displayWord(Nama(user));
        printf(" memiliki %d teman\n", jumlahTeman);
        printf("Daftar teman ");
        displayWord(Nama(user));
        for(i = 0; i < 20; i++){
            if(i!= Id(user)){
                if(f[i] == 1){
                    printf("| ");
                    displayWord(Nama(ELMT_LP(lp,i)));
                }
            }
        }
        printf("\n")
    }else{
        displayWord(Nama(user));
        printf(" belum mempunyai teman.\n")
    }
    

}

void HAPUS_TEMAN(Pengguna user, ListPengguna lp, Friends *f){
    Word ya,tidak;
    ya.TabWord[0] = 'Y';
    ya.TabWord[1] = 'A';
    ya.Length = 2;
    tidak.TabWord[0] = 'T';
    tidak.TabWord[1] = 'I';
    tidak.TabWord[2] = 'D';
    tidak.TabWord[3] = 'A';
    tidak.TabWord[4] = 'K';
    tidak.Length = 5;
    printf("Masukkan nama pengguna:\n");
    ADVWORD_takeBlank();
    if(isMember(lp,currentWord)){
        if(isFriend(*f,idxPengguna(Nama(user)), idxPengguna(currentWord))){
            for(;;){ // cek input agar YA atau TIDAK
                    printf("Apakah anda yakin ingin menghapus ");
                    displayWord(currentWord);
                    printf("dari daftar teman anda?(YA/TIDAK)\n");
                    ADVWORD_takeBlank();
                    if(isWordEqual(currentWord,ya) || isWordEqual(currentWord,tidak)){
                        break;
                    }else{
                        printf("Silahkan ulangi input anda!\n");
                    }
                }
            if(isWordEqual(currentWord,ya)){
                removeFriend(f,idxPengguna(Nama(user)), idxPengguna(currentWord));
                displayWord(currentWord);
                printf(" berhasil dihapus dari daftar teman Anda.\n");
            }else{
                printf("Penghapusan teman dibatalkan.\n")
            }
        }else{
            displayWord(currentWord);
            printf(" bukan teman Anda\n")
        }
    }else{
        printf("User tidak dapat ditemukan\n")
    }
}

