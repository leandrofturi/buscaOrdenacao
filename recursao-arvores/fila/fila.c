#include <stdlib.h>
#include <stdio.h>
#include "fila.h"

struct tFila {
    int primeiro, nDados;
    void *dados[NMAX];
};
typedef struct tFila tFila;


tFila *cria_fila(int sz) {
    tFila* F = (tFila*) malloc(sizeof(tFila*) + sz*NMAX);
    F->primeiro = F->nDados = 0;
    return(F);
}

void deleta_fila(tFila *F) {
    free(F);
}

void enfilera(tFila *F, void* dado) {
    if(F->nDados >= NMAX)
        return;

    F->dados[(F->primeiro + F->nDados) % NMAX] = dado;
    F->nDados ++;
}

void *desenfilera(tFila *F) {
    if(F->nDados == 0)
        return(NULL);

    F->nDados --;
    F->primeiro = (F->primeiro + 1) % NMAX;
    return(F->dados[F->primeiro-1]);
}

int vazia_fila(tFila* F) {
    return(F->nDados == 0);
}
