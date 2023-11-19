/*File : List_pengguna.c*/
/*Implementasi ADT LIST PENGGUNA*/

#include "pengguna.h"
#include "liststatikpengguna.h"
#include "wordmachine.h"
#include <stdio.h>

/* KONSTRUKTOR List Pengguna*/

void createListPengguna(ListPengguna *LP)
{
    for (int i=0; i<CAPACITY_LPENGGUNA; i++){
        Id(ELMT_LP(*LP,i)) = IDX_UNDEF_LPENGGUNA;
    }
    lenListPengguna(*LP) = 0;
}
