#include <stdio.h>
#define MAX 20
#define INF 1000

typedef struct {
    int predecessor;
    int distance;
    int status;
    int neighbours[MAX];
} Node;

typedef struct {
    int start;
    int end;
    int q[5*MAX];
} Queue;

Queue next_nodes = {0,0,{}};

Node nodes[MAX];

int exists(int node) {
    for (int i = next_nodes.start; i < next_nodes.end; i++) {
        if (next_nodes.q[i] == node) return 1;
    }
    return 0;
}

void insert(int node) {
    if (!exists(node)) next_nodes.q[next_nodes.end++] = node;
}

int delete() {
    int temp;
    int min = 0;
    for (int i = next_nodes.start; i < next_nodes.end; i++) {
        if (nodes[next_nodes.q[i]].distance < nodes[next_nodes.q[min]].distance) min = i;
    }
    temp = next_nodes.q[next_nodes.start];
    next_nodes.q[next_nodes.start] = next_nodes.q[min];
    next_nodes.q[min] = temp;
    return next_nodes.q[next_nodes.start++];
}

void print(int n) {
    for (int i = 0; i < n; i++) printf("Node %d:\n  Distance: %d\n  Predecessor: %d\n",i,nodes[i].distance,nodes[i].predecessor);
}

void show() {
    for (int i = next_nodes.start; i < next_nodes.end; i++) printf("%d ",next_nodes.q[i]);
    printf("\n");
}

void main() {
    int n,start,ref,weight;
    printf("Enter number of nodes:\n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix (-1 if no edge): \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d",&nodes[i].neighbours[j]);
        }
        nodes[i].distance = INF;
        nodes[i].status = 0;
        nodes[i].predecessor = -1;
    }
    printf("Enter the starting node:\n");
    scanf("%d",&start);
    insert(start);
    nodes[start].distance = 0;
    while (next_nodes.start != next_nodes.end) {
        ref = delete();
        nodes[ref].status = 1;
        for (int i = 0; i < n; i++) {
            weight = nodes[ref].neighbours[i];
            if (weight == -1) continue;
            if (nodes[i].distance > (nodes[ref].distance + weight)) {
                nodes[i].distance = (nodes[ref].distance + weight);
                nodes[i].predecessor = ref;
            }
            if (nodes[i].status == 0) insert(i);
        }
    }
    print(n);
}