#include <stdio.h>
#include <stdlib.h>

/*Estrutura de Grafo representado por uma matriz de adjacências: */
typedef struct grafo {
   int E; /* Quantidade de arestas. */
   int V; /* Quantidade de vértices. */
   int **Mat; /* Matrix de adjacências. */
} grafo_matrix;

/*Função para criar um grafo representado como uma matriz de adjacências.*/
grafo_matrix* create_graph (int tamanho) {
   int v;
   grafo_matrix *G = (grafo_matrix *)malloc(sizeof(grafo_matrix));
   G->E = 0;
   G->V = tamanho;
   G->Mat = (int **)malloc(tamanho * sizeof(int *));
   for (v = 0; v < G->V; v++) {
      G->Mat[v] = (int *)malloc(tamanho * sizeof(int));
   }

    for (int j=0; j < G->V; j++){
        for (int i=0;i < G->V; i++){
            G->Mat[i][j] = 0;
        }
    }
   return G;
}

/*Função para destruir um grafo construído como uma matriz de adjacências.*/
void destroy_graph (grafo_matrix *G) {
   int v;
   for (v = 0; v < G->V; v++) {
      free(G->Mat[v]);
   }
   free(G->Mat);
   free(G);
}

/*Função para mostrar um grafo construído como uma matriz de adjacências.*/
void show_graph (grafo_matrix *G) {
   int u, v;
   for (u = 0; u < G->V; u++) {
      for (v = 0; v < G->V; v++) {
         printf("%d ", G->Mat[u][v]);
      }
      printf("\n");
   }
}

/*Função auxiliar para adicionar uma aresta em um grafo representado por uma matriz de adjacências.*/
void _add_edge (int i, int j, grafo_matrix *G) {
   if (G->Mat[i][j]) {
      printf("A aresta já existe!\n");
   }
   else {
      G->Mat[i][j] = 1;
   }
}

/*Função para adicionar uma aresta em um grafo (direcionado ou não direcionado) representado por uma matriz de adjacências.*/
void add_edge (int i, int j, grafo_matrix *G) {
   _add_edge (i, j, G);
   //_add_edge (j, i, G); /*Direcionado ou não?, só comentar*/
   G->E++; /*Mais uma aresta no grafo!*/
}

/*Função principal.*/
int main () {

   int V = 6; /*Número de vértices*/

   grafo_matrix *G = create_graph (V);

    add_edge(1,0,G);

    add_edge (5,0,G);

    add_edge (2,1,G);

    add_edge (3,1,G);

    add_edge (0,2,G);

    add_edge (4,2,G);

    add_edge (2,3,G);

    add_edge (3,4,G);

    add_edge (4,5,G);

   show_graph (G);

   //Correto

   destroy_graph (G);

   return 0;
}

