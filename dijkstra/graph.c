#include "graph.h"

void printLGraph(LGraph* G, int size)
{
    printf("Graph: \n");
    for(int i = 0; i < size; i++)
    {
        printf("%d -> ", i);
        Node* current = G->adj[i]; // Usando uma variável auxiliar para percorrer a lista
        while(current != NULL)
        {
           if(current->id != INT_MAX ){ printf("%d ", current->id); }
            current = current->next;
        }
        printf("\n");
    }
}


void printMGraph(MGraph* G, int size)
{
   printf("Graph: \n");
   printf("     ");
    for(int i = 0; i < size; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
    printf("     ");
    for(int i = 0; i < size; i++)
    {
        printf("| ");
    }
    printf("\n");
    for(int i = 0; i < size; i++)
    {
        printf("%d--  ", i);
        for(int v = 0; v < size; v++)
        {
            printf("%d ", G->matrix[i][v]);
        }
        printf("\n");
    }
}

LGraph* createLGraph(int size)
{
    LGraph* G = (LGraph*) malloc(sizeof(LGraph));
    G->V = size;
    G->E = 0;
    G->adj = (Node**) malloc(sizeof(Node*)*size);
    for(int v = 0; v < G->V; v++)
    {
        G->adj[v] = NULL;
    }
    
    return G;
}


MGraph* createMGraph(int size)
{
    MGraph* G = (MGraph*) malloc(sizeof(MGraph));
    G->V = size;
    G->E = 0;
    G->matrix = (int**) malloc(sizeof(int*) * size);
    for(int i = 0; i < size; i++)
    {
        G->matrix[i] = (int*) malloc(sizeof(int) * size);
    }
     for(int i = 0; i < size; i++)
    {
         for(int j = 0; j < size; j++)
         {
            G->matrix[i][j] = 0;
         }
    }
    return G;
}

void insertWeightEdgeMatrix(MGraph* G, int v1, int v2, int weight)
{
    G->E++;
    G->matrix[v1][v2] = weight;
    G->matrix[v2][v1] = weight;

}

void insertEdgeMatrix(MGraph* G, int v1, int v2)
{
    G->E++;
    G->matrix[v1][v2] = 1;
    G->matrix[v2][v1] = 1;
}

void InsertEdgeListDirectional(LGraph* GrafoA, int index, int data){

   //printf("ligação %d , %d \n", data1, data2);
   Node* no1 = (Node *)malloc( sizeof(Node));
   no1->id = data;
   no1->next = NULL;
   //inserindo no 2
   if(GrafoA->adj[index] == NULL)
   {
      GrafoA->adj[index] = no1;
   }
   else
   {
      Node* noAux = GrafoA->adj[index];
      while(noAux->next != NULL)
      {
         noAux = noAux->next;
         //printf("id: %d \n", noAux->id);
      }
      noAux->next = no1;
   }
}

void InsertEdgeList( LGraph* GrafoA, int data1, int data2){
   GrafoA->E += 1;
   InsertEdgeListDirectional( GrafoA, data1, data2);
   InsertEdgeListDirectional( GrafoA, data2, data1);     
}

void correctAdj(LGraph* G)
{
    for(int v = 0; v < G->V; v++)
    {
        if(G->adj[v] == NULL)
        {
            Node* node = (Node*) malloc(sizeof(Node));
            node->id = INT_MAX;
            node->next = NULL;
            G->adj[v] = node;
            
        }
    }
}

void InsertWeightEdgeListDirectional(LGraph* GrafoA, int v1, int v2, int weight)
{
   Node* no1 = (Node *)malloc( sizeof(Node));
   no1->id = v2;
   no1->weight = weight;
   no1->next = NULL;
   //inserindo no 2
   if(GrafoA->adj[v1] == NULL)
   {
      GrafoA->adj[v1] = no1;
   }
   else
   {
      Node* noAux = GrafoA->adj[v1];
      while(noAux->next != NULL)
      {
         noAux = noAux->next;
         //printf("id: %d \n", noAux->id);
      }
      noAux->next = no1;
   }
}

void printLGraphWeight(LGraph* G, int size)
{
     printf("Graph: \n");
    for(int i = 0; i < size; i++)
    {
        printf("%d -> ", i);
        Node* current = G->adj[i]; // Usando uma variável auxiliar para percorrer a lista
        while(current != NULL)
        {
           if(current->id != INT_MAX ){ printf("%d(%d) ", current->id, current->weight); }
            current = current->next;
        }
        printf("\n");
    }
}