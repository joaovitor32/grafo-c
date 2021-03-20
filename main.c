#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#define class struct
#define GRAPH_SIZE 20

class Node
{
    int data;
    int search;
    class Node **edges;
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
    newNode->edges = malloc(sizeof(class node *));
    newNode->search = 0;

    return newNode;
}

//Adding Edge in the last position in both arrays of type edge
void addEdge(class Node *node1, class Node *node2)
{
    node1->edges[getIndexEdges(node1->edges)] = node2;
    node2->edges[getIndexEdges(node2->edges)] = node1;
}

/*---------- Métodos do Grafo ------------*/
graph *createGraph(int numVertices)
{
    graph *Graph = malloc(sizeof(graph));
    Graph->nodes = malloc(numVertices * sizeof(class node *));
    Graph->start = NULL;
    Graph->end = NULL;

    return Graph;
}

void printGraph(class Graph *graph, int numVertices)
{
    for (int i = 0; i < numVertices; i++)
    {
        printf("Index: %i - Value:%d \n ", i, graph->nodes[i]->data);
    }
}

int main(void)
{
    graph *Graph = createGraph(GRAPH_SIZE);
    //printGraph(Graph, GRAPH_SIZE);

    node *node1 = createNode(1);
    node *node2 = createNode(2);
    node *node3 = createNode(3);

    addEdge(node1, node2);
    addEdge(node3, node1);
}
