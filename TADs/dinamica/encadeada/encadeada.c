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

tEncadeada* insere_encadeada(void *dado, tEncadeada *E) {
    if(dado == NULL || E == NULL)
        return(E);

    if(E->dado == NULL) {
        E->dado = dado;
        E->prox = NULL;
    }
    else {
        tEncadeada *p = E;
        while(p->prox != NULL)
            p = p->prox;
        p->prox = cria_encadeada( );
        p->prox->dado = dado;
        p->prox->prox = NULL;
    }
    return(E);
}

tEncadeada* remove_encadeada(void *dado, tEncadeada *E, int (*igual)(void*, void*)) {
    if(dado == NULL || E == NULL)
        return(E);

    tEncadeada *p = E, *q = E->prox;
    if(igual(p->dado, dado)) {
        free(p);
        return(q);
    }
    for(; q != NULL; q = q->prox) {
        if(igual(q->dado, dado)) {
            p->prox = q->prox;
            free(q);
            return(E);
        }
    }
}

int contem_encadeada(void *dado, tEncadeada *E, int (*igual)(void*, void*)) {
    for(tEncadeada *p = E; p != NULL; p = p->prox)
        if(igual(p->dado, dado))
            return(1);
    return(0);
}

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

/*

// TESTES

void print_double(void *dado) {
    printf(" %lf", *(double*) dado);
}

int igual_double(void *dado1, void *dado2) {
    return(*(double*) dado1 == *(double*) dado2);
}

int main() {

    tEncadeada *E;
    E = cria_encadeada();
    printf("%d", tamanho_encadeada(E));
    double a = 5.5;
    double b = 4.5;
    E = insere_encadeada(&a, E);
    E = insere_encadeada(&b, E);
    E = remove_encadeada(&a, E, igual_double);
    imprime_encadeada(E, print_double);
    printf("%d", tamanho_encadeada(E));
    deleta_encadeada(E);

    return(0);
}
*/