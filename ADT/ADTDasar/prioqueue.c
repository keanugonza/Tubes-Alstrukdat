#include <stdlib.h>
#include <stdio.h>
#include "prioqueue.h"

boolean IsEmpty(Queue Q){
    return(IDX_HEAD(Q) == IDX_UNDEF && IDX_TAIL(Q) == IDX_UNDEF);
}

boolean IsFull(Queue Q){
    return((IDX_TAIL(Q) - IDX_HEAD(Q) + 1) == CAPACITY);
}

int length(Queue Q){
    if(IsEmpty(Q))
        return 0;
    else
        return(IDX_TAIL(Q) - IDX_HEAD(Q) + 1);
}

void CreateEmpty(Queue *Q){
    IDX_HEAD(*Q) = IDX_UNDEF;
    IDX_TAIL(*Q) = IDX_UNDEF;
}

void Enqueue(Queue *Q, infotype X){
    if(IsEmpty(*Q)){
        IDX_HEAD(*Q) = 0;
        IDX_TAIL(*Q) = 0;
        TAIL(*Q) = X;
    }
    else if(!IsFull(*Q)){
        int n = length(*Q), idx = IDX_TAIL(*Q);
        while((Prio(X) > Prio((*Q).buffer[idx])) && (n > 0)){
            (*Q).buffer[idx + 1] = (*Q).buffer[idx];
            idx--;
            n--;
        }
        (*Q).buffer[idx + 1] = X;
        IDX_TAIL(*Q) += 1;
    }
}

void Dequeue(Queue *Q, infotype *X){
    *X = HEAD(*Q);
    if(IDX_HEAD(*Q) == IDX_TAIL(*Q))
        CreateEmpty(Q);
    else{
        for(int i = 0; i <= IDX_TAIL(*Q); i++){
            (*Q).buffer[i] = (*Q).buffer[i + 1];
        }
        IDX_TAIL(*Q)--;
    }
}

void PrintQueue(Queue Q){
    infotype dum;
    int len = length(Q);
    while(len--){
        Dequeue(&Q, &dum);
        printf("%d %d\n", Prio(dum), Info(dum));
    }
    printf("#\n");
}