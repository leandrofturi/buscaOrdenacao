#include <stdlib.h>
#include "../bib/CrivodeEratostenes.h"

// int
void inicializar_I(int *I, int N) {
    for(int j=2; j<N; j++)
        I[j] = 0;
}

void marcarMultiplos_I(int *I, int N) {
    for(int j=2; j<N; j++)
        for(int i=2*j; i<N; i+=j)
            I[i] = 1;
}

void imprimePrimos_I(int *I, int N) {
    for(int j=2; j<N; j++)
        if(!I[j])
            printf("%d ", j);
    printf("\n");
}

// char
void inicializar_C(char *C, int N) {
    for(int j=2; j<N; j++)
        C[j] = '0';
}

void marcarMultiplos_C(char *C, int N) {
    for(int j=2; j<N; j++)
        for(int i=2*j; i<N; i+=j)
            C[i] = '1';
}

void imprimePrimos_C(char *C, int N) {
    for(int j=2; j<N; j++)
        if(C[j] == '0')
            printf("%d ", j);
    printf("\n");
}

// bit a bit
void inicializar_B(char *B, int N) {
    for(int k=0; k<N/8+1; k++)
        B[k] = NULL;
}

void marcarMultiplos_B(char *B, int N) {
    for(int j=2; j<N; j++)
        for(int i=2*j; i<N; i+=j)
            B[i/8] |= 1 << i%8;
}

void imprimePrimos_B(char *B, int N) {
    for(int j=2; j<N; j++)
        if(!(B[j/8] & 1 << j%8))
            printf("%d ", j);
    printf("\n");
}