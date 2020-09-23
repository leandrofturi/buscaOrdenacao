#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arvore/arvore.h"


int main(int argc, char *argv[]) {
    srand(time(NULL));
    int N = 100;
    tArvore *A = cria_arvore( );
    for(size_t j = 0; j < 10; j++) {
        for(size_t i = 0; i < N; i++)
            insere_arvore(A, rand());
        printf("%d\n", altura_arvore(A));
    }
    deleta_arvore(A);
    return(0);
}