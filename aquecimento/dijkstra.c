#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "pilha/pilha.h"


double opera(double a, double b, char c) {
    double r = 0.0;
    if(c == '+') r = a+b;
    else if(c == '-') r = a-b;
    else if(c == '*') r = a*b;
    else if(c == '/') r = a/b;
    return(r);
}

int main( ) {
    tPilha *I = inicializa_pilha(sizeof(char*));
    tPilha *C = inicializa_pilha(sizeof(char*));

    double r = 0.0;
    char r_tmp[NMAX][NMAX]; // #1 dimensão para resultado corrente, 
    int tmp = 1;            // #2 dimensão para o double convertido em char*
    char op[2*NMAX]; // string de entrada
    fgets(op, 2*NMAX, stdin);

    char* token = strtok(op, " ");
    while(token != NULL) {
        if(isdigit(*token)) {
            empilha(I, token); // Empilho o token corrente na pilha
        }
        else if(*token == '+' || *token == '-' || *token == '*' || *token == '/')
            empilha(C, token);
        else if(*token == ')') {
            r = opera(strtod((char*) desempilha(I), NULL), 
                     strtod((char*) desempilha(I), NULL), 
                     *(char*) desempilha(C));
            sprintf(r_tmp[tmp], "%f", r); // Converto o resultado corrente (double) em char e 
            empilha(I, r_tmp[tmp]);      // adiciono em uma nova posição da minha matriz
            tmp++;
        }
        token = strtok(NULL, " ");
    }
    printf("%.2f  ", strtod((char*) desempilha(I), NULL));

    deleta_pilha(C);
    deleta_pilha(I);
    return(0);
}