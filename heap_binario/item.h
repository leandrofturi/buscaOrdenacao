typedef int Item;
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define greater(A, B) (key(A) > key(B))
#define exch(A, B) { Item t = A; A = B; B = t; }
#define print(A) printf("%d", A)
