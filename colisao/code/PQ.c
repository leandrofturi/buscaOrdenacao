#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "event.h"
#include "PQ.h"

#define key(A) get_time(A)
#define greater(A, B) (key(A) > key(B))
#define exch(A, B) { Event *t = A; A = B; B = t; }


// TODO: Aqui você deve implementar uma fila com prioridade mínima para
//       ordenar os eventos por tempo, isto é, o evento com o menor tempo tem
//       a maior prioridade. Veja as funções definidas em 'event.h' para
//       a manipulação das estruturas de evento. A princípio, as funções já
//       existentes em 'event.h' são suficientes para implementar a simulação,
//       isto é, você não precisa implementar mais nada lá.
//
//       Você é livre para implementar a fila com prioridade da forma que quiser
//       mas é recomendado usar um min-heap para obter um bom desempenho. As
//       simulações maiores geram uma quantidade grande de eventos: um
//       limite superior frouxo (mas seguro) para o número máximo simultâneo de
//       eventos é N^3, aonde N é o número de partículas.

// TODO: Crie a struct pq.
struct pq {
    Event **events;
    int max_N, N;
};

/*
 * Cria uma nova fila de prioridade mínima com o limite de elementos informado.
 */
PQ* PQ_create(int max_N) {
    // TODO: Implemente a criação da fila que suporta no máximo o número de
    //       de eventos informados no parâmetro.

    PQ *pq = (PQ*) malloc(sizeof(PQ));
    pq->max_N = max_N;
    pq->N = -1;
    pq->events = (Event**) malloc(max_N*sizeof(Event*));
    return pq;
}

/*
 * Libera a memória da fila.
 */
void PQ_destroy(PQ *pq) {
    // TODO: Implemente essa função que libera toda a memória da fila,
    //       destruindo inclusive os eventos que estavam na fila.

    for(size_t i = 0; i <= pq->N; i++) {
        if(pq->events[i] != NULL)
            destroy_event(pq->events[i]);
    }
    free(pq->events);
    free(pq);
}

/*
 * Insere o evento na fila segundo o seu tempo.
 */
static void fix_up(PQ *pq, int k) { // swim up
    while(k > 0 && greater(pq->events[k/2], pq->events[k])) {
        exch(pq->events[k], pq->events[k/2]);
        k = k/2;
    }
}

void PQ_insert(PQ *pq, Event *e) {
    // TODO: Implemente essa função que insere o evento dado na fila segundo
    //       o tempo do evento.
    //       Assuma que 'e' não é nulo. É importante testar overflow (inserção
    //       em uma fila que já contém o número máximo de eventos) para evitar
    //       dores de cabeça com acessos inválidos na memória.

    if(pq->N == pq->max_N-1)
        return;

    pq->N++;
    pq->events[pq->N] = e;
    fix_up(pq, pq->N);
}

/*
 * Remove e retorna o evento mais próximo.
 */
static void fix_down(PQ *pq, int sz, int k){
    while(2*k <= sz) {
        int j = 2*k;
        if(j < sz && greater(pq->events[j], pq->events[j+1]))
            j++;
        if(!greater(pq->events[k], pq->events[j]))
            break;
        exch(pq->events[k], pq->events[j]);
        k = j;
    }
}

Event* PQ_delmin(PQ *pq) {
    // TODO: Implemente essa função que remove o evento com o menor tempo da
    //       fila e o retorna.
    if(PQ_is_empty(pq))
        return NULL;

    Event *min = pq->events[0];
    exch(pq->events[0], pq->events[pq->N]);
    pq->N--;
    fix_down(pq, pq->N, 0);
    return min;
}

/*
 * Testa se a fila está vazia.
 */
bool PQ_is_empty(PQ *pq) {
    // TODO: Implemente essa função.
    return PQ_size(pq) == 0;
}

/*
 * Retorna o tamanho da fila.
 */
int PQ_size(PQ *pq) {
    // TODO: Implemente essa função.
    return pq->N+1;
}
