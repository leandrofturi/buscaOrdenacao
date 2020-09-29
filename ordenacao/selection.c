#include "item.h"


void sort(Item *a, int lo, int hi) {
    int k;
    for(int i = lo; i < hi; i++) {
        k = i;
        for(int j = i+1; j < hi; j++) {
            if(less(j, k))
                k = j;
        }
        exch(a[i], a[k]);
    }
}