#include "function.h"

int main(){
	int i, j, n, node;
	printf("Digite o numero de vertices: \n");
	scanf("%d", &n);
	int matriz[n][n];
	printf("\nDigite a matriz de adjacencia do grafo: \n");
	for(i=0;i < n;i++)
		for(j=0;j < n;j++)
			scanf("%d", &matriz[i][j]);
	printf("\n Digite o no de base: (0 para A, 1 para B, ...) \n");
	scanf("%d", &node);
	if (node > n){
        printf("Invalido\n"); //Nega entrada invalida
	}
	dijikstra(matriz,n,node); // Chama a funcao para calcular o menor caminho

	return 0;
}


