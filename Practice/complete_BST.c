//完全二叉搜索树
//题意理解：将给定的从小到大的数字建立成一棵完全二叉搜索树，输出其层序遍历的结果。
//由于主要操作是遍历，而完全二叉树决定了空间不会被浪费，所以使用数组。

//核心算法：根据给定的数据规模配合完全二叉树的性质导出根结点的位置，然后对左右子树递归进行排序建立（实际是先序遍历），之后层序遍历输出
#include <stdio.h>
#include <stdlib.h>
int A[100];
int resultT[100];

//要做的事情就是对排好序的数据A，从中挑出数字排到resultT[root]中
void solve(int Aleft, int Aright, int root) //初始调用为solve（0，N-1，0）
{
    int nleft, nright;
    int n = Aright - Aleft + 1;

    if (n == 0)
        return;

    int L = getLeftLen(n); //计算有n个结点的完全二叉树的左子树结点个数

    resultT[root] = A[Aleft + L];

    int leftroot = root * 2 + 1; //下标从0开始
    int rightroot = leftroot + 1;

    solve(Aleft, Aleft + L - 1, leftroot);
    solve(Aleft + L + 1, Aright, rightroot);
}

int getLeftLen(int n) //完全二叉树：2^H-1+X=N
{
    int h = (int)(log2(n + 1));
    int x = n + 1 - (int)(pow(2, h));
    x = min(x, (int)(pow(2, h - 1)));
    return (int)(pow(2, h - 1)) - 1 + x;
}

int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int N;
    int i = 0, n;
    while ((n = getchar()) != '\n')
        A[i++] = n;

    qsort(A, N, sizeof(int), compare);
}