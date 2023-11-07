#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

void createGraph(Graph *g){
    int i,j;
    createMatrix(20,20,g);
    for(i = 0; i<ROW_EFF(*g); i++){
        for(j = 0; j<COL_EFF(*g); i++){
            ELMT(*g,i,j) = 0;
        }
    }
}