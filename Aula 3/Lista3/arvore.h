#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct arvore {
  int info;
  struct arvore *esq;
  struct arvore *dir;
} Arvore;

int buscar (Arvore *a, int v);

Arvore* inserir (Arvore *a, int v);

Arvore* remover (Arvore *a, int v);

void imprime_decrescente (Arvore *a);

int max(Arvore *a);

int min(Arvore *a);

