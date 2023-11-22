#include "wordmachine.h"
#include "datetime.h"

typedef struct nodeBalasan* Balasan;

typedef struct nodeBalasan {
    int idkicau;
    int idparent;
    Word author;
    listAnak la;
    DATETIME datetime;
} NodeBalasan;

typedef struct listAnak{
    
}
