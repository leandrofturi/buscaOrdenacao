#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

tStack inicializa_pilha() {
    tStack S;
    S.count = 0;
    return(S);
}

void empilha(tStack* S, void* dado) {
    S->elements[S->count] = dado;
    S->count ++;
}

void* desempilha(tStack* S) {
    S->count --;
    return(S->elements[S->count]);
}

int vazia_pilha(tStack S) {
    return(S.count == 0);
}

void imprime_pilha(tStack S, void (*print)(void*)) {
    for(size_t i = 0; i < S.count; i++)
        print(S.elements[i]);
    printf("\n");
}
