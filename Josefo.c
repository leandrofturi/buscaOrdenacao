#include <stdio.h>
#include <stdlib.h>
#include "bib/ProblemadeJosefo.h"


int main(int argc, char *argv[]) {

    int N = atoi(argv[1]);
    int M = atoi(argv[2]);

    int I[N];
    inicializar_I(I, N);
    printf("%d\n", eleicao_I(I, N, M));

    char B[(N/8)+1];
    inicializar_B(B, N);
    printf("%d\n", eleicao_B(B, N, M));
    
    return(0);
}