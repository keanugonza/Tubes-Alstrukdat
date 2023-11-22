#include "../../ADT/liststatikpengguna.h"
#include "../../ADT/friends.h"

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

void HAPUS_TEMAN();

