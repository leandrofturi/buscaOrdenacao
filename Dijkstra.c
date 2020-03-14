#include <stdio.h>
#include <stdlib.h>
#include "bib/Dijkstra2-stack.h"


int main(int argc, char *argv[]) {

    tPilha *D = cria_P();
    tPilha *S = cria_P();
    float *r = calculadora(D, S);
    printf("%f\n", *r);
    free(r);

    deleta_P(D);
    deleta_P(S);

    return(0);
}