#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "../bib/Dijkstra2-stack.h"


#define N 10


void empilha_dijkstra(char *c, tPilha *D, tPilha *S) {
    if(ispunct(*c)) {
        char *s = (char*) malloc(sizeof(char));
        *s = *c;
        empilha_P(s, S);
    }
    else {
        float *d = (float*) malloc(sizeof(float));
        *d = atof(c);
        empilha_P(d, D);
    }
}

float *opera(float *a, float *b, char *op) {
    float *r = (float*) malloc(sizeof(float));
    *r = 0;
    if(*op == '+')
        *r = *a + *b;
    else if(*op == '-')
        *r = *a - *b;
    else if(*op == '*')
        *r = *a * *b;
    else if (*op == '/')
        *r = *a / *b;
    free(a);
    free(b);
    free(op);
    return(r);
}

float *calculadora(tPilha *D, tPilha *S) {
    char c[N];
    float *r;
    tPilha *P = cria_P();
    do {
        scanf(" %s", c);
        if(*c == '(')
            empilha_P(NULL, P);
        else if(*c == ')') {
            desempilha_P(P);
            r = opera((float*)desempilha_P(D), (float*)desempilha_P(D), (char*)desempilha_P(S));
            empilha_P(r, D);
        }
        else
            empilha_dijkstra(c, D, S);
    } while(!estaVazia_P(P));
    deleta_P(P);
    return(r);
}