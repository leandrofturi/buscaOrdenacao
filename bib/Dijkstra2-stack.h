#pragma once


#include <stdlib.h>
#include "../TADsC/bib/pilha.h"


void empilha_dijkstra(char *c, tPilha *D, tPilha *S);

double *opera(double a, double b, char op);
double calculadora(tPilha *D, tPilha *S);