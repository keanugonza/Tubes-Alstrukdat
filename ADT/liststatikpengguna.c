/*File : List_pengguna.c*/
/*Implementasi ADT LIST PENGGUNA*/

#include "pengguna.h"
#include "liststatikpengguna.h"
#include "wordmachine.h"
#include "boolean.h"
#include "ADTDasar\pcolor.h"
#include "foto.h"


/* KONSTRUKTOR List Pengguna*/

void createListPengguna(ListPengguna *LP)
{
    for (int i = 0; i < CAPACITY_LPENGGUNA; i++){
        Id(ELMT_LP(*LP,i)) = IDX_UNDEF_LPENGGUNA;
    }
    lenListPengguna(*LP) = 0;
}

void insertPengguna(ListPengguna *LP, eltype val)
{
    if ((*LP).len != CAPACITY_LPENGGUNA)
    {
        ELMT_LP(*LP, (*LP).len) = val;
    }
    lenListPengguna(*LP) = lenListPengguna(*LP) + 1;
}

boolean isMember(ListPengguna LP, Word val)
{
    int i = 0;
    boolean status = false;
    while (i < LP.len && status == false){
        if (isWordEqual(ELMT_LP(LP,i).nama, val) == true){
            status = true;
        }
        else 
        {
            i++;
        }
    }
    return status;
}

int idxPengguna(ListPengguna LP, Word val)
{
    int i = 0;
    boolean status = false;
    while (i < LP.len && status == false){
        if (isWordEqual(ELMT_LP(LP,i).nama, val) == true){
            status = true;
        }
        else 
        {
            i++;
        }
    }
    return i;
}

void printInfoPengguna(ListPengguna LP, int id)
{
    printf("\n| Nama: %s",ELMT_LP(LP,id).nama);
    printf("\n| Bio Akun: %s",ELMT_LP(LP,id).bio);
    printf("\n| No HP: %s",ELMT_LP(LP,id).noHP);
    printf("\n| Weton: %s",ELMT_LP(LP,id).weton);
}

void displayProfil(ListPengguna LP, int id)
{   
    Word listwarna[3];
    listwarna[0] = stringToWord("R");
    listwarna[1] = stringToWord("G");
    listwarna[2] = stringToWord("B");

    for(int i = 0; i < 5;i++){
        for(int j = 0; j < 5; j++){
            if (isWordEqual(ELMT_FT((ELMT_LP(LP, id).color), i, j), listwarna[0]) == true){
                print_red((ELMT_FT((ELMT_LP(LP, id).simbol), i, j)).TabWord[0]);
            }
            else if (isWordEqual(ELMT_FT((ELMT_LP(LP, id).color), i, j), listwarna[1]) == true){
                print_green((ELMT_FT((ELMT_LP(LP, id).simbol), i, j)).TabWord[0]);
            }
            else if (isWordEqual(ELMT_FT((ELMT_LP(LP, id).color), i, j), listwarna[2]) == true){
                print_blue((ELMT_FT((ELMT_LP(LP, id).simbol), i, j)).TabWord[0]);
            }
        }
        printf("\n");
    }
}
