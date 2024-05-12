#include "bfs.h"
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define QUEUESIZE 100

void BFS(LGraph* G, int s)
{
    printf("Vertices visited: ");
    for(int i = 0; i < G->V; i++)
    {
        G->adj[i]->color = WHITE;
    }

    G->adj[s]->color = GRAY;
    Queue* q = createQueue(QUEUESIZE);
    enqueue(q, s);
    
    while(!emptyQueue(q))
    {
        int u = dequeue(q); // 0
        Node* aux = G->adj[u];
        while(aux != NULL)
        {
            int v = aux->id; // 1
            if(G->adj[v]->color == WHITE)
            {
                G->adj[v]->color = GRAY;
                enqueue(q, v); // 1
            } 
            aux = aux->next;
        }
        G->adj[u]->color = BLACK;
        printf("%d ", u);
    }
    
}