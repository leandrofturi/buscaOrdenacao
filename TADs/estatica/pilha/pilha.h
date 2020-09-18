#define NMAX 1000

struct tStack {
    int count;
    void* elements[NMAX];
};
typedef struct tStack tStack;

// Inicialização
tStack inicializa_pilha();

// Inserção e remoção de elementos
void empilha(tStack* S, void* dado);
void* desempilha(tStack* S);

// Propriedades
int vazia_pilha(tStack S);
void imprime_pilha(tStack S, void (*print)(void*));