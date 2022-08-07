#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100
#define ElementType int
typedef int set;

int Find(set *S, ElementType X)
{
    if (X > MaxSize)
        return -1;
    for (; S[X] >= 0; X = S[X])
        ;

    return X;
}

/* 采用路径压缩优化的Find函数 int Find(set *S, ElementType X)
{
    if (S[X] < 0)
    {
        return X;
    }
    else
        return S[X] = Find(S, S[X]);
}
*/

void Union(set *S, int root1, int root2)
{
    S[root1] = root2;
}

/*  采用按秩归并(按高度)后改进的Union函数，将高度小的树接到高度大的树上
    当两棵树高不同的时候，合并后高度为其中较高的树的树高；
    当两棵树同高度时，总树高加1
void Union(set *S, int root1, int root2)
{
    if (S[root1] < S[root2])
        S[root2] = root1;
    else if (S[root1] > S[root2])
        S[root1] = root2;
    else
    {
        S[root1] = root2;
        S[root2] -= 1;
    }
}
*/

/*  采用按秩归并(按规模)后改进的Union函数，将规模小的树接到规模大的树上
    合并后规模求和
void Union(set *S, int root1, int root2)
{
    if(S[root2]<S[root1])
    {
        S[root2]+=S[root1];
        S[root1]=root2;
    }
    else
    {
        S[root1]+=S[root2];
        S[root2]=root1;
    }
}
*/

void Init(set **S, int n) //这里malloc是给指针赋值，传指针的地址，形参为二级指针
{

    *S = (int *)malloc(sizeof(int) * (n + 1));
    for (int i = 1; i < n + 1; i++)
    {
        (*S)[i] = -1;
    }
}

void Input_connection(set *S)
{
    int obj1, obj2;
    scanf("%d %d", &obj1, &obj2);
    int root1, root2;

    root1 = Find(S, obj1);
    root2 = Find(S, obj2);

    Union(S, root1, root2);
}

void Check_connection(set *S)
{
    int obj1, obj2;
    scanf("%d %d", &obj1, &obj2);

    if (Find(S, obj1) == Find(S, obj2))
        printf("yes\n");
    else
        printf("no\n");
}

void Check_network(set *S, int n)
{
    int counter = 0;
    for (int i = 1; i <= n; i++)
    {
        if (S[i] < 0)
        {
            counter++;
        }
    }
    if (counter != 1)
    {
        printf("the computers are not all connected");
        return;
    }
    else
        printf("the computers are all connected");
}

int main()
{
    int n, i;
    char cmd;
    set *S;

    scanf("%d", &n);
    Init(&S, n);
    do
    {
        scanf("%c", &cmd);
        switch (cmd)
        {
        case 'I':
            Input_connection(S);
            break;
        case 'C':
            Check_connection(S);
            break;
        case 'S':
            Check_network(S, n);
            break;
        }

    } while (cmd != 'S');

    return 0;
}
