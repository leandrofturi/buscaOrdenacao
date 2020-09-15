// Quick Union + Weighted + Path Compression
#include <stdbool.h>

// Inicializa estrutura com N objetos numerados de 0 a N-1.
void QU_W_PC_init(int N);

// Adiciona uma conexao entre p e q.
void QU_W_PC_union(int p, int q);

// Retorna o identificador do componente de p (entre 0 a N-1).
int QU_W_PC_find(int p);

// Os objetos p e q estao no mesmo componente?
bool QU_W_PC_connected(int p, int q);

// Componentes formadas
void QU_W_PC_components();