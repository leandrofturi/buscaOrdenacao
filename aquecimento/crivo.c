#include <stdio.h>
#include <stdlib.h>
#include "crivo.h"

void inicializa_int(int* I, int N) {
    for(int i = 2; i <= N; i++)
        I[i] = 0;
}

void algoritmo_int(int* I, int N) {
    for(int i = 2; i <= N; i++)
        for(int j = 2*i; j <= N; j += i)
            I[j] = 1;
}

void imprime_int(int* I, int N) {
    printf("\nCrivo de Eratostenes\n");
    for(int i = 2; i <= N; i++)
        if(!I[i])
            printf("%d ", i);
    printf("\n");
}


void inicializa_char(char* C, int N) {
    for(int i = 2; i <= N; i++)
        C[i] = '0';
}

void algoritmo_char(char* C, int N) {
    for(int i = 2; i <= N; i++)
        for(int j = 2*i; j <= N; j += i)
            C[j] = '1';
}

void imprime_char(char* C, int N) {
    printf("\nCrivo de Eratostenes\n");
    for(int i = 2; i <= N; i++)
        if(C[i] == '0')
            printf("%d ", i);
    printf("\n");
}

void inicializa_bit(char* B, int N) {
    for(int i = 0; i <= N/8; i++)
        B[i] = 0b00000000;
}

void algoritmo_bit(char* B, int N) {
    for(int i = 2; i <= N; i++)
        for(int j = 2*i; j <= N; j += i)
            B[j/8] |= 1 << j%8;
}

void imprime_bit(char* B, int N) {
    printf("\nCrivo de Eratostenes\n");
    for(int i = 2; i <= N; i++)
        if(!(B[i/8] & 1 << i%8))
            printf("%d ", i);
    printf("\n");
}


// gcc Crivo.c -o out
int main() {

    int N;
    scanf(" %d", &N);
    if(N < 2) return(0);

    int I[N];
    inicializa_int(I, N);
    algoritmo_int(I, N);
    imprime_int(I, N);

    char C[N];
    inicializa_char(C, N);
    algoritmo_char(C, N);
    imprime_char(C, N);

    char B[N/8];
    inicializa_bit(B, N);
    algoritmo_bit(B, N);
    imprime_bit(B, N);
    
    return(0);
}