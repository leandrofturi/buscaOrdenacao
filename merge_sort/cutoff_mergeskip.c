#include <stdlib.h>
#include <stdbool.h>
#include "item.h"

#define CUTOFF 50


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

void merge_sort(Item *a, Item *aux, int lo, int hi) {
    if (hi <= lo + CUTOFF - 1) {
        insert_sort(a, lo, hi);
        return;
    }
    int mid = lo + (hi - lo) / 2;
    merge_sort(a, aux, lo, mid);
    merge_sort(a, aux, mid + 1, hi);
    if(!less(a[mid+1], a[mid]))
        return;
    merge(a, aux, lo, mid, hi);
}

void sort(Item *a, int lo, int hi) {
    int n = (hi - lo) + 1;
    Item *aux = (Item*) malloc(n*sizeof(Item));
    merge_sort(a, aux, lo, hi);
    free(aux);
}
