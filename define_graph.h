#include "size.h"
#include"define_list.h"

struct Graph
{
    int n;
    int A[MAX_N][MAX_N];
};
void init_graph(Graph *G, int n)
{
    int i, j;
    G->n = n;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            G->A[i][j] = 0;
}
void add_edge(Graph *G, int x, int y)
{
    G->A[x][y] = 1;
}
int adjacent(Graph *G, int x, int y)
{
    return G->A[x][y] != 0;
}
int degree(Graph *G, int x)
{
    int y, deg = 0;
    for (y = 1; y <= G->n; y++)
        deg += G->A[x][y];
    return deg;
}
List neighbors(Graph *G, int x)
{
    int y;
    List list;
    make_null_list(&list);
    for (y = 1; y <= G->n; y++)
        if (adjacent(G, x, y))
            push_back(&list, y);
    return list;
}
void copy_list(List *S1, List *S2)
{
    int i, x;
    make_null_list(S1);
    for (i = 1; i <= S2->size; i++)
    {
        x = element_at(&S2, i);
        push_back(S1, x);
    }
}
