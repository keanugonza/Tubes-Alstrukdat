#include <stdio.h>
#include <stdlib.h>
#include "friends.h"

void createPertemanan(Friends *f){
    /* I.S. Sembarang */
    /* F.S. Mengembalikan graph adjacency matriks dari pertemanan */
    int i,j;
    createGraph(f);
    for(i = 0; i<ROW_EFF(*f); i++){
        for(j = 0; j<COL_EFF(*f); i++){
            if (i == j){
                ELMT(*f,i,j) = 1;
            }
        }
    }
}

void addFriend(Friends *f, int user1, int user2){
    /* I.S. Friends terdefinisi */
    /* F.S. Mengembalikan friends dengan penambahan relasi antara user 1 dan user 2 */
    ELMT(*f,user1,user2) = 1;
    ELMT(*f,user2,user1) = 1;
}

void removeFriend(Friends*f, int user1, int user2){
    /* I.S. Friends terdefinisi */
    /* F.S. Mengembalikan friends dengan pengurangan relasi antara user 1 dan user 2 */
    ELMT(*f,user1,user2) = 0;
    ELMT(*f,user2,user1) = 0;
}

boolean isFriend(Friends f, int user1, int user2){
    return ELMT(f,user1,user2) == 1;
}