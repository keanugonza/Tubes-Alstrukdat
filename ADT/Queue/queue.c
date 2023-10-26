#include <stdio.h>
#include "queue.h"

void CreateQueue(Queue *q){
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

boolean isEmpty(Queue q){
    return(IDX_HEAD(q) == IDX_UNDEF && IDX_TAIL(q) == IDX_UNDEF);
}

boolean isFull(Queue q){
    return(IDX_HEAD(q) == (IDX_TAIL(q) + 1) % CAPACITY);
}

int length(Queue q){
    if(isEmpty(q))
        return 0;
    else
        return(((IDX_TAIL(q) + CAPACITY - IDX_HEAD(q)) % CAPACITY) + 1);
}

void enqueue(Queue *q, ElType val){
    if(isEmpty(*q)){
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = IDX_HEAD(*q);
        TAIL(*q) = val;
    }
    else{
        IDX_TAIL(*q) = (IDX_TAIL(*q) + 1) % CAPACITY;
        TAIL(*q) = val;
    }
}

void dequeue(Queue *q, ElType *val){
    *val = HEAD(*q);
    IDX_HEAD(*q) = (IDX_HEAD(*q) + 1) % CAPACITY;
}

void displayQueue(Queue q){
    if(isEmpty(q)){
        printf("[]\n");
    }
    else{
        int t = length(q);
        ElType dum;
        printf("[");
        while(t--){
            dequeue(&q, &dum);
            printf("%d", dum);
            if(t > 0)
                printf(",");
        }
        printf("]\n");
    }
}