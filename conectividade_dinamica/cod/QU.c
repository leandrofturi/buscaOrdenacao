static int id[1000];
static int N;

#include <stdio.h>
#include "../bib/QU.h"


void QU_init(int size) {
    N = size;
    for(int i = 0; i < N; i++)
        id[i] = i;
}

void QU_union(int p, int q) {
    id[QU_find(p)] = QU_find(q); // Raiz de p recebe raiz de q
}

int QU_find(int p) {
    while(p != id[p])
        p = id[p];
    return p;
}

bool QU_connected(int p, int q) {
    return(QU_find(p) == QU_find(q));
}

void QU_components( ) {
    int tmp[N];
    for(int i = 0; i < N; i++)
        tmp[i] = 1;

    printf("\n");
    for(int i = 0; i < N; i++) {
        if(tmp[i]) {
            printf("%d ", i);
            for(int j = i+1; j < N; j++) {
                if(QU_connected(i, j)) {
                    printf("%d ", j);
                    tmp[j] = 0;
                }
            }
            tmp[i] = 0;
            printf("\n");
        }
    }
}