#include <stdlib.h>
#include <stdio.h>
#include "prioqueue.h"

boolean IsEmpty(Queue Q){
    return(IDX_HEAD(Q) == IDX_UNDEF && IDX_TAIL(Q) == IDX_UNDEF);
}

boolean IsFull(Queue Q){
    return((((IDX_TAIL(Q) - IDX_HEAD(Q) + CAPACITY) % CAPACITY) + 1) == CAPACITY);
}

void CreateEmpty(Queue *Q){
    IDX_HEAD(*Q) = IDX_UNDEF;
    IDX_TAIL(*Q) = IDX_UNDEF;
}

void Enqueue(Queue *Q, infotype X){
    if(IsEmpty(*Q)){
        IDX_HEAD(*Q) = 0;
        IDX_TAIL(*Q) = IDX_HEAD(*Q);
        Elmt(*Q, IDX_HEAD(*Q) + (IDX_TAIL(*Q) - IDX_HEAD(*Q))) = X;
    }
    else if(!IsFull(*Q)){
        Elmt(*Q, (IDX_HEAD(*Q) + (IDX_TAIL(*Q) - IDX_HEAD(*Q)) + 1) % CAPACITY) = X;
        IDX_TAIL(*Q)++;
    }
}

void Dequeue(Queue *Q, infotype *X){
    *X = HEAD(*Q);
    if(IDX_TAIL(*Q) - IDX_HEAD(*Q) + 1 == 1)
        CreateEmpty(Q);
    else if(!IsEmpty(*Q))
        IDX_HEAD(*Q) = (IDX_HEAD(*Q) + 1) % CAPACITY;
}

void PrintQueue(Queue Q){
    infotype dum;
    int length = IDX_TAIL(Q) - IDX_HEAD(Q) + 1;
    while(length--){
        Dequeue(&Q, &dum);
        printf("%d %d\n", Prio(dum), Info(dum));
    }
    printf("#\n");
}