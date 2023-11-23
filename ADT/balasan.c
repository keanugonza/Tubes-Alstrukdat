#include "balasan.h"
#include <stdlib.h>
#include <stdio.h>

Balasan newNodeBalasan(int idbalasan, Word isibalasan, Word author, DATETIME datetime){
    Balasan p;

    p = (Balasan)malloc(sizeof(NodeBalasan));
    if(p == NULL){
        printf("alokasi gagal\n");
        return NULL;
    }
    IDBALASAN(p) = idbalasan;
    AUTHORBALASAN(p) = author;
    ISIBALASAN(p) = isibalasan;
    SIBLINGBALASAN(p) = NULL;
    CHILDBALASAN(p) = NULL;
    DATETIMEBALASAN(p) = datetime;
    return p;
}

void newChildBalasan(Balasan parentbalasan, Balasan childbalasan){
    Balasan p;

    p = CHILDBALASAN(parentbalasan);
    if(p == NULL){
        CHILDBALASAN(parentbalasan) = childbalasan;
    }
    else{
        while( SIBLINGBALASAN(p) != NULL){
            p = SIBLINGBALASAN(p);
        }
        SIBLINGBALASAN(p) = childbalasan;
    }
}

Balasan findByIdBalasan(Balasan parentbalasan, int idbalasan){
    Balasan res;
    if(IDBALASAN(parentbalasan) == idbalasan) return parentbalasan;
    else{
        res = NULL;
        if(CHILDBALASAN(parentbalasan)!=NULL){
            res = findByIdBalasan(CHILDBALASAN(parentbalasan),idbalasan);
        }
        if(SIBLINGBALASAN(parentbalasan)!=NULL && res == NULL){
            res = findByIdBalasan(SIBLINGBALASAN(parentbalasan),idbalasan);
        }
        return res;
    }
}

int findMaxIdBalasan(Balasan parentbalasan){
    int res,temp;
    res = IDBALASAN(parentbalasan);
    if(CHILDBALASAN(parentbalasan)!=NULL){
        temp = findMaxIdBalasan(CHILDBALASAN(parentbalasan));
        if(temp>res) res = temp;
    }
    if(SIBLINGBALASAN(parentbalasan)!=NULL){
        temp = findMaxIdBalasan(SIBLINGBALASAN(parentbalasan));
        if(temp>res) res = temp;
    }
    return res;
}

void displayBalasan(Balasan cbalasannode){
    printf("| ID = %d\n",IDBALASAN(cbalasannode));
    printf("| ");
    displayWord(AUTHORBALASAN(cbalasannode));
    printf("\n");
    printf("| ");
    TulisDATETIME(DATETIMEBALASAN(cbalasannode));
    printf("\n");
    printf("| ");
    displayWord(ISIBALASAN(cbalasannode));
    printf("\n");
}