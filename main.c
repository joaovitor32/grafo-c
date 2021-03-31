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
    int edgesArrayLength;
};

class Graph
{
    class Node **nodes;
    class Node *start;
    class Node *end;
    int nodeArrayLength;
};

class Queue
{
    int nodesArrayLength;
    class Node **nodes;
};

typedef class Node node;
typedef class Graph graph;
typedef class Queue queue;

/*------------------- Método de Queue --------------------*/

queue *createQueue()
{
    queue *Queue = (class Queue *)malloc(sizeof(queue));
    Queue->nodes = malloc(sizeof(class node *));
    Queue->nodesArrayLength = 0;
    return Queue;
}

/*---------- Métodos do Node ------------*/

class Node *createNode(int value)
{

    class Node *newNode = malloc(sizeof(class Node));
    newNode->data = value;
    newNode->search = FALSE;
    newNode->edges = malloc(sizeof(class node *));
    newNode->edgesArrayLength = 0;
    return newNode;
}

//Adding Edge in the last position in both arrays of type edge
void addEdge(class Node *node1, class Node *node2)
{
    node1->edges[node1->edgesArrayLength++] = node2;
    node2->edges[node2->edgesArrayLength++] = node1;
}

/*---------- Métodos do Grafo ------------*/
graph *createGraph()
{
    graph *Graph = (class Graph *)malloc(sizeof(graph));
    Graph->nodes = malloc(sizeof(class node *));
    Graph->start = NULL;
    Graph->end = NULL;
    Graph->nodeArrayLength = 0;
    return Graph;
}

void addNode(class Graph *graph, class Node *node)
{
    graph->nodes[graph->nodeArrayLength++] = node;
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

    printf("Percorrendo o grafo: \n");
    for (int j = 0; j < i; j++)
    {
        printf("%d-> %d\n", j, path[j].data);
    }
}

/*Provavelmente isso vai dar erro - Talvez a me
Talvez esteja sendo apontado um espaço na memória 
incompatível, POP no nosso caso sempre vai retirar o
primeiro elemento
*/
node *pop(class Queue *queue)
{
    class Node *element = queue->nodes[0];
    free(&queue->nodes[0]);

    for (int i = 0; i < queue->nodesArrayLength; i++)
    {
        queue->nodes[i] = queue->nodes[i++];
    }
    queue->nodesArrayLength--;

    return element;
}

void append(class Queue *queue, class Node *node)
{
    queue->nodes[queue->nodesArrayLength++] = node;
}
// Start and End are indexes
void BFS(class Graph *graph, int start, int end)
{

    class Queue *queue = createQueue();
    class Node *current = malloc(sizeof(class Node));
    class Node *neighbor = malloc(sizeof(class Node));
    graph->start = graph->nodes[start];
    graph->end = graph->nodes[end];
    graph->start->search = TRUE;

    printf("Start: %d\n", graph->start->data);
    printf("End: %d\n", graph->end->data);

    append(queue, graph->start);

    while (queue->nodesArrayLength > 0)
    {

        current = pop(queue);

        if (current->data == graph->end->data)
        {
            printf("End node was found!\n");
            break;
        }
        else
        {
            for (int i = 0; i < current->edgesArrayLength; i++)
            {
                neighbor = current->edges[i];
                if (neighbor->search == FALSE)
                {
                    neighbor->search = TRUE;
                    neighbor->parent = current;
                    append(queue, neighbor);
                }
            }
        }
    }
    getPathBFS(graph);
}

void printGraph(class Graph *graph)
{
    for (int i = 0; i < graph->nodeArrayLength; i++)
    {
        printf("Index: %i - Value:%d \n ", i, graph->nodes[i]->data);
    }
}

int main(void)
{
    graph *Graph = createGraph();

    node *node1 = createNode(11);
    node *node2 = createNode(22);
    node *node3 = createNode(33);
    node *node4 = createNode(44);

    addEdge(node1, node2);
    addEdge(node3, node1);
    addEdge(node3, node1);
    addEdge(node2, node3);
    addEdge(node4, node3);

    addNode(Graph, node1);
    addNode(Graph, node2);
    addNode(Graph, node3);
    addNode(Graph, node4);

    BFS(Graph, 3, 0);

    free(Graph);
}
