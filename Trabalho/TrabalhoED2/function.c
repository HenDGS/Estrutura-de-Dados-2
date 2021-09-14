#include "function.h"

void dijikstra(int matriz[N][N], int n, int noinicial){
	int custo[N][N], distancia[N],visitado[N];
	int min, proximo, i,j;

	/*Contador serve para ver o número de nós vistos até agora
	Cria o custo da matriz*/
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(matriz[i][j]==0){
				custo[i][j]=INF;
			}
			else {
				custo[i][j]=matriz[i][j];
			}
		}
	}

	//Inicializa pred, distancia e visitados
	for(i=0;i<n;i++){
		distancia[i]=custo[noinicial][i]; //Inicializa a distancia do array com o custo da matriz pelo noinicial
		visitado[i]=0; //Inicializa o array visitado com 0
	}
	distancia[noinicial]=0; //distancia do inicial para o no inicial e 0
	visitado[noinicial]=1; //Incializa o arrayincial como visitado


	for (int z = 1; z <= n-1; z++){
		min=INF; //Minimo como infinito
		//Próximo nó dara a distancia minima
		for(i=0;i < n;i++){
			if(distancia[i] < min&& !visitado[i]){ //Olha se o vizinho foi visitado ou não, e se é menor
				min=distancia[i];
				proximo=i;
			}
		}
		visitado[proximo]=1; //Marca ele como visitado
		//Checa se existe um caminho melhor
		for(i=0;i<n;i++){ //Olha se o no é um vertice
			if(!visitado[i]){
				if(min+custo[proximo][i] < distancia[i]){ //Verifica se a distancia mais o custo é menor do que a
					distancia[i]=min+custo[proximo][i];   //distancia pelo outro no
				}
			}
		}
	}

	printf("\nMelhor caminho: \n");
	for (int i = 0; i <= n-1; i++){ //Imprime o melhor caminho
			printf("\n%d->%d = %d\n", noinicial, i, distancia[i]);
	}
}

