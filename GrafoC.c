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
    class Node *parent;
    class Node *edges;
};

class Graph
{
    *nodes;
    class Node *start;
    class Node *end;
};
typedef class Node node;
typedef class Graph graph;
/*---------- Métodos do Node ------------*/

node *addEdge(node *node1, node *node2)
{
}
/*---------- Métodos do Grafo ------------*/

graph *addNode(graph *gph, node *n)
{

    if (gph->nodes == NULL)
    {
        printf("Grafo está vazio!\n\n");
        return;
    }

    for (int i = 0; i < GRAPH_SIZE; i++)
    {
        if (gph->nodes[i] == NULL)
        {
            gph->nodes[i] = n;
            return;
        }
    }
}

graph *getNode(graph *g, int value)
{
}

int main(void)
{
    graph *Graph = (graph *)malloc(sizeof(graph));

    Graph->nodes = (class node *)malloc(sizeof(node));

    if (!Graph)
    {
        printf("Sem memoria disponivel!\n");
        exit(1);
    }
    else
    {
        inicia(Graph);
        int opt;

        do
        {
            opt = menu();
            opcao(Graph, opt);
        } while (opt);

        free(Graph);
        return 0;
    }
}

int menu(void)
{
    int opt;

    printf("Escolha a opcao\n");
    printf("0. Sair\n");
    scanf("%d", &opt);

    return opt;
}

void opcao(node *Graph, int op)
{
    node *tmp;
    switch (op)
    {
    case 0:
        libera(Graph);
        break;

    default:
        printf("Comando invalido\n\n");
    }
}
