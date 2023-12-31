#include "../kicauan.h"
#include "../listdinKicauan.h"
#include "../datetime.h"
#include "../wordmachine.h"
#include "../charmachine.h"
#include "../pengguna.h"

boolean EndWord;
Word currentWord;
int main(){
    Kicauan K;
    Word author;
    Word text;
    ListDinKicauan l;
    Pengguna user;
    Matrix color,simbol;
    createPengguna(&user, 0, stringToWord("A"), stringToWord("A"), stringToWord(" "), stringToWord(" "), stringToWord(" "), false, color, simbol);
    STARTWORD();
    text = currentWord;
    displayWord(text);

    int capacity = 2;
    CreateListDinKicauan(&l,capacity);

    createKicauan(&K, 1,text,12,user);
    insertKicauan(&l, K);
    displayKicauan(K);
    
    createKicauan(&K, 2,text,12482934,user);
    insertKicauan(&l, K);
    displayKicauan(K);


    printf("\n\n -------------CEK ISI LIST-----------\n");
    K = l.buffer_Kicauan[0];
    displayKicauan(K);
    K = l.buffer_Kicauan[1];
    displayKicauan(K);


    createKicauan(&K, 3,text,111,user);
    displayKicauan(K);
    insertKicauan(&l, K);

    if (isFullKicauan(l)){
        printf("Penuhhh\n");
    }else{
        printf("Kosong\n");
    }

    int len = listLengthKicauan(l);
    printf("%d", len);


    printf("\n\n -------------TAMBAH LIKE-----------\n");
    printf("TAMBAH LIKE ID 1\n");
    int id = 1;
    Kicauan k = KICAUAN(l,id-1);
    tambahLike(&k, 10);
    setKicauan(&l,k,id-1);
    K = KICAUAN(l,id-1);
    displayKicauan(K);

    printf("\n\n -------------UBAH TEXT-----------\n");
    printf("UBAH TEKS ID 1\n");
    k = KICAUAN(l,id-1);
    ubahTeksKicauan(&k);
    setKicauan(&l,k,id-1);
    K = KICAUAN(l,id-1);
    displayKicauan(K);
}

//gcc  -o main .\driverKicauan.c ..\charmachine.c ..\datetime.c ..\kicauan.c ..\listdinKicauan.c ..\pengguna.c ..\wordmachine.c