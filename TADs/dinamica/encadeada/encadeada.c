#include <stdlib.h>
#include <stdio.h>
#include "encadeada.h"


struct tEncadeada {
    void *dado;
	tEncadeada *prox;
};


tEncadeada *cria_encadeada( ) {
    tEncadeada *E = (tEncadeada*) malloc(sizeof(tEncadeada));
    E->dado = NULL;
    return(E);
}

void deleta_encadeada(tEncadeada *E) {
    tEncadeada *p = E;
    tEncadeada *q;
    while(p != NULL) {
        q = p;
        p = p->prox;
        free(q);
    }
}

void insere_encadeada(void *dado, tEncadeada *E) {
    if(dado == NULL || E == NULL)
        return;

    if(E->dado == NULL) {
        E->dado = dado;
        E->prox = NULL;
        return;
    }

    tEncadeada *p = E;
    while(p->prox != NULL)
        p = p->prox;
    p->prox = cria_encadeada( );
    p->prox->dado = dado;
    p->prox->prox = NULL;
}

void remove_encadeada(void *dado, tEncadeada *E) {
    if(dado == NULL || E == NULL)
        return;

    if(E->dado == dado) {
        // Implementar
    }
    for(tEncadeada *q = E, *p = E->prox; p != NULL; p = p->prox) {
        if(p->dado == dado) {
            q->prox = p->prox;
            free(p);
            return;
        }
    }
}

int contem_encadeada(void *dado, tEncadeada *E, int (*igual)(void*, void*)) {
    for(tEncadeada *p = E; p != NULL; p = p->prox)
        if(igual(p->dado, dado))
            return(1);
    return(0);
}

// Propriedades
int tamanho_encadeada(tEncadeada *E) {
    int n = 0;
    if(E->dado != NULL)
        for(tEncadeada *p = E; p != NULL; p = p->prox)
            n++;
    return(n);
}

int vazia_encadeada(tEncadeada *E) {
    return(E->dado == NULL);
}

// <tipo-de-retorno> (*<nome-da-variável>)(<parâmetros>)
void imprime_encadeada(tEncadeada *E, void (*print)(void*)) {
    printf("\n");
    tEncadeada *p = E;
    while(p != NULL) {
        print(p->dado);
        p = p->prox;
    }
    printf("\n");
}

void print_double(void *dado) {
    printf(" %lf", *(double*) dado);
}

int main() {

    tEncadeada *E;
    E = cria_encadeada();
    printf("%d", tamanho_encadeada(E));
    double a = 5.5;
    double b = 5.5;
    insere_encadeada(&a, E);
    insere_encadeada(&b, E);
    remove_encadeada(&a, E);
    imprime_encadeada(E, print_double);
    printf("%d", tamanho_encadeada(E));
    deleta_encadeada(E);

    return(0);
}