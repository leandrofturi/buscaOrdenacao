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

int median_3(Item *a, int lo, int hi) {
    int x = (rand() % (hi - lo)) + lo;
    int y = (rand() % (hi - lo)) + lo;
    int z = (rand() % (hi - lo)) + lo;

    if(leq(a[x], a[y]) && leq(a[y], a[z])) return(y);  // x y z
    if(leq(a[x], a[z]) && leq(a[z], a[y])) return(z);  // x z y
    if(leq(a[y], a[x]) && leq(a[x], a[z])) return(x);  // y x z
    if(leq(a[y], a[z]) && leq(a[z], a[x])) return(z);  // y z x
    if(leq(a[z], a[x]) && leq(a[x], a[y])) return(x);  // z x y
    return(y);                                         // z y y
}

void quick_sort(Item *a, int lo, int hi) {
    if(hi <= lo)
        return;
    if(hi <= lo + CUTOFF - 1) {
        insert_sort(a, lo, hi);
        return;
    }

    int median = median_3(a, lo, hi);
    exch(a[lo], a[median]);
    int j = partition(a, lo, hi);
    quick_sort(a, lo, j-1);
    quick_sort(a, j+1, hi);
}

void sort(Item *a, int lo, int hi) {
    quick_sort(a, lo, hi);
}