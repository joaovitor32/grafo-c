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

class Queue
{
    class Node *nodes;
};

class Edges
{
    class Node *nodes;
};

typedef class Node node;
typedef class Graph graph;
typedef class Queue queue;
typedef class Edges edges;

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
    newNode->search = FALSE;
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
    graph *Graph = (class Graph *)malloc(sizeof(graph));
    Graph->nodes = (class Node *)malloc(sizeof(class node *));
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

/*Provavelmente isso vai dar erro - Talvez a me
Talvez esteja sendo apontado um espaço na memória 
incompatível
*/
node *pop(class Queue *queue, int index)
{
    class Node *element = &queue->nodes[index];
    free(&queue->nodes[index]);
    return element;
}

void append(class Queue *queue, class Node node)
{
    int index = getIndexEdges(queue->nodes);
    queue->nodes[index] = node;
}

void BFS(class Graph *graph, int start, int end)
{
    class Queue *queue = malloc(sizeof(class Queue));
    class Edge **edges = malloc(sizeof(class Edges));
    class Node *current = malloc(sizeof(class Node));
    class Node *neighbor = malloc(sizeof(class Node));
    graph->start = graph->nodes[start];
    graph->end = graph->nodes[end];

    int i = 0;
    queue->nodes[0] = *graph->start;
    while (getIndexEdges(queue->nodes) > 0)
    {
        current = pop(queue, 0);
        if (current == graph->end)
        {
            printf("End node was found!");
            break;
        }
        else
        {
            edges = current->edges;
            while (edges[i] != NULL)
            {
                neighbor = edges[i];
                if (neighbor->search == FALSE)
                {
                    neighbor->search = TRUE;
                    neighbor->parent = current;
                    append(queue, *neighbor);
                }
            }
            i++;
        }
    }
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
    node *node4 = createNode(4);
    node *node5 = createNode(5);

    addEdge(node1, node2);
    addEdge(node3, node1);
    addEdge(node4, node5);
    addEdge(node2, node5);

    addNode(Graph, node1);
    addNode(Graph, node2);
    addNode(Graph, node3);
    addNode(Graph, node4);
    addNode(Graph, node5);

    printGraph(Graph);

    free(Graph);
}
