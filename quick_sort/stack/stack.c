#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

struct tStack {
    int N;
    int NMAX;
    Item* elements;
};
typedef struct tStack tStack;


tStack* init_stack(int sz) {
    tStack* S = (tStack*) malloc(sizeof(tStack));
    if(S == NULL) {
        printf("out of memory!\n");
        return(NULL);
    }
    S->elements = (Item*) malloc(sz*sizeof(Item));
    if(S->elements == NULL) {
        printf("out of memory!\n");
        return(NULL);
    }
    S->NMAX = sz;
    S->N = 0;
    return(S);
}

void del_stack(tStack *S) {
    free(S->elements);
    free(S);
}

void push(tStack *S, Item item) {
    if(S->N == S->NMAX)
        return;
    S->elements[S->N] = item;
    S->N++;
}

Item pop(tStack *S) {
    if(S->N == 0)
        return(-1);
    S->N --;
    return(S->elements[S->N]);
}

Item peek(tStack *S) {
    return(S->elements[S->N-1]);
}

int empty_stack(tStack *S) {
    return(S->N == 0);
}

void print_stack(tStack *S) {
    for(int i = 0; i < S->N; i++) {
        printItem(S->elements[i]);
        printf(" ");
    }
    printf("\n");
}
