#include "item.h"


void sort(Item *a, int lo, int hi) {
    for(int i = lo+1; i < hi; i++) {
        for(int j = i; j > lo && less(a[j], a[j-1]); j--) {
            exch(a[j], a[j-1]);
        }
    }
}
