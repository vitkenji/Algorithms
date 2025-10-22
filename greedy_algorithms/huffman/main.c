#include "huffman.h"
#define SIZE 4

int main()
{
    char* c = (char*) malloc(sizeof(char)*SIZE);
    float* f = (float*) malloc(sizeof(float)*SIZE);    
    c[0] = 'a'; c[1] = 'b'; c[2] = 'c'; c[3] = 'd';
    f[0] = 0.1; f[1] = 0.2; f[2] = 0.3; f[3] = 0.4;
    
    Tree* t = huffmanTree(c, f, SIZE);
    return 0;
}