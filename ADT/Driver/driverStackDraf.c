#include "../kicauan.h"
#include "../stackDraf.h"
#include "../datetime.h"
#include "../wordmachine.h"
#include "../charmachine.h"
#include <stdio.h>

boolean EndWord;
Word currentWord;
int main(){
    Draf d, d2;
    DATETIME T;
    Word author;
    Word text;

    StackDraf s;
    CreateStackDraf(&s);
    
    printf("\n\n---------------------push-----------------------\n");
    STARTWORD();
    text = currentWord;
    createDraf(&d, text);
    pushDraf(&s, d);

    printf("\n\n---------------------pop-----------------------\n");
    popDraf(&s, &d);
    displayDraf(d);

 
    printf("\n\n---------------------push1-----------------------\n");
    ADVWORD();
    text = currentWord;
    createDraf(&d2, text);
    pushDraf(&s, d2);

    printf("\n\n---------------------push2-----------------------\n");
    ADVWORD();
    text = currentWord;
    createDraf(&d2, text);
    pushDraf(&s, d2);

    printf("\n\n---------------------pop 1-----------------------\n");
    popDraf(&s, &d2);
    displayDraf(d2);
    printf("\n\n---------------------pop 2-----------------------\n");
    popDraf(&s, &d2);
    displayDraf(d2);
 

 
}

//gcc  -o main .\driverStackDraf.c ..\charmachine.c ..\datetime.c ..\kicauan.c ..\listdinKicauan.c ..\wordmachine.c ..\stackDraf.c