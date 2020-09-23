#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

struct tPilha {
    int count;
    void* elements[NMAX];
};
typedef struct tPilha tPilha;


tPilha* inicializa_pilha(int sz) {
    tPilha* P = (tPilha*) malloc(sizeof(tPilha*) + sz*NMAX);
    P->count = 0;
    return(P);
}

void deleta_pilha(tPilha *P) {
    free(P);
}

void empilha(tPilha* P, void* dado) {
    if(P->count >= NMAX)
        return;
    P->elements[P->count] = dado;
    P->count ++;
}

void* desempilha(tPilha* P) {
    if(P->count == 0)
        return(NULL);
    P->count --;
    return(P->elements[P->count]);
}

void* espiar(tPilha* P) {
    return(P->elements[P->count-1]);
}

int vazia_pilha(tPilha *P) {
    return(P->count == 0);
}

void imprime_pilha(tPilha *P, void (*print)(void*)) {
    for(size_t i = 0; i < P->count; i++)
        print(P->elements[i]);
    printf("\n");
}
