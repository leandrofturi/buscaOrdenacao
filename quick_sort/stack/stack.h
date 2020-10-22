#include "item.h"

typedef struct tStack tStack;


tStack* init_stack(int sz);
void del_stack(tStack *S);

void push(tStack *S, Item item);
Item pop(tStack *S);
Item peek(tStack *S);

int empty_stack(tStack *S);
void print_stack(tStack *S);