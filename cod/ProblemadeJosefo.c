#include <stdlib.h>
#include "../bib/ProblemadeJosefo.h"


// int
void inicializar_I(int *I, int N) {
    for(int i=0; i<N; i++)
        I[i] = 0;
}

int eleicao_I(int *I, int N, int M) {
    int i=0, j=1, k=0;
    while(k < N) {
        if(!(I[i])) {
            if(j==M) {
                I[i] = 1;
                j=0;
                k++;
            }
            j++;
        }
        i=(i+1)%N;
    }
    return(i==0?N:i);
}


// bit a bit
void inicializar_B(char *B, int N) {
    for(int k=0; k<N/8+1; k++)
        B[k] = NULL;
    for(int k=N%8; k<8; k++)
        B[N/8] |= 1 << k;
}

int eleicao_B(char *B, int N, int M) {
    int i=0, j=1, k=0;
    while(k < N) {
        if(!(B[i/8] & 1 << i%8)) {
            if(j==M) {
                B[i/8] |= 1 << i%8;
                j=0;
                k++;
            }
            j++;
        }
        i=(i+1)%N;
    }
    return(i==0?N:i);
}