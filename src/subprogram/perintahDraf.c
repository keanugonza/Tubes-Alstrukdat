#include <stdio.h>
#include "C:\Users\Keanu\Documents\GitHub\Tubes-Alstrukdat\ADT\kicauan.h"
#include "C:\Users\Keanu\Documents\GitHub\Tubes-Alstrukdat\ADT\stackDraf.h"
#include "C:\Users\Keanu\Documents\GitHub\Tubes-Alstrukdat\ADT\wordmachine.h"
#include "C:\Users\Keanu\Documents\GitHub\Tubes-Alstrukdat\ADT\charmachine.h"
#include "C:\Users\Keanu\Documents\GitHub\Tubes-Alstrukdat\ADT\boolean.h"
#include "C:\Users\Keanu\Documents\GitHub\Tubes-Alstrukdat\ADT\datetime.h"

#include "C:\Users\Keanu\Documents\GitHub\Tubes-Alstrukdat\ADT\kicauan.c"
#include "C:\Users\Keanu\Documents\GitHub\Tubes-Alstrukdat\ADT\stackDraf.c"
#include "C:\Users\Keanu\Documents\GitHub\Tubes-Alstrukdat\ADT\wordmachine.c"
#include "C:\Users\Keanu\Documents\GitHub\Tubes-Alstrukdat\ADT\charmachine.c"
#include "C:\Users\Keanu\Documents\GitHub\Tubes-Alstrukdat\ADT\datetime.c"
#include "perintahKicauan.c"


void SIMPAN(StackDraf*s, Word text){
    Draf d;
    createDraf(&d, text);
    pushDraf(&s,d);
}

void TERBIT(ListDinKicauan *l, Word text, boolean privat, Word author){
    Kicauan k;
    int id = listLengthKicauan(*l) + 1;
    int like =0;
    createKicauan(&k, id, text, like, author, privat);
    insertKicauan(l,k);
    printf("\n");
    printf("Selamat! kicauan telah diterbitkan!\n");
    printf("Detil kicauan:\n");
    displayKicauan(k);
}



BUAT_DRAF(StackDraf *s, ListDinKicauan *l, boolean privat, Word author){
    Word text;
    int pilihan;
    printf("Masukkan draf:\n");
    STARTWORD_takeBlank();
    text = currentWord;

    printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?\n");

    if(pilihan == 0){ //HAPUS
        printf("Draf telah berhasil dihapus!\n");
    } else if(pilihan == 1){ //SIMPAN
        SIMPAN(s, text);
    } else if (pilihan ==3){ //TERBIT
        TERBIT(l, text, privat, author);
    }
}

LIHAT_DRAF()



