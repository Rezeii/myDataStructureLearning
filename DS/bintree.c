//结点的度：结点的子树个数
//树的度：树的所有节点中最大的度数

//二叉树的分类：斜二叉树、完美二叉树、完全二叉树
#define ElementType int
typedef TreeNode *bintree;
typedef bintree Position;
struct TreeNode
{
    ElementType data;
    bintree left;
    bintree right;
};

void PreOrderTraversal(bintree BT) //先序遍历
{
    if (BT)
    {
        printf("%d", BT->data);
        PreOrderTraversal(BT->left);
        PreOrderTraversal(BT->right);
    }
}

void InOrderTraversal(bintree BT) //钟序遍历
{
    if (BT)
    {
        PreOrderTraversal(BT->left);
        printf("%d", BT->data);
        PreOrderTraversal(BT->right);
    }
}

void PostOrderTraversal(bintree BT) //钟序遍历
{
    if (BT)
    {
        PreOrderTraversal(BT->left);
        printf("%d", BT->data);
        PreOrderTraversal(BT->right);
    }
}

void Traversal(bintree BT) //非递归实现二叉树的中序遍历
{
    bintree T = BT;
    stack S = createStack(maxsize);

    while (T || !IsEmpty(S))
    {
        while (T)
        {
            Push(S, T); //第一次碰到这个结点
            T = T->left
        }
        if (!IsEmpty(S))
        {
            T = Pop(S); //第二次碰到这个结点
            printf("%d", T->data);
            T = T->right; //第三次碰到这个结点
        }
    }
}

int PostOrderGetHeight(bintree BT)
{
    int HL, HR, MaxH;
    if (BT)
    {
        HL = PostOrderGetHeight(BT->left);
        HR = PostOrderGetHeight(BT->right);
        MaxH = (HL > HR) ? HL : HR;
        return MaxH + 1;
    }
    else
        return 0;
}
