#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "item.h"

extern void sort(Item *a, int lo, int hi);


Item* read(int N) {
    Item *a = (Item*) malloc(N*sizeof(Item));
    if(a == NULL) {
        printf("out of memory!\n");
        return(NULL);
    }

    char in[N];
    for(int i = 0; i < N; i++) {
        fgets(in, N, stdin);
        a[i] = char_2Item(in);
    }
    return(a);
}

void analysis(Item *a, int N) {
    clock_t start = clock();
    sort(a, 0, N);
    clock_t end = clock();
    //printf("elapsed time is %lf\n", ((double) end-start) / CLOCKS_PER_SEC);
    printf("%lf\n", ((double) end-start) / CLOCKS_PER_SEC);
}

void print(Item *a, int N) {
    printf("\n");
    for(int i = 0; i < N; i++) {
        printItem(a[i]);
        printf(" ");
    }
    printf("\n");
}


int main(int argc, char *argv[]) {
    int N = atoi(argv[1]);
    Item *a  = read(N);
    analysis(a, N);
    //print(a, N);
    return(0);
}
