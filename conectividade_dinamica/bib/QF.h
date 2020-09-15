// Quick Find
#include <stdbool.h>

// Inicializa estrutura com N objetos numerados de 0 a N-1.
void QF_init(int N);

// Adiciona uma conexao entre p e q.
void QF_union(int p, int q);

// Retorna o identificador do componente de p (entre 0 a N-1).
int QF_find(int p);

// Os objetos p e q estao no mesmo componente?
bool QF_connected(int p, int q);

// Componentes formadas
void QF_components();