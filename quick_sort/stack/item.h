#pragma once

typedef int Item;
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define leq(A, B) (key(A) <= key(B))
#define exch(A, B) { Item t = A; A = B; B = t; }
#define compexch(A, B) if (less(B, A)) exch(A, B)
#define char_2Item(A) atoi(A)
#define printItem(A) printf("%d", A)
