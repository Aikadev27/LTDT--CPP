#include <iostream>
#include "size.h"
#include "define_list.h"
#include "define_graph.h"
#include "define_queue.h"
using namespace std;
// #define MAX_VERTICLE 100
// int rank[MAX_VERTICE];
// int d[MAX_VERTICE];

List topo_sort(Graph *pG)
{
    int d[MAX_N];
    for (int u = 1; u <= pG->n; u++)
    {
        d[u] = 0;
        for (int x = 1; x <= pG->n; x++)
        {
            if (pG->A[u][x] != 0)
            {
                d[u]++;
            }
        }
    }
    Queue Q;
    makenull_Queue(&Q);
    for (int u= 1; u <= pG->n; u++)
    {
        if (d[u] == 0)
        {
            push(&Q,u);
        }
    }
    List pL;
    make_null_list(&pL);
    while (!empty(&Q))
    {
        int u = top(&Q);
        pop(&Q);
        push_back(&pL, u);
        for (int v = 1; v <= pG->n; v++)
        {
            if (pG->A[u][v] != 0)
            {
                d[v]--;
                if (d[v] == 0)
                {
                    push(&Q,v);
                }
            }
        }
    }
    return pL;
}

int main()
{
    Graph G;
    int m , n ,u ,v,e;
    cin>>n>>m;
    init_graph(&G,n);
    for(e=0; e<m; e++){
        cin>>u>>v;
        add_edge(&G,u,v);
    }
    List l = topo_sort(&G);
    for( u =1; u<=l.size; u++){
        cout<<element_at(&l,u)<<endl;
    }
    return 0;
}