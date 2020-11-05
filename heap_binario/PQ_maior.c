#include <stdio.h>
#include <stdlib.h>
#include "PQ.h"


struct pq {
    Item *a;
    int max_N, N;
};


PQ* PQ_create(int max_N) {
    PQ *pq = (PQ*) malloc(sizeof(PQ));
    pq->max_N = max_N;
    pq->N = -1;
    pq->a = (Item*) malloc(max_N*sizeof(Item));
    return pq;
}

/*
 * Libera a memória da fila.
 */
void PQ_destroy(PQ *pq) {
    free(pq->a);
    free(pq);
}

/*
 * Insere o evento na fila segundo o seu tempo.
 */
static void fix_up(PQ *pq, int k) { // swim up
    while(k > 0 && less(pq->a[k/2], pq->a[k])) {
        exch(pq->a[k], pq->a[k/2]);
        k = k/2;
    }
}

void PQ_insert(PQ *pq, Item e) {
    if(pq->N == pq->max_N-1)
        return;

    pq->N++;
    pq->a[pq->N] = e;
    fix_up(pq, pq->N);
}

/*
 * Remove e retorna o evento mais próximo.
 */
static void fix_down(PQ *pq, int sz, int k){
    while(2*k <= sz) {
        int j = 2*k;
        if(j < sz && less(pq->a[j], pq->a[j+1]))
            j++;
        if(!less(pq->a[k], pq->a[j]))
            break;
        exch(pq->a[k], pq->a[j]);
        k = j;
    }
}

Item PQ_del(PQ *pq) {
    Item min = pq->a[0];
    exch(pq->a[0], pq->a[pq->N]);
    pq->N--;
    fix_down(pq, pq->N, 0);
    return min;
}

/*
 * Testa se a fila está vazia.
 */
int PQ_is_empty(PQ *pq) {
    return pq->N == -1;
}

/*
 * Retorna o tamanho da fila.
 */
int PQ_size(PQ *pq) {
    return pq->N;
}

int main() {
    PQ *pq = PQ_create(10);
    for(int i = 10; i > 0; i--)
        PQ_insert(pq, i);
    PQ_insert(pq, 0);
    printf("%d\n", PQ_del(pq));
    printf("%d\n", PQ_del(pq));
    return 0;
}