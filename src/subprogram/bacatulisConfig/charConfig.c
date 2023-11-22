#include "charmachine.h"
#include <stdio.h>

char currentChar;
boolean EOP;

static FILE *pitaconfig;
static int retvalconfig;

void START_Char_Config()
{
       /* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
          Karakter pertama yang ada pada pita posisinya adalah pada jendela.
          I.S. : sembarang
          F.S. : currentChar adalah karakter pertama pada pita. Jika currentChar != MARK maka EOP akan padam (false).
                 Jika currentChar = MARK maka EOP akan menyala (true) */

       /* Algoritma */
       pitaconfig = fopen("sapi.config","w");
       ADV_Char();
}

void ADV_Char_Config()
{
       /* Pita dimajukan satu karakter.
          I.S. : Karakter pada jendela =
                 currentChar, currentChar != MARKSC, currentChar != MARKNL
          F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
                 currentChar mungkin = MARKSC atau =MARKNL
                       Jika  currentChar = MARK maka EOP akan menyala (true) */

       /* Algoritma */
       retvalconfig = fscanf(pitaconfig, "%c", &currentChar);
}