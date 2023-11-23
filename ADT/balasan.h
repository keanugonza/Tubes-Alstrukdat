#include <stdlib.h>
#include "wordmachine.h"
#include "datetime.h"

#ifndef BALASAN_H
#define BALASAN_H

typedef struct nodeBalasan* Balasan;

typedef struct nodeBalasan {
    int idbalasan;
    Word author;
    Word isiBalasan;
    Balasan leftChild;
    Balasan rightSibling;
    DATETIME datetime;
} NodeBalasan;

#define IDBALASAN(p) (p)->idbalasan
#define ISIBALASAN(p) (p)->isiBalasan
#define AUTHORBALASAN(p) (p)->author
#define SIBLINGBALASAN(p) (p)->rightSibling
#define CHILDBALASAN(p) (p)->leftChild
#define DATETIMEBALASAN(p) (p)->datetime


Balasan newNodeBalasan(int idbalasan,Word isibalasan, Word author, DATETIME datetime);
void newChildBalasan(Balasan parent, Balasan newChild);
Balasan findByIdBalasan(Balasan parent, int id);
int findMaxIdBalasan(Balasan parentbalasan);
void displayBalasan(Balasan cbalasannode);

#endif