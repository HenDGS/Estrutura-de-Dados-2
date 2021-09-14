#include "arvore.h"

void imprimir_in_ordem (Arvore *a) {
    if (a != NULL) {
        imprimir_in_ordem (a->esq);
        printf ("%d\n", a->info);
        imprimir_in_ordem (a->dir);
    }
}

int main () {
    Arvore *a = NULL;
    Arvore *b = NULL;

    clock_t start1 = clock();

    long long i =0;
    for (i=0;i<100000;i++){
        a = inserir (a, i);
    }

    clock_t end1 = clock();

    float seconds1 = (float)(end1 - start1) / CLOCKS_PER_SEC;

    printf("Tempo para inserir: %f\n", seconds1);

    clock_t start2 = clock();

    for (i=0;i<100000;i++){
        b = inserir(rand() % 99999,i);
    }

    clock_t end2 = clock();

    float seconds2 = (float)(end2 - start2) / CLOCKS_PER_SEC;

    printf("Tempo para buscar randomicamente: %f\n", seconds2);

    clock_t start3 = clock();

    int z = buscar(b,100000);

    printf("%d\n", z);

    clock_t end3 = clock();

    float seconds3 = (float)(end3 - start3) / CLOCKS_PER_SEC;

    printf("Tempo para buscar randomicamente: %f\n", seconds3);


   /*a = inserir (a, 50);
   a = inserir (a, 30);
   a = inserir (a, 90);
   a = inserir (a, 20);
   a = inserir (a, 40);
   a = inserir (a, 95);
   a = inserir (a, 10);
   a = inserir (a, 35);
   a = inserir (a, 45);*/
    //imprimir_in_ordem (a);

    return 0;
}

