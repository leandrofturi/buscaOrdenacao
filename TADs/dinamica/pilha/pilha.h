#pragma once
#include <stdlib.h>
#include "../encadeada/encadeada.h"


typedef tEncadeada tPilha;


// Inicialização e finalização
tPilha *cria_pilha( );
void deleta_pilha(tPilha *P);

// Inserção e remoção de elementos
tPilha* empilha(void *dado, tPilha *P);
void* desempilha(tPilha *P);
int contem_pilha(void *dado, tPilha *P, int (*igual)(void*, void*));

// Propriedades
int tamanho_pilha(tPilha *P);
int vazia_pilha(tPilha *P);
void imprime_pilha(tPilha *P, void (*print)(void*));