#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 100
#define inf 10000
typedef int WeightType;
typedef int Vertex;
typedef int DataType;

typedef struct MGraph
{
    int ne;
    int nv;
    WeightType G[MaxVertexNum][MaxVertexNum];
} * Graph;

Graph BuildGraph()
{
    int V, E;

    scanf("%d %d", &V, &E);

    Graph mg = (Graph)malloc(sizeof(struct MGraph));

    mg->ne = E;
    mg->nv = V;

    for (int i = 0; i < mg->nv; i++)
    {
        for (int j = 0; j < mg->nv; j++)
        {
            mg->G[i][j] = inf;
        }
    }

    int i, j, w;
    for (int k = 0; k < E; k++)
    {
        scanf("%d %d %d", &i, &j, &w);
        mg->G[i][j] = w;
        mg->G[j][i] = w;
    }
    return mg;
}

void Floyd(Graph g)
{
    for (int k = 0; k < g->nv; k++)
    {
        for (int i = 0; i < g->nv; i++)
        {
            for (int j = 0; j < g->nv; j++)
            {
                if (g->G[i][k] + g->G[k][j] < g->G[i][j])
                    g->G[i][j] = g->G[i][k] + g->G[k][j];
            }
        }
    }
}

int FindMax(Graph g, int i, int n)
{
    int maxdist = 0;
    for (int k = 0; k < n; k++)
    {
        if (maxdist < g->G[i][k] && i != k)
            maxdist = g->G[i][k];
    }
    return maxdist;
}

void Find(Graph g)
{
    int mindist = inf;

    for (int i = 0; i < g->nv; i++)
    {
        if (mindist > FindMax(g, i, g->nv))
            mindist = FindMax(g, i, g->nv);
    }
    printf("%d\n", &g->ne);
    printf("%d\n", &g->nv);

    printf("the mindist is %d", &mindist);
}

int main()
{

    Graph g = BuildGraph();

    Floyd(g);

    Find(g);

    return 0;
}
