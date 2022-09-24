//题意理解：给定先序和中序遍历的结果，输出后序遍历的结果

#include <stdio.h>
#include <stdlib.h>
int pre[100], in[100], post[100];

//方法一：建树后后序遍历（难点主要是建树）
typedef struct TreeNode
{
    int data;
    struct TNode *left;
    struct TNode *right;
} * Tree;

Tree BuildTree(int *in, int *pre, int inL, int inR, int preL, int preR)
{
    Tree root;
    int leftlen, rightlen, r; // r是根结点在in[]中的下标

    root = (Tree)malloc(sizeof(struct TreeNode));
    root->data = pre[preL];

    for (r = inL; in[r] != pre[preL]; r++) //通过循环找到根结点在in中的位置
        ;

    leftlen = r - inL;  //根的左子树结点个数
    rightlen = inR - r; //根的右子树结点个数

    if (leftlen)
    {
        root->left = BuildTree(in, pre, inL, inL + leftlen - 1, preL + 1, preL + leftlen); //向左建立树
    }
    else
        root->left = NULL;

    if (rightlen)
    {
        root->right = BuildTree(in, pre, inR - rightlen + 1, inR, preR - rightlen + 1, preR); //向右建立树
    }
    else
        root->right = NULL;

    return root;
}

//方法二：不建树，直接根据前序和中序输出后序遍历结果
void solve(int preL, int inL, int postL, int num)
{
    //通过先序和中序数组直接写出后序数组
    if (num == 0)
        return;
    if (num == 1)
    {
        post[postL] = pre[preL];
        return;
    }
    int root = pre[preL]; //根结点是先序第一个
    post[postL + num - 1] = root;
    //在中序中找根结点下标
    int k;
    for (int i = 0; i < num; i++)
    {
        if (in[inL + i] == root)
        {
            k = i;
            break;
        }
    }
    int L = k, R = num - L - 1; //左右子树的个数
    //递归处理
    solve(preL + 1, inL, postL, L);
    solve(preL + L + 1, inL + L + 1, postL + L, R);
}
