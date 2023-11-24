#include "../foto.h"
Matrix C, S;

int main(){
    createMatrixColor(&C);
    createMatrixSimbol(&S);
    displayMatrix(C);
    displayMatrix(S);
}