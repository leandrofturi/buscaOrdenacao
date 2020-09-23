#define NMAX 10000

typedef struct tFila tFila;


// Inicialização e finalização
tFila *cria_fila(int sz);
void deleta_fila(tFila *F);

// Inserção e remoção de elementos
void enfilera(tFila *F, void* dado);
void *desenfilera(tFila *F);

// Propriedades
int vazia_fila(tFila* F);
