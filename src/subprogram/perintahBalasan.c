#include "../../ADT/balasan.h"
#include "../../ADT/liststatikpengguna.h"
#include "../../ADT/listdinKicauan.h"
#include "../../ADT/friends.h"


void BALAS(int idkicau, int iddibalas, ListPengguna progListPengguna, ListDinKicauan *progListKicau, int progIdUser,Friends progFriends);
void rekurbalasan(Balasan cnodebal, int progIdUser, int idxKicau, ListDinKicauan progListKicau, ListPengguna progListPengguna, Friends progFriends, int depth);
void BALASAN(int progIdUser, int idxKicau, ListDinKicauan progListKicau, ListPengguna progListPengguna, Friends progFriends);
void HAPUSBALAS(int idkicau, int balasdihapus, ListPengguna progListPengguna, ListDinKicauan *progListKicau, int progIdUser);
void rekurHapusBalas(Balasan par, int idxdihapus);




void BALAS(int idkicau, int iddibalas, ListPengguna progListPengguna, ListDinKicauan *progListKicau, int progIdUser,Friends progFriends)
{
    idkicau--;
    Balasan par, parbalasan, resBalasan;
    Word kataBalasan, namaUser;
    DATETIME dtbalasan;
    int idbalasan,idxauthorkicau;
    if (idkicau > (progListKicau->nEff_Kicauan) || idkicau < 1)
    {
        printf("Wah, tidak terdapat kicauan yang ingin Anda balas!\n");
        return;
    }

    par = ANAK_KICAU(KICAUAN(*progListKicau, idkicau));
    parbalasan = findByIdBalasan(par, iddibalas);

    if (parbalasan == NULL && iddibalas != -1)
    {
        printf("Wah, tidak terdapat kicauan yang ingin Anda balas!\n");
        return;
    }
    idxauthorkicau = idxPengguna(progListPengguna,AUTHOR_KICAUAN(KICAUAN(*progListKicau, idkicau)));
    if(Jenis(ELMT_LP(progListPengguna,idxauthorkicau)) && !isFriend(progFriends, idxauthorkicau, progIdUser)){
        printf("Wah, akun tersebut merupakan akun privat dan anda belum berteman akun tersebut!\n");
        return;
    }

    printf("Masukkan balasan:");
    ADVWORD_takeBlank();
    kataBalasan = currentWord;
    namaUser = Nama(ELMT_LP(progListPengguna, progIdUser));
    BacaDATETIME(&dtbalasan);
    idbalasan = findMaxIdBalasan(par) + 1;
    resBalasan = newNodeBalasan(idbalasan, kataBalasan, namaUser, dtbalasan);

    if (iddibalas == -1)
    {
        if (par == NULL)
        {
            ANAK_KICAU(KICAUAN(*progListKicau, idkicau)) = resBalasan;
        }
        else
        {
            while (SIBLINGBALASAN(par) != NULL)
            {
                par = SIBLINGBALASAN(par);
            }
            SIBLINGBALASAN(par) = resBalasan;
        }
    }
    else
    {
        newChildBalasan(parbalasan, resBalasan);
    }
}

