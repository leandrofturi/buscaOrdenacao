#include <stdio.h>
#include <stdlib.h>
#include "../bib/crivo.h"


int* inicializa_int(int N) {
    int *I = (int*) malloc((N+1)*sizeof(int));
    for(int i = 2; i <= N; i++)
        I[i] = 0;
    return(I);
}

void algoritmo_int(int *I, int N) {
    for(int i = 2; i <= N; i++)
        for(int j = 2*i; j <= N; j += i)
            I[j] = 1;
}

void imprime_int(int *I, int N) {
    printf("\n");
    for(int i = 2; i <= N; i++)
        if(!I[i])
            printf("%d ", i);
    printf("\n");
}


char* inicializa_char(int N) {
    char *C = (char*) malloc((N+1)*sizeof(char));
    for(int i = 2; i <= N; i++)
        C[i] = '0';
    return(C);
}

void algoritmo_char(char *C, int N) {
    for(int i = 2; i <= N; i++)
        for(int j = 2*i; j <= N; j += i)
            C[j] = '1';
}

void imprime_char(char *C, int N) {
    printf("\n");
    for(int i = 2; i <= N; i++)
        if(C[i] == '0')
            printf("%d ", i);
    printf("\n");
}

char* inicializa_bit(int N) {
    char *C = (char*) malloc((N/8+1)*sizeof(char));
    for(int i = 0; i <= N/8; i++)
        C[i] = 0b00000000;
    return(C);
}

void algoritmo_bit(char *C, int N) {
    for(int i = 2; i <= N; i++)
        for(int j = 2*i; j <= N; j += i)
            C[j/8] |= 1 << j%8;
}

void imprime_bit(char *C, int N) {
    printf("\n");
    for(int i = 2; i <= N; i++)
        if(!(C[i/8] & 1 << i%8))
            printf("%d ", i);
    printf("\n");
}
