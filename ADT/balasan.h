#include <stdlib.h>
#include "wordmachine.h"
#include "datetime.h"

typedef struct nodeBalasan* Balasan;

typedef struct nodeBalasan {
    int idbalasan;
    int idparent;
    Word author;
    Balasan leftChild;
    Balasan rightSibling;
    DATETIME datetime;
} NodeBalasan;

#define IDBALASAN(p) (p)->idbalasan;
#define IDPARENTBALASAN(p) (p)->idparent;
#define AUTHORBALASAN(p) (p)->author;
#define SIBLINGBALASAN(p) (p)->rightSibling;
#define CHILDBALASAN(p) (p)->leftChild;
#define DATETIMEBALASAN(p) (p)->datetime;


Balasan newNodeBalasan(int idbalasan, int idparent, Word author, DATETIME datetime);
void newChildBalasan(Balasan parent, Balasan newChild);