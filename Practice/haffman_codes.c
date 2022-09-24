//题意理解：检测给定的编码是否为最优编码
//核心算法：
// 1.计算最优编码长度
// 2.编码字符全部在叶结点上(前缀码)
// 3.不存在度为1的结点
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    int weight;
    struct Node *left;
    struct Node *right;
} * Tree;

int WPL(Tree T, int depth)
{

    if (!T->left && !T->right)
        return (T->data) * depth;
    else
    {
        depth++;
        return WPL(T->left, depth) + WPL(T->right, depth);
    }
}