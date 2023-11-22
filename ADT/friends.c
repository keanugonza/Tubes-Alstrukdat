#include <stdio.h>
#include <stdlib.h>
#include "friends.h"

void createPertemanan(Friends *f){
    /* I.S. Sembarang */
    /* F.S. Mengembalikan graph adjacency matriks dari pertemanan */
    int i,j;
    createGraph(f);
    for(i = 0; i<20; i++){
        for(j = 0; j<20; i++){
            if (i == j){
                NODE_TEMAN(*f,i,j) = 1;
            }
        }
    }
}

void addFriend(Friends *f, int user1, int user2){
    /* I.S. Friends terdefinisi */
    /* F.S. Mengembalikan friends dengan penambahan relasi antara user 1 dan user 2 */
    NODE_TEMAN(*f,user1,user2) = 1;
    NODE_TEMAN(*f,user2,user1) = 1;
}

void removeFriend(Friends*f, int user1, int user2){
    /* I.S. Friends terdefinisi */
    /* F.S. Mengembalikan friends dengan pengurangan relasi antara user 1 dan user 2 */
    NODE_TEMAN(*f,user1,user2) = 0;
    NODE_TEMAN(*f,user2,user1) = 0;
}

boolean isFriend(Friends f, int user1, int user2){
    return NODE_TEMAN(f,user1,user2) == 1;
}

int friendCount(Friends f, int user){
    int i,j;
    int count;
    for(i = 0; i < 20; i++){
        if(i != user){
            if(f[i] == 1){
                count +=1;
            }
        }
    }
}