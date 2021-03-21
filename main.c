#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#define class struct

enum search
{
    TRUE = 1,
    FALSE = 0,

} search;

class Node
{
    int data;
    int search;
    class Node **edges;
    class Node *parent;
};

class Graph
{
    class Node **nodes;
    class Node *start;
    class Node *end;
};
typedef class Node node;
typedef class Graph graph;

/*------------ Funções Uteis ---------------*/
//Pega último index
int getIndexEdges(class Node **arr)
{
    int i = 0;
    while (arr[i] != NULL)
    {
        i++;
    }

    return i;
}

/*---------- Métodos do Node ------------*/

class Node *createNode(int value)
{

    class Node *newNode = malloc(sizeof(class Node));
    newNode->data = value;
    newNode->search = 0;
    newNode->edges = malloc(sizeof(class node *));

    return newNode;
}

//Adding Edge in the last position in both arrays of type edge
void addEdge(class Node *node1, class Node *node2)
{
    node1->edges[getIndexEdges(node1->edges)] = node2;
    node2->edges[getIndexEdges(node2->edges)] = node1;
}

/*---------- Métodos do Grafo ------------*/
graph *createGraph()
{
    graph *Graph = malloc(sizeof(graph));
    Graph->nodes = malloc(sizeof(class node *));
    Graph->start = NULL;
    Graph->end = NULL;

    return Graph;
}

void addNode(class Graph *graph, class Node *node)
{
    int index = getIndexEdges(graph->nodes);
    graph->nodes[index] = node;
}

node *getNode(class Graph *graph, int index)
{
    return graph->nodes[index];
}

node *setStart(class Graph *graph, int index)
{
    class Node *start = graph->nodes[index];
    graph->start = start;
    return start;
}

node *setEnd(class Graph *graph, int index)
{
    class Node *end = graph->nodes[index];
    graph->end = end;
    return end;
}

void getPathBFS(class Graph *graph)
{
    class Node *path = malloc(sizeof(class Node));
    class Node *next = malloc(sizeof(class Node));

    path[0] = *graph->end;
    next = graph->end->parent;

    int i = 1;
    while (next != NULL)
    {
        path[i] = *next;
        next = next->parent;
        i++;
    }

    int j = 0;
    while (&path[j] != NULL)
    {
        printf("%d", path[j].data);
    }
}

void BFS(class Graph *graph, int start, int end)
{
    class Node *queue = malloc(sizeof(class Node));
}

void DFS()
{
}

void printGraph(class Graph *graph)
{

    int i = 0;
    while (graph->nodes[i] != NULL)
    {
        printf("Index: %i - Value:%d \n ", i, graph->nodes[i]->data);
        ++i;
    }
}

int main(void)
{
    graph *Graph = createGraph();

    node *node1 = createNode(1);
    node *node2 = createNode(2);
    node *node3 = createNode(3);

    addEdge(node1, node2);
    addEdge(node3, node1);

    addNode(Graph, node1);
    addNode(Graph, node2);
    addNode(Graph, node3);

    printGraph(Graph);
}
