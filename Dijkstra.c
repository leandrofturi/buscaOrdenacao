#include <stdio.h>
#include <stdlib.h>
#include "bib/Dijkstra2-stack.h"


int main(int argc, char *argv[]) {
    tPilha *D = cria_P();
    tPilha *S = cria_P();
    calculadora(D, S);
    
    return(0);
}