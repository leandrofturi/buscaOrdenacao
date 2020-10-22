#include <stdlib.h>
#include <stdio.h>
#include "item.h"
#include "stack/stack.h"

#define push2(S, A, B) push(S, B); push(S, A)


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

void quick_sort(Item *a, int lo, int hi) {
    if(hi <= lo)
        return;

    int N = hi-lo+1;
    tStack *S = init_stack(N);
    if(S == NULL) return;

    push2(S, lo, hi);
    while(!empty_stack(S)) {
        lo = pop(S);
        hi = pop(S);
        if(hi <= lo)
            continue; // Could add cutoff here.
        int i = partition(a, lo, hi);
        if(i-lo > hi-i) { // Test the size of sub-arrays.
            push2(S, lo, i-1); // Push the larger one.
            push2(S, i+1, hi); // Sort the smaller one first.
        }
        else {
            push2(S, i+1, hi);
            push2(S, lo, i-1);
        }
    }
    del_stack(S);
}

void sort(Item *a, int lo, int hi) {
    quick_sort(a, lo, hi);
}