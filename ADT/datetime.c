#include <stdio.h>
#include "time.h"


/* *** Definisi TYPE DATETIME <DD/MM/YY HH:MM:SS> *** */
typedef struct
{
    int YY;   /* integer tahun*/
    int MM;     /* integer bulan*/
    int DD;     /* integer hari*/
    int hh;     /* integer jam*/
    int mm;     /* integer menit*/
    int ss;     /* integer detik*/
} DATETIME;

/* *** Notasi Akses: selektor DATETIME *** */
#define YEAR(D) (D).YY
#define MONTH(D) (D).MM
#define DAY(D) (D).DD
#define HOUR(D) (D).hh
#define MINUTE(D) (D).mm
#define SECOND(D) (D).ss


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
    hh = (gm_time -> tm_hour) + 7;
    mm = gm_time -> tm_min;
    ss = gm_time -> tm_sec;

    CreateDATETIME(D,YY,MM,DD,hh,mm,ss);


}
/* I.S. : D tidak terdefinisi */
/* F.S. : D terdefinisi dan merupakan DATETIME yang valid */


void TulisDATETIME(DATETIME D){
    printf("%d/",DAY(D));
    printf("%d/",MONTH(D));
    printf("%d ",YEAR(D));
    printf("%d:",HOUR(D));
    printf("%d:",MINUTE(D));
    printf("%d",SECOND(D));
    printf("\n");

}

/* I.S. : D sembarang */
/* F.S. : Nilai D ditulis dg format DD/MM/YYYY HH:MM:SS */
/* Proses : menulis nilai setiap komponen D ke layar dalam format DD/MM/YYYY HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/