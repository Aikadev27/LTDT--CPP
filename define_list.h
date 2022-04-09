#include "size.h"
typedef int ElementType;

struct List
{
    ElementType data[MAX_ELEMENT];
    int size;
};
void make_null_list(List *L)
{
    L->size = 0;
}

void push_back(List *L, int x)
{
    L->data[L->size] = x;
    L->size++;
}

int size(List *L)
{
    return L->size;
}

ElementType element_at(List *L ,int i)
{
    return L->data[i - 1];
}
