#include<stdlib.h>

typedef struct nnode
{
    struct nnode *left;
    int data;
    struct nnode *right;
} NODE;

NODE* createNode()
{
    NODE *n = (NODE *) malloc(sizeof(NODE));
    n->left = NULL;
    n->right = NULL;
    return n;
}

NODE *Display(NODE *tree)
{
    if (tree != NULL)
    {
        printf("%d",tree->data);
        if (tree->left != NULL)
        {
            Display(tree->left);
        }
        if (tree->right != NULL)
        {
            Display(tree->right);
        }
    }
}

NODE *insert(NODE *tree, int val)
{
    NODE *n = createNode();
    if (tree == NULL)
    {
        n->data = val;
    }
    else    
    {
        if(val >= tree->data)
        {
            while(val > tree->data)
            {
                tree = tree->right;
                if (tree->right == NULL)
                {
                    tree->right = n;
                }
            }
            while(val < tree->data)
            {
                tree = tree->left;
                if (tree->left == NULL)
                {
                    tree->left = n;
                }
            }
        }
        if(val < tree->data)
        {
            while(val < tree->data && tree->left != NULL)
            {
                tree = tree->left;
                if (tree->left == NULL)
                {
                    tree->left = n;
                }
            }
            while(val > tree->data && tree->right != NULL)
            {
                tree = tree->right;
                if (tree->right == NULL)
                {
                    tree->right = n;
                }
            }
        }
        n->data = val;
        return tree;                
    }
}