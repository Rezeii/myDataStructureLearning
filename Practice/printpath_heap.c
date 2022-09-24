#include <stdio.h>
#define MAXN 1001
#define MINH -10001

int H[MAXN], size; //根结点从1开始存放数据

void Create()
{
    size = 0;
    H[0] = MINH; //最小堆 哨兵为H[0]
}

void Insert(int X)
{
    int i = ++size;
    for (; H[i / 2] > X; i /= 2)
    {
        H[i] = H[i / 2];
    }
    H[i] = X;
}

int main()
{
    int n, m, x, i, j = 1;

    scanf("%d %d", &n, &m);
    Create();
    for (i = 0; i < n; i++)
    {
        scanf("%d", x);
        Insert(x);
    }

    for (i = 0; i < m; i++)
    {
        scanf("%d", &j);
        printf("%d", H[j]);
        while (j > 1)
        {
            j /= 2;
            printf(" %d", H[j]);
        }
        printf("\n");
    }

    return 0;
}