void rekurbalasan(Balasan cnodebal, int progIdUser, int idxKicau, ListDinKicauan progListKicau, ListPengguna progListPengguna, Friends progFriends, int depth){
    int i, idxauthorbalas;
    idxauthorbalas = idxPengguna(progListPengguna,AUTHORBALASAN(cnodebal));
    for(i = 0;i<depth;i++){
        printf("  ");
    }
    printf("| ID = %d\n",IDBALASAN(cnodebal));
    for(i = 0;i<depth;i++){
        printf("  ");
    }
    printf("| ");
    if(!isFriend(progFriends,idxauthorbalas,progIdUser) && Jenis(ELMT_LP(progListPengguna,idxauthorbalas)))
        printf("PRIVAT");
    else
        displayWord(AUTHORBALASAN(cnodebal));
    printf("\n");
    for(i = 0;i<depth;i++){
        printf("  ");
    }
    printf("| ");
    if(!isFriend(progFriends,idxauthorbalas,progIdUser) && Jenis(ELMT_LP(progListPengguna,idxauthorbalas)))
        printf("PRIVAT");
    else
        TulisDATETIME(DATETIMEBALASAN(cnodebal));
    printf("\n");
    for(i = 0;i<depth;i++){
        printf("  ");
    }
    printf("| ");
    if(!isFriend(progFriends,idxauthorbalas,progIdUser) && Jenis(ELMT_LP(progListPengguna,idxauthorbalas)))
        printf("PRIVAT");
    else
        displayWord(ISIBALASAN(cnodebal));
    printf("\n");
    if(CHILDBALASAN(cnodebal) != NULL){
        rekurbalasan(CHILDBALASAN(cnodebal), progIdUser,idxKicau, progListKicau, progListPengguna, progFriends, depth+1);
    }
    if(SIBLINGBALASAN(cnodebal) != NULL){
        rekurbalasan(SIBLINGBALASAN(cnodebal), progIdUser,idxKicau, progListKicau, progListPengguna, progFriends, depth);
    }
}

void BALASAN(int progIdUser, int idxKicau, ListDinKicauan progListKicau, ListPengguna progListPengguna, Friends progFriends){
    idxKicau--;
    int idxauthorkicau;
    Balasan par;
    if (idxKicau > (progListKicau.nEff_Kicauan) || idxKicau < 1)
    {
        printf("Tidak terdapat kicauan dengan id tersebut!\n");
        return;
    }
    idxauthorkicau = idxPengguna(progListPengguna,AUTHOR_KICAUAN(KICAUAN(progListKicau, idxKicau)));
    if(Jenis(ELMT_LP(progListPengguna,idxauthorkicau)) && !isFriend(progFriends, idxauthorkicau, progIdUser)){
        printf("Wah, kicauan tersebut dibuat oleh pengguna dengan akun privat!\n");
        return;
    }
    if(ANAK_KICAU(KICAUAN(progListKicau, idxKicau)) == NULL){
        printf("Belum terdapat balasan apapun pada kicauan tersebut. Yuk balas kicauan tersebut!");
        return;
    }
    par = ANAK_KICAU(KICAUAN(progListKicau, idxKicau));
    rekurbalasan(par, progIdUser,idxKicau, progListKicau, progListPengguna, progFriends, 0);
}

void HAPUSBALAS(int idkicau, int balasdihapus, ListPengguna progListPengguna, ListDinKicauan *progListKicau, int progIdUser){
    Balasan par;
    Balasan resbalasan;
    idkicau--;
    par = ANAK_KICAU(KICAUAN(*progListKicau, idkicau));
    resbalasan = findByIdBalasan(par, balasdihapus);
    if(resbalasan == NULL){
        printf("Balasan tidak ditemukan\n");
        return;
    }if(!isWordEqual(AUTHORBALASAN(resbalasan),Nama(ELMT_LP(progListPengguna,progIdUser)))){
        printf("Hei, ini balasan punya siapa? Jangan dihapus ya!\n");
        return;
    }
    rekurHapusBalas(par,balasdihapus);
}

void rekurHapusBalas(Balasan par, int idxdihapus){
    if(par == NULL) return;
    if(CHILDBALASAN(par)!=NULL){
        if(IDBALASAN(CHILDBALASAN(par)) == idxdihapus){
            (CHILDBALASAN(par)) = SIBLINGBALASAN(CHILDBALASAN(par));
            return;
        }
        else{
            rekurHapusBalas(CHILDBALASAN(par),idxdihapus);
        }
    }
    if(SIBLINGBALASAN(par)!=NULL){
        if(IDBALASAN(SIBLINGBALASAN(par)) == idxdihapus){
            (SIBLINGBALASAN(par)) = SIBLINGBALASAN(SIBLINGBALASAN(par));
            return;
        }
        else{
            rekurHapusBalas(SIBLINGBALASAN(par),idxdihapus);
        }
    }
}