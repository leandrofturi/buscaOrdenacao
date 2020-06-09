#pragma once
#include <stdlib.h>


typedef struct tEncadeada tEncadeada;


// Inicialização e finalização
tEncadeada *cria_encadeada( );
void deleta_encadeada(tEncadeada *E);

// Inserção e remoção de elementos
void insere_encadeada(void *dado, tEncadeada *E);
void remove_encadeada(void *dado, tEncadeada *E);
int contem_encadeada(void *dado, tEncadeada *E, int (*igual)(void*, void*));

// Propriedades
int tamanho_encadeada(tEncadeada *E);
int vazia_encadeada(tEncadeada *E);
void imprime_encadeada(tEncadeada *E, void (*print)(void*));