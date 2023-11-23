#include "../balasan.h"
#include <stdio.h>



int main(){
    Word nama,isi;
    DATETIME d1;
    Balasan balasanutama,balasan1,balasan2,balasan11,balasan21;

    STARTWORD_takeBlank();
    nama = currentWord;
    ADVWORD_takeBlank();
    isi = currentWord;
    BacaDATETIME(&d1);
    balasanutama = newNodeBalasan(-1,isi,nama,d1);
    displayBalasan(balasanutama);
    STARTWORD_takeBlank();
    nama = currentWord;
    ADVWORD_takeBlank();
    isi = currentWord;
    BacaDATETIME(&d1);
    balasan1 = newNodeBalasan(1,isi,nama,d1);
    displayBalasan(balasan1);
    STARTWORD_takeBlank();
    nama = currentWord;
    ADVWORD_takeBlank();
    isi = currentWord;
    BacaDATETIME(&d1);
    balasan2 = newNodeBalasan(2,isi,nama,d1);
    displayBalasan(balasan2);
    STARTWORD_takeBlank();
    nama = currentWord;
    ADVWORD_takeBlank();
    isi = currentWord;
    BacaDATETIME(&d1);
    balasan11 = newNodeBalasan(11,isi,nama,d1);
    displayBalasan(balasan11);
    STARTWORD_takeBlank();
    nama = currentWord;
    ADVWORD_takeBlank();
    isi = currentWord;
    BacaDATETIME(&d1);
    balasan21 = newNodeBalasan(21,isi,nama,d1);
    displayBalasan(balasan21);

    newChildBalasan(balasanutama,balasan1);
    newChildBalasan(balasanutama,balasan2);
    newChildBalasan(balasan1,balasan11);
    newChildBalasan(balasan2,balasan21);
    displayBalasan(CHILDBALASAN(balasanutama));
    displayBalasan(SIBLINGBALASAN(balasan1));
    displayBalasan(CHILDBALASAN(balasan1));
    displayBalasan(CHILDBALASAN(balasan2));
}