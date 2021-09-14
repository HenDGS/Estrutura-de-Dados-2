#include "arvore.h"

int j=0;

int buscar (Arvore *a, int v) {
  if (a == NULL) {
    return 0;
  }
  else if (v < a->info) {
    return buscar (a->esq, v);
  }
  else if (v > a->info) {
    return buscar (a->dir, v);
  }
  else {
    return 1;
  }
}

Arvore* inserir (Arvore *a, int v) {
  if (a == NULL) {
    a = (Arvore*)malloc(sizeof(Arvore));
    a->info = v;
    a->esq = NULL;
    a->dir = NULL;
  }
  else if (v < a->info) {
    a->esq = inserir (a->esq, v);
  }
  else {
    a->dir = inserir (a->dir, v);
  }
  return a;
}

long long conta_nos (Arvore *a){
    if (a!=NULL) {
      conta_nos (a->esq);
      free(a);
      cont++;
      conta_nos (a->dir);
      tamanho=conta_nos(a);
      long long valores[tamanho];
   }
   return valores;
}

void imprime_decrescente (Arvore *a){
    long long valores = conta_nos;
    while (a!=NULL){
        valores[j]=a->info
        j++;
        imprime_decrescente (a->esq);
        imprime_decrescente (a->dir);
    }
    size_t tamanho_lista = sizeof(valores) / sizeof(valores[0]);
    sort(valores);
    for (i=0;i<tamanho_lista;i++){
        printf(valores[i]);
    }

}

int max(Arvore *a){
    if (a==NULL)
        return 0;
    else {
        int valor;
        if (a->info > valor){
            valor=a->info;
        }
        int maxdireita = max(a->dir);
        int maxesquerda = max(a->esq);
        return valor;
    }
}

int min(Arvore *a){
    if (a==NULL)
        return 0;
    else {
        int valor;
        if (a->info < valor){
            valor=a->info;
        }
        int maxdireita = min(a->dir);
        int maxesquerda = min(a->esq);
        return valor;
    }
}

Arvore* remover (Arvore *a, int v) {
  if (a == NULL) { return NULL; }
  else {
    if (a->info > v)
       a->esq = remover (a->esq, v);
    else if (a->info < v)
       a->dir = remover (a->dir, v);
    else {
       if ((a->esq == NULL) && (a->dir == NULL)) {
          free(a);
          a = NULL;
       }
       else if (a->dir == NULL) {
          Arvore *tmp = a;
          a = a->esq;
          free (tmp);
       }
       else if (a->esq == NULL) {
          Arvore *tmp = a;
          a = a->dir;
          free (tmp);
       }
       else {
          Arvore *tmp = a->esq;
          while (tmp->dir != NULL)
            tmp = tmp->dir;
          a->info = tmp->info;
          tmp->info = v;
          a->esq = remover (a->esq, v);
       }
    }
    return a;
  }
}

