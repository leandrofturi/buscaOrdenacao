#include <stdio.h>
#include "bib/CrivodeEratostenes.h"


int main(int argc, char *argv[]) {

    int N = atoi(argv[1])+1;

    int I[N];
    inicializar_I(I, N);
    marcarMultiplos_I(I, N);
    imprimePrimos_I(I, N);

    char C[N];
    inicializar_C(C, N);
    marcarMultiplos_C(C, N);
    imprimePrimos_C(C, N);

    char B[N/8+1];
    inicializar_B(B, N);
    marcarMultiplos_B(B, N);
    imprimePrimos_B(B, N);
    
    return(0);
}