#include <stdio.h>
#include <stdlib.h>

typedef struct Mat {
   int **valor; /* Quantidade de arestas. */
   int **vetor; /* Quantidade de vértices. */
   int arestas[6];
   int arestass[6];
} Mat;

/*Estrutura de Grafo representado por uma matriz de adjacências: */
typedef struct grafo {
   int E; /* Quantidade de arestas. */
   int V; /* Quantidade de vértices. */
   Mat Mat; /* Matrix de adjacências. */
} grafo_matrix;



/*Função para criar um grafo representado como uma matriz de adjacências.*/
grafo_matrix* create_graph (int tamanho) {
   int v;
   grafo_matrix *G = (grafo_matrix *)malloc(sizeof(grafo_matrix));
   G->E = 0;
   G->V = tamanho;
   G->Mat.vetor = (int **)malloc(tamanho * sizeof(int *));
   G->Mat.valor = (int **)malloc(tamanho * sizeof(int *));
   for (v = 0; v < G->V; v++) {
      G->Mat.vetor[v] = (int *)malloc(tamanho * sizeof(int));
      G->Mat.valor[v] = (int *)malloc(tamanho * sizeof(int));
   }

    for (int j=0; j < G->V; j++){
        for (int i=0;i < G->V; i++){
            G->Mat.vetor[i][j] = 0;
            G->Mat.valor[i][j] = 0;
        }
    }

    for (int i=0; i<6; i ++){
        G->Mat.arestas[i]=0;
        G->Mat.arestass[i]=0;
    }
   return G;
}

/*Função para destruir um grafo construído como uma matriz de adjacências.*/
void destroy_graph (grafo_matrix *G) {
   int v;
   for (v = 0; v < G->V; v++) {
      free(G->Mat.vetor[v]);
   }
   free(G->Mat.vetor);
   free(G);
}

/*Função para mostrar um grafo construído como uma matriz de adjacências.*/
void show_graph (grafo_matrix *G) {
   int u, v;
   for (u = 0; u < G->V; u++) {
      for (v = 0; v < G->V; v++) {
         printf("%d ", G->Mat.valor[u][v]);
      }
      printf("\n");
   }
   for (int p=0;p<6;p++){
        printf("Numero de arestas incidentes ao vertice %d: %d\n", p, G->Mat.arestas[p]);
        printf("Numero de arestas que saem do vertice %d: %d\n\n", p, G->Mat.arestass[p]);
    }

    for (int p=0;p<6;p++){
        for (int x=0; x<6;x++){
            if (G->Mat.vetor[p][x]==1 && p!=x){
                printf("%d e vizinho de %d\n", p,x);
            }
        }
        printf("\n");
    }

}

/*Função auxiliar para adicionar uma aresta em um grafo representado por uma matriz de adjacências.*/
void _add_edge (int i, int j, grafo_matrix *G, int z) {
   if (G->Mat.vetor[i][j]) {
      printf("A aresta já existe!\n");
   }
   else {
      G->Mat.vetor[i][j] = 1;
      G->Mat.valor[i][j] = z;
      G->Mat.arestas[j]++;
      G->Mat.arestass[i]++;
   }
}

/*Função para adicionar uma aresta em um grafo (direcionado ou não direcionado) representado por uma matriz de adjacências.*/
void add_edge (int i, int j, grafo_matrix *G, int z) {
   _add_edge (i, j, G, z);
   //_add_edge (j, i, G); /*Direcionado ou não?, só comentar*/
   G->E++; /*Mais uma aresta no grafo!*/
}

/*Função principal.*/
int main () {

   int V = 6; /*Número de vértices*/

   grafo_matrix *G = create_graph (V);

    add_edge(0,1,G,1);

    add_edge (0,3,G,5);

    add_edge (1,3,G,8);

    add_edge (2,0,G,5);

    add_edge (2,3,G,4);

    add_edge (3,3,G,6);

    add_edge (3,4,G,3);

    add_edge (4,2,G,7);

    add_edge (4,5,G,9);

    add_edge (5,0,G,2);

   show_graph (G);

   destroy_graph (G);

   return 0;
}

