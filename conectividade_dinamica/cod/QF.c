static int id[1000];
static int N;

#include <stdio.h>
#include "../bib/QF.h"


void QF_init(int size) {
    N = size;
    for(int i = 0; i < N; i++)
        id[i] = i;
}

void QF_union(int p, int q) {
    int t = q;
    for(int i = 0; i < N; i++)
        if(QF_connected(i, t))
            id[i] = id[p];
}

int QF_find(int p) {
    return(id[p]);
}

bool QF_connected(int p, int q) {
    return(QF_find(p) == QF_find(q));
}

void QF_components( ) {
    printf("\n");
    for(int i = 0; i < N; i++) {
        if(id[i] != -1) {
            printf("%d ", i);
            for(int j = i+1; j < N; j++) {
                if(QF_connected(i, j)) {
                    printf("%d ", j);
                    id[j] = -1;
                }
            }
            id[i] = -1;
            printf("\n");
        }
    }
}