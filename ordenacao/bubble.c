#include <stdbool.h>
#include "item.h"


void sort(Item *a, int lo, int hi) {
    bool swapped;
    for(int i = lo; i < hi; i++) {
        swapped = false;
        for(int j = lo; j < hi-1; j++) {
            if(less(a[j+1], a[j])) {
                exch(a[j], a[j+1]);
                swapped = true;
            }
        }
        if(!swapped) break;
    }
}
