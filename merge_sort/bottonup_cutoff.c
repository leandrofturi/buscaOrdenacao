#include <stdlib.h>
#include <stdbool.h>
#include "item.h"

#define CUTOFF 5
#define SZ2 (sz+sz)
#define MIN(X,Y) ((X < Y) ? (X) : (Y))


void merge(Item *a, Item *aux, int lo, int mid, int hi) {
    for (int k = lo; k <= hi; k++)
        aux[k] = a[k];

    int i = lo, j = mid + 1;
    for(int k = lo; k <= hi; k++) {
        if(i > mid)
            a[k] = aux[j++];
        else if(j > hi)
            a[k] = aux[i++];
        else if (less(aux[j], aux[i]))
            a[k] = aux[j++];
        else
            a[k] = aux[i++];
    }
}

void insert_sort(Item *a, int lo, int hi) {
    int i;
    for(i = hi; i > lo; i--)
        compexch(a[i-1], a[i]);
    for(i = lo+2; i <= hi; i++) {
        int j = i;
        Item v = a[i];
        for(; less(v, a[j-1]); j--)
            a[j] = a[j-1];
        a[j] = v;
    }
}

void sort(Item *a, int lo, int hi) {
    int N = (hi - lo) + 1;
    int y = N - 1;
    Item *aux = (Item*) malloc(N * sizeof(Item));
    for(int i = lo; i < hi; i+=CUTOFF)
        insert_sort(a, i, i+CUTOFF);
    
    for(int sz = CUTOFF; sz < N; sz = SZ2) {
        for(int lo = 0; lo < N-sz; lo += SZ2) {
            int x = lo + SZ2 - 1;
            merge(a, aux, lo, lo+sz-1, MIN(x,y));
        }
    }
    free(aux);
}