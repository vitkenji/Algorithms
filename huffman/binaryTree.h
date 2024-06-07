#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char c;
    float f;
    struct node* left;
    struct node* right;

}Tree;

Tree* createTree();
Tree* insertNode(Tree* t, char c, float f);
Tree* buildTree(char c, float f, Tree* left, Tree* right);

void preOrder(Tree* t);
void inOrder(Tree* t);
void postOrder(Tree* t);

int search(Tree*, int data);
