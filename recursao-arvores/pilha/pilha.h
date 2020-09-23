#define NMAX 10000

typedef struct tPilha tPilha;


// Inicialização
tPilha* inicializa_pilha(int sz);
void deleta_pilha(tPilha *P);

// Inserção e remoção de elementos
void empilha(tPilha* P, void* dado);
void* desempilha(tPilha* P);
void* espiar(tPilha* P);

// Propriedades
int vazia_pilha(tPilha *P);
void imprime_pilha(tPilha *P, void (*print)(void*));