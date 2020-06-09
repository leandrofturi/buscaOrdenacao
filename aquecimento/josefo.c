#include <stdio.h>
#include <stdlib.h>
#include "josefo.h"


void inicializa_int(int *I, int N) {
    for(int i = 0; i < N; i++)
        I[i] = 0;
}

int eleicao_int(int *I, int N, int M) {
    int i = 0, j = 1, k = 0;
    while(k < N) {
        if(!(I[i])) {
            if(j == M) {
                I[i] = 1;
                j = 0;
                k++;
            }
            j++;
        }
        i = (i+1) % N;
    }
    return(i == 0 ? N : i);
}


void inicializa_bit(char *B, int N) {
    for(int i = 0; i <= N/8; i++)
        B[i] = 0b00000000;

    for(int i = N%8; i < 8; i++)
        B[N/8] |= 1 << i;
}

int eleicao_bit(char *B, int N, int M) {
    int i = 0, j = 1, k = 0;
    while(k < N) {
        if(!(B[i/8] & 1 << i%8)) {
            if(j == M) {
                B[i/8] |= 1 << i%8;
                j = 0;
                k++;
            }
            j++;
        }
        i = (i+1) % N;
    }
    return(i == 0 ? N : i);
}


int main(int argc, char *argv[]) {

    int N = atoi(argv[1]);
    int M = atoi(argv[2]);

    int I[N];
    inicializa_int(I, N);
    printf("%d\n", eleicao_int(I, N, M));

    char B[(N/8)+1];
    inicializa_bit(B, N);
    printf("%d\n", eleicao_bit(B, N, M));
    
    return(0);
}