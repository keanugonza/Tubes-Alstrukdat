#include "../datetime.h"

int main(){
    DATETIME D;
    BacaDATETIME(&D);
    TulisDATETIME(D);
}

//gcc -o main .\driverdatetime.c ..\datetime.c 