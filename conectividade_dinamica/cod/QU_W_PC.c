static int id[1000];
static int sz[1000];
static int N;

#include <stdio.h>
#include "../bib/QU_W_PC.h"


void QU_W_PC_init(int size) {
    N = size;
    for(int i = 0; i < N; i++) {
        id[i] = i;
        sz[i] = 1;
    }
}

void QU_W_PC_union(int p, int q) {
    if(sz[p] < sz[q]) {
        id[QU_W_PC_find(p)] = id[QU_W_PC_find(q)];
        sz[id[QU_W_PC_find(p)]]++;
    }
    else {
        id[QU_W_PC_find(q)] = id[QU_W_PC_find(p)];
        sz[id[QU_W_PC_find(q)]]++;
    }
}

int QU_W_PC_find(int p) {
    while(p != id[p])
        p = id[p];
    return p;
}

bool QU_W_PC_connected(int p, int q) {
    return(QU_W_PC_find(p) == QU_W_PC_find(q));
}

void QU_W_PC_components( ) {
    int tmp[N];
    for(int i = 0; i < N; i++)
        tmp[i] = 1;

    printf("\n");
    for(int i = 0; i < N; i++) {
        if(tmp[i]) {
            printf("%d ", i);
            for(int j = i+1; j < N; j++) {
                if(QU_W_PC_connected(i, j)) {
                    printf("%d ", j);
                    tmp[j] = 0;
                }
            }
            tmp[i] = 0;
            printf("\n");
        }
    }
}