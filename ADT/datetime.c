#include <stdio.h>
#include "time.h"
#include "datetime.h"


/* *** Konstruktor: Membentuk sebuah DATETIME dari komponen-komponennya *** */


/* *** Konstruktor: Membentuk sebuah DATETIME dari komponen-komponennya *** */
void CreateDATETIME(DATETIME *D, int YY, int MM, int DD, int hh, int mm, int ss){
    YEAR(*D) = YY;
    MONTH(*D) = MM;
    DAY(*D) = DD;
    HOUR(*D) = hh;
    MINUTE(*D) = mm;
    SECOND(*D) = ss;
}
/* Membentuk sebuah DATETIME dari komponen-komponennya yang valid */
/* Prekondisi : DD, MM, YY, hh, mm, ss valid untuk membentuk DATETIME */

void BacaDATETIME(DATETIME *D){
    int YY,MM,DD,hh,mm,ss;
    time_t now = time(NULL);
    struct tm *gm_time = gmtime(&now);
    
    YY = (gm_time -> tm_year) + 1900;
    MM = (gm_time -> tm_mon) + 1;
    DD = gm_time -> tm_mday;
    hh = ((gm_time -> tm_hour) + 7) % 24;
    mm = gm_time -> tm_min;
    ss = gm_time -> tm_sec;

    CreateDATETIME(D,YY,MM,DD,hh,mm,ss);


}
/* I.S. : D tidak terdefinisi */
/* F.S. : D terdefinisi dan merupakan DATETIME yang valid */


void TulisDATETIME(DATETIME D){
    if(DAY(D)<10){
        printf("0%d/",DAY(D));
    }  if (DAY(D)>=10){
        printf("%d/",DAY(D));
    }  if (MONTH(D)<10){
        printf("0%d/",MONTH(D));
    }  if (MONTH(D) >= 10){
        printf("%d/",MONTH(D));
    }  if (YEAR(D) < 10){
        printf("0%d ",YEAR(D));
    }  if (YEAR(D)>=10){
        printf("%d ",YEAR(D));
    }  if (HOUR(D) < 10){
        printf("0%d:",HOUR(D));
    } if (HOUR(D)>=10){
        printf("%d:",HOUR(D));
    } if (MINUTE(D)<10){
        printf("0%d:",MINUTE(D));
    } if (MINUTE(D)>=10){
         printf("%d:",MINUTE(D));
    } if (SECOND(D) < 10){
        printf("0%d",SECOND(D));
    } if (SECOND(D)>=10){
        printf("%d",SECOND(D));
    }
}

/* I.S. : D sembarang */
/* F.S. : Nilai D ditulis dg format DD/MM/YYYY HH:MM:SS */
/* Proses : menulis nilai setiap komponen D ke layar dalam format DD/MM/YYYY HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/