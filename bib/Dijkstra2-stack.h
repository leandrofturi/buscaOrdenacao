#pragma once


#include <stdlib.h>
#include "../TADsC/bib/pilha.h"


void empilha_dijkstra(char *c, tPilha *D, tPilha *S);

float *opera(float *a, float *b, char *op);
float *calculadora(tPilha *D, tPilha *S);