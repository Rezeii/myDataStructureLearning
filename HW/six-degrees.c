void SDS()
{
    for (each V in G)
    {
        count = BFS(V);
        optput(count / N);
    }
}