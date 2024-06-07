#include "binaryTree.h"

Tree* createTree()
{
    return NULL;

}

Tree* insertNode(Tree* t, char c, float f)
{
    Tree* t = (Tree*) malloc(sizeof(Tree));
    t->c = c;
    t->f = f;
    t->left = NULL;
    t->right = NULL;
    return t;
}

Tree* buildTree(char c, float f, Tree* left, Tree* right)
{
    Tree* t = (Tree*) malloc(sizeof(Tree));
    t->c = c;
    t->f = f;
    t->left = left;
    t->right = right;

    return t;

}

void preOrder(Tree* t)
{
    if(t != NULL)
    {
        printf("%c ", t->c);
        preOrder(t->left);
        preOrder(t->right);
    }
}

void inOrder(Tree* t)
{
    if(t != NULL)
    {
        inOrder(t->left);
        printf("%c ", t->c);
        inOrder(t->right);
    }
}

void postOrder(Tree* t)
{
    if(t != NULL)
    {
        postOrder(t->left);
        postOrder(t->right);
        printf("%c ", t->c);
    }
}

int search(Tree* t, int data)
{
    if(t != NULL)
    {
        if(t->f == data)
        {
            return 1;
        }
        else
        {
            int l, r;
            l = search(t->left, data);
            r = search(t->right, data);
            if(l == 1 || r == 1)
            {
                return 1;
            }
        }

        
        
    }
    return 0;
}
