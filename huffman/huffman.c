#include "huffman.h"

Tree* huffmanTree(char* c, float* f, int n)
{
    
    Tree* t = createTree();
    Heap* h = createHeap(n);
    for(int i = 0; i < n; i++)
    {
        h->c[i] = c[i];
        h->f[i] = f[i];
    }
    printHeap(h);
    for(int i = 0; i < n - 1; i++)
    {
        Tree* node = (Tree*) malloc(sizeof(Tree));
        
    }
    return t;
}