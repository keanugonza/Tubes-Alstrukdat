#include "balasan.h"
#include <stdlib.h>

Balasan newNodeBalasan(int idbalasan, int idparent, Word author, DATETIME datetime){
    Balasan p;

    p = (Balasan)malloc(sizeof(NodeBalasan));
    if(p == NULL){
        printf("alokasi gagal\n");
        return NULL;
    }
    IDBALASAN(p) = idbalasan;
    IDPARENTBALASAN(p) = idparent;
    AUTHORBALASAN(p) = author;
    SIBLINGBALASAN(p) = NULL;
    CHILDBALASAN(p) = NULL;
    DATETIMEBALASAN(p) = datetime;
    return p;
}

void newChildBalasan(Balasan parent, Balasan child){
    Balasan p;

    p = CHILDBALASAN(parent);
    if(p == NULL){
        CHILDBALASAN(parent) = child;
    }
    else{
        while(SIBLINGBALASAN(p) != NULL){
            p = SIBLINGBALASAN(p);
        }
        SIBLINGBALASAN(p) = child;
    }
}