#include <stdio.h>
#include <stdlib.h>
#include "bib/QU_W_PC.h"


int main(int argc, char *argv[]) {
    int p, q, N = atoi(argv[1]), M = atoi(argv[2]);
    QU_W_PC_init(N);
    for(int i = 0; i < M; i++) {
        scanf("%d %d", &p, &q);
        if(!QU_W_PC_connected(p, q))
            QU_W_PC_union(p, q);
    }
    QU_W_PC_components( );
}
