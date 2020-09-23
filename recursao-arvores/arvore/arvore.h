#pragma once

typedef struct tArvore tArvore;

// Inicialização e finalização
tArvore *cria_arvore( );
void deleta_arvore(tArvore *A);

// Inserção e remoção de elementos
void insere_arvore(tArvore *A, int dado);
int contem_arvore(tArvore *A, int dado);

// Propriedades
int tamanho_arvore(tArvore *A);
int altura_arvore(tArvore *A);

// Caminhamento Recursivo
void rec_preordem_arvore(tArvore *A, void (*visit)(int));
void rec_inordem_arvore(tArvore *A, void (*visit)(int));
void rec_posordem_arvore(tArvore *A, void (*visit)(int));

// Caminhamento N Recursivo
void preordem_arvore(tArvore *A, void (*visit)(int));
void inordem_arvore(tArvore *A, void (*visit)(int));
void posordem_arvore(tArvore *A, void (*visit)(int));

void transversal_fila(tArvore *A, void (*visit)(int));