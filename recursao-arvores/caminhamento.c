#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arvore/arvore.h"
#include "fila/fila.h"


void visit(int dado) {
    printf("%d ", dado);
}

int main(int argc, char *argv[]) {
    tArvore *A = cria_arvore( );
    /*
    insere_arvore(A, 6);
    insere_arvore(A, 2);
    insere_arvore(A, 7);
    insere_arvore(A, 1);
    insere_arvore(A, 4);
    insere_arvore(A, 9);
    insere_arvore(A, 3);
    insere_arvore(A, 5);
    insere_arvore(A, 8);

    transversal_fila(A, visit);
    */

    /*
    for(int i = 0; i < NMAX/10; i++)
        insere_arvore(A, i);
    
    
    clock_t start = clock();
    rec_preordem_arvore(A, visit);
    rec_inordem_arvore(A, visit);
    rec_posordem_arvore(A, visit);
    clock_t end = clock();
    printf("Elapsed time is %lf\n", ((double) end-start) / CLOCKS_PER_SEC);

    start = clock();
    preordem_arvore(A, visit);
    inordem_arvore(A, visit);
    posordem_arvore(A, visit);
    end = clock();
    printf("Elapsed time is %lf\n", ((double) end-start) / CLOCKS_PER_SEC);
    */

    deleta_arvore(A);
    return(0);
}