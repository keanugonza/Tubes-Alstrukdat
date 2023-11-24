#include "kicauan.h"
#include "stackDraf.h"
#include "datetime.h"
#include "wordmachine.h"
#include "charmachine.h"

boolean EndWord;
Word currentWord;
int main(){
    Draf d;
    DATETIME T;
    Word author;
    Word text;

    StackDraf s;
    CreateStackDraf(&s);
    
    STARTWORD_takeBlank();
    text = currentWord;
    createDraf(&d, text);
    displayDraf(d);
    pushDraf(&s, d);

    STARTWORD_takeBlank();
    text = currentWord;
    createDraf(&d, text);
    displayDraf(d);
    pushDraf(&s, d);

    popDraf(&s, &d);
    displayDraf(d);

    popDraf(&s, &d);
    displayDraf(d);
    // createKicauan(&K, 1,text,12,author,true);
    // pushDraf(&s, K);
    // printKicauan(&K);
    
    // createKicauan(&K, 2,text,12482934,author,true);
    // pushDraf(&s, K);
    // printKicauan(&K);


    // printf("\n\n-------------OPERASI POP--------------");
    // popDraf(&s, &K);
    // printKicauan(&K);
    // popDraf(&s, &K);
    // printKicauan(&K);
 
}

//gcc -o testKicauan .\datetime.c .\kicauan.c .\listdinKicauan.c .\testKicauan.c