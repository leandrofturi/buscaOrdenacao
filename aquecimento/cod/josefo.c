#include <stdio.h>
#include <stdlib.h>
#include "../bib/josefo.h"


int *inicializa_int(int N) {
    int *I = (int*) malloc((N+1)*sizeof(int));
    for(int i = 0; i < N; i++)
        I[i] = 0;
    return(I);
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


char *inicializa_bit(int N) {
    char *B = (char*) malloc((N/8+1)*sizeof(char));
    for(int i = 0; i <= N/8; i++)
        B[i] = 0b00000000;
    for(int i = N%8; i < 8; i++)
        B[N/8] |= 1 << i;
    return(B);
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
