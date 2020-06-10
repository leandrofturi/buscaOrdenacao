#include "pilha.h"
#include "../encadeada/encadeada.c"


tPilha *cria_pilha( ) {
    return(cria_encadeada( ));
}

void deleta_pilha(tPilha *P) {
    deleta_encadeada(P);
}

tPilha* empilha(void *dado, tPilha *P) {
    return(insere_encadeada(dado, P));
}

void* desempilha(tPilha *P) {
    return(remove_ultimo_encadeada(P));
}

int contem_pilha(void *dado, tPilha *P, int (*igual)(void*, void*)) {
    return(contem_encadeada(dado, P, igual));
}

int tamanho_pilha(tPilha *P) {
    return(tamanho_encadeada(P));
}

int vazia_pilha(tPilha *P) {
    return(vazia_encadeada(P));
}

void imprime_pilha(tPilha *P, void (*print)(void*)) {
    imprime_encadeada(P, print);
}