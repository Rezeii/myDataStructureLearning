
typedef struct Vertex
{

} void ListComponents(Graph G)
{
    for ()
}
int DFS(Vertex V)
{
    int ans = 0;

    visited[V] = true;
    if (issafe(V))
        ans = 1;
    else
    {
        for ()
            if (!visited[W] && Jump(V, W))
            {
                ans = DFS(W);
                if (ans)
                    break;
            }
    }

    return ans;
}