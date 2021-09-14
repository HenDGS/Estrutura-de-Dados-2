#include <stdio.h>
#include <stdlib.h>

/*Estrutura para um nó em uma lista encadeada: */
typedef struct _no {
   int id;           /*Identificador armazenado no nó. */
   struct _no *next; /*Próximo nó na lista encadeada. */
} nodo;

/*Estrutura de Grafo representado por uma lista de adjacências: */
typedef struct {
   int E; /* Quantidade de arestas. */
   int V; /* Quantidade de vértices. */
   nodo **Adj; /* Lista de adjacências. */
} grafo_lista;

/*Função para criar um grafo representado como uma lista de adjacências.*/
grafo_lista* create_graph (int tamanho) {
   int v;
   grafo_lista *G = (grafo_lista *)malloc(sizeof(grafo_lista));
   G->E = 0;
   G->V = tamanho;
   G->Adj = (nodo **)malloc(tamanho * sizeof(nodo *));
   for (v = 0; v < G->V; v++) {
      G->Adj[v] = NULL; /*Inicializando cada uma das listas encadeadas de adjacência!*/
   }
   return G;
}

/*Função para destruir um grafo construído como uma lista de adjacências.*/
void destroy_graph (grafo_lista *G) {
   int v;
   for (v = 0; v < G->V; v++) {
      if (G->Adj[v] != NULL) {
         free(G->Adj[v]);
      }
   }
   free(G->Adj);
   free(G);
}

/*Função para mostrar um grafo construído como uma matriz de adjacências.*/
void show_graph (grafo_lista *G) {
   int v;
   for (v = 0; v < G->V; v++) {
      nodo *u;
      printf ("%d -> ", v);
      for (u = G->Adj[v]; u != NULL; u = u->next) {
         printf ("%d, ", u->id);
      }
      printf("\n");
   }
}

/*Função auxiliar para adicionar uma aresta em um grafo representado por uma lista de adjacências.*/
void _add_edge (int i, int j, grafo_lista *G) {
   nodo *aux, *ultimo = NULL;
   for (aux = G->Adj[i]; aux != NULL; aux = aux->next) {
      if (aux->id == j) {
         printf("A aresta já existe!\n");
         return;
      }
      ultimo = aux;
   }
   nodo *novo = (nodo *)malloc(sizeof(nodo));
   novo->id = j;
   novo->next = NULL;
   if (ultimo != NULL)
      ultimo->next = novo;
   else {
      G->Adj[i] = novo;
   }
}

/*Função para adicionar uma aresta em um grafo (direcionado ou não direcionado) representado por uma lista de adjacências.*/
void add_edge (int i, int j, grafo_lista *G) {
   _add_edge (i, j, G);
   //_add_edge (j, i, G); /*Direcionado ou não?*/
   G->E++; /*Mais uma aresta no grafo!*/
}

/*Função principal.*/
int main () {

   int V = 6; /*Número de vértices*/

   grafo_lista* G = create_graph (V);

    add_edge(0,1,G);

    add_edge (0,5,G);

    add_edge (1,2,G);

    add_edge (1,3,G);

    add_edge (2,0,G);

    add_edge (2,4,G);

    add_edge (3,2,G);

    add_edge (4,3,G);

    add_edge (5,4,G);

   show_graph (G);

   destroy_graph (G);

   return 0;
}

