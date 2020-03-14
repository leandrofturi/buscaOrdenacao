#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "../bib/Dijkstra2-stack.h"


void empilha_dijkstra(char *c, tPilha *D, tPilha *S) {
    if(ispunct(*c))
        empilha_P(c, S);
    double d = atof(c);
    empilha_P(&d, D);
}

double *opera(double a, double b, char op) {
    double *r = (double*) malloc(sizeof(double));
    *r = 0;
    if(op == '+')
        *r = a+b;
    else if(op == '-')
        *r = a-b;
    else if(op == '*')
        *r = a*b;
    else if (op == '/')
        *r = a/b;
    return(r);
}

double calculadora(tPilha *D, tPilha *S) {
    char *c;
    double *r;
    tPilha *P = cria_P();
    do {
        scanf(" %s", c);
        if(*c == '(')
            empilha_P(NULL, P);
        else if(*c == ')') {
            r = opera(*(double*)desempilha_P(D), *(double*)desempilha_P(D), *(char*)desempilha_P(S));
            empilha_P(r, D);
        }
        else
            empilha_dijkstra(c, D, S);
    } while(!estaVazia_P(P));
    return(*r);
}