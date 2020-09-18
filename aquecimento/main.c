#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bib/crivo.h"
#include "bib/josefo.h"


int main(int argc, char *argv[]) {
    // int N = atoi(argv[1]);
    // int M = atoi(argv[2]);

    clock_t tic = clock();

    

    clock_t toc = clock();
    printf("Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);

    return(0);
}