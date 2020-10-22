#include <stdlib.h>
#include "item.h"
#define CUTOFF 30


int partition(Item *a, int lo, int hi) {
    int i = lo, j = hi+1;
    Item v = a[lo];

    while(1) {
        while(less(a[++i], v))
            if(i == hi)
                break;
        while(less(v, a[--j]))
            if(j == lo)
                break;
        if(i >= j)
            break;
        exch(a[i], a[j]);
    }
    exch(a[lo], a[j]);

    return(j);
}

void insert_sort(Item *a, int lo, int hi) {
    int i, j, N = hi-lo+1;
    for(i = 1; i < N; i++)
        for(j = i; j > 0; j--)
            if(a[j-1] > a[j]) {
                a[j-1] += a[j];
                a[j] = a[j-1] - a[j];
                a[j-1] -= a[j];
            }
            else break;
}

void quick_sort(Item *a, int lo, int hi) {
    if(hi <= lo)
        return;

    if(hi <= lo + CUTOFF - 1) {
        insert_sort(a, lo, hi);
        return;
    }

    int j = partition(a, lo, hi);
    quick_sort(a, lo, j-1);
    quick_sort(a, j+1, hi);
}

void sort(Item *a, int lo, int hi) {
    quick_sort(a, lo, hi);
}