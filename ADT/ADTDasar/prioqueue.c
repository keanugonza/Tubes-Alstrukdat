#include <stdlib.h>
#include <stdio.h>
#include "prioqueue.h"

boolean IsEmpty(Queue Q){
    return((Head(Q) == Nil) && (Tail(Q) == Nil));
}

boolean IsFull(Queue Q){
    return((((Tail(Q) - Head(Q) + MaxEl(Q)) % MaxEl(Q)) + 1) == MaxEl(Q));
}

int NBElmt(Queue Q){
    if(IsEmpty(Q))
        return 0;
    else
        return(((Tail(Q) - Head(Q) + MaxEl(Q)) % MaxEl(Q)) + 1);
}

void CreateEmpty(Queue *Q, int Max){
    (*Q).T = malloc((Max + 1) * sizeof(infotype));
    if((*Q).T != NULL){
        MaxEl(*Q) = Max;
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    }
    else
        MaxEl(*Q) = 0;
}

void DeAlokasi(Queue *Q){
    MaxEl(*Q) = 0;
    free((*Q).T);
}

void Add(Queue *Q, infotype X){
    if(IsEmpty(*Q)){
        Head(*Q) = 1;
        Tail(*Q) = Head(*Q);
        InfoHead(*Q) = X;
    }
    else{
        int n = NBElmt(*Q);
        int idx = Tail(*Q);
        while((Prio(X) > Prio((*Q).T[idx])) && (n > 0)){
            (*Q).T[(idx % MaxEl(*Q)) + 1] = (*Q).T[idx];
            idx--;
            n--;
            if(idx == 0)
                idx = MaxEl(*Q);
        }
        (*Q).T[(idx % MaxEl(*Q)) + 1] = X;
        Tail(*Q) = (Tail(*Q) % MaxEl(*Q)) + 1;
    }
}

void Del(Queue *Q, infotype *X){
    Info(*X) = Info(InfoHead(*Q));
    Prio(*X) = Prio(InfoHead(*Q));
    if(NBElmt(*Q) == 1){
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    }
    else
        Head(*Q) = (Head(*Q) % MaxEl(*Q)) + 1;
}

void PrintQueue(Queue Q){
    infotype dum;
    while(!IsEmpty(Q)){
        Del(&Q, &dum);
        printf("%d %d\n", Prio(dum), Info(dum));
    }
    printf("#\n");
}