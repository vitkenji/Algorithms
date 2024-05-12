#include "queue.h"

Queue* createQueue(int size)
{
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->array = (int*) malloc(sizeof(int)*size);
    q->size = size;
    q->front = 0;
    q->back = 0;

    return q;

}

int fullQueue(Queue* q)
{
    return (q->front == ((q->back + 1) % q->size));

}

int emptyQueue(Queue* q)
{
    return (q->front == q->back);   

}

int front(Queue* q)
{
    return(q->array[q->front]);
}

void enqueue(Queue* q, int data)
{
    if(fullQueue(q))
    {
        printf("error: full queue");
        exit(1);

    }
    
    q->array[q->back] = data;
    q->back = (q->back + 1) % q->size;
    
}

int dequeue(Queue* q)
{
    if(emptyQueue(q))
    {
        printf("error: empty queue");
        exit(1);

    }

    int data = q->array[q->front];
    q->front = (q->front + 1) % q->size; 
    
    return data; 
    
}

void printQueue(Queue* q)
{
    printf("Queue: ");
    for(int i = q->front; i != q->back; (i++) % q->size) { printf("%d ", q->array[i]); }  
    printf("\n");

}   

