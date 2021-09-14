#include <stdio.h>
#include <stdlib.h>



typedef struct arvore {
   char info;
   struct arvore *esq;
   struct arvore *dir;
} Arvore;

Arvore* cria_arv_vazia (void) {
   return NULL;
}

Arvore* constroi_arv (char c, Arvore *e, Arvore *d) {
   Arvore *no = (Arvore*)malloc(sizeof(Arvore));
   no->info = c;
   no->esq = e;
   no->dir = d;
   return no;
}

int verifica_arv_vazia (Arvore *a) {
   return (a == NULL);
}

void arv_libera (Arvore* a) { //Pós
   if (!verifica_arv_vazia(a)) {
      arv_libera (a->esq);
      arv_libera (a->dir);
      printf("%c", a->info);
      free(a);
   }
}

void arv_libera_pre (Arvore* a) {
   if (!verifica_arv_vazia(a)) {
      printf("%c", a->info);
      arv_libera_pre (a->esq);
      free(a);
      arv_libera_pre (a->dir);
   }
}

void arv_libera_in (Arvore* a) {
   if (!verifica_arv_vazia(a)) {
      arv_libera (a->esq);
      printf("%c", a->info);
      free(a);
      arv_libera_in (a->dir);
   }
}

void imprime_arv_marcadores (Arvore *a){
    if (!verifica_arv_vazia(a)) {
        printf("<");
        printf("%c", a->info);
        imprime_arv_marcadores (a->esq);
        imprime_arv_marcadores (a->dir);
        printf(">");
    }
    else {
        printf("<>");
    }
}


int flag = 1;

int pertence_arv (Arvore *a, char c){
    if (!verifica_arv_vazia(a)) {
        printf("%c", a->info);
        if (a->info=='c'){
            flag=0;
        }
        arv_libera_pre (a->esq);
        free(a);
        arv_libera_pre (a->dir);
    }
    if (flag==0){
        return 1;
    }
   else {
        return 0;
    }
}

int cont=0;
int conta_nos (Arvore *a){
    if (!verifica_arv_vazia(a)) {
      conta_nos (a->esq);
      free(a);
      cont++;
      conta_nos (a->dir);
   }
   return cont;
}

int altura=0;
int calcula_altura_arvore (Arvore *a){
    if (!verifica_arv_vazia(a)) {
      calcula_altura_arvore (a->esq);
              if(!verifica_arv_vazia(a->esq)){
            altura++;
        }
      free(a);

      calcula_altura_arvore (a->dir);
   }
   return altura;
}


int main (int argc, char *argv[]) {

   Arvore *a = constroi_arv ('a',
       constroi_arv('b',
       cria_arv_vazia(),
       constroi_arv('d', cria_arv_vazia(),cria_arv_vazia())
     ),
     constroi_arv('c',
       constroi_arv('e',cria_arv_vazia(),cria_arv_vazia()),
       constroi_arv('f',cria_arv_vazia(),cria_arv_vazia())
     )
   );

   arv_libera_pre (a); //Pré

   printf("\n");

   Arvore *b = constroi_arv ('a',
       constroi_arv('b',
       cria_arv_vazia(),
       constroi_arv('d', cria_arv_vazia(),cria_arv_vazia())
     ),
     constroi_arv('c',
       constroi_arv('e',cria_arv_vazia(),cria_arv_vazia()),
       constroi_arv('f',cria_arv_vazia(),cria_arv_vazia())
     )
   );

   arv_libera(b); //Pós

   printf("\n");

   Arvore *c = constroi_arv ('a',
       constroi_arv('b',
       cria_arv_vazia(),
       constroi_arv('d', cria_arv_vazia(),cria_arv_vazia())
     ),
     constroi_arv('c',
       constroi_arv('e',cria_arv_vazia(),cria_arv_vazia()),
       constroi_arv('f',cria_arv_vazia(),cria_arv_vazia())
     )
   );

   arv_libera_in(c); //In

   printf("\n");

    Arvore *d = constroi_arv ('a',
       constroi_arv('b',
       cria_arv_vazia(),
       constroi_arv('d', cria_arv_vazia(),cria_arv_vazia())
     ),
     constroi_arv('c',
       constroi_arv('e',cria_arv_vazia(),cria_arv_vazia()),
       constroi_arv('f',cria_arv_vazia(),cria_arv_vazia())
     )
   );

   imprime_arv_marcadores(d);

   printf("\n");

    Arvore *e = constroi_arv ('a',
       constroi_arv('b',
       cria_arv_vazia(),
       constroi_arv('d', cria_arv_vazia(),cria_arv_vazia())
     ),
     constroi_arv('c',
       constroi_arv('e',cria_arv_vazia(),cria_arv_vazia()),
       constroi_arv('f',cria_arv_vazia(),cria_arv_vazia())
     )
   );

   conta_nos(e);

    printf("%d\n", cont);

        Arvore *f = constroi_arv ('a',
       constroi_arv('b',
       cria_arv_vazia(),
       constroi_arv('d', cria_arv_vazia(),cria_arv_vazia())
     ),
     constroi_arv('c',
       constroi_arv('e',cria_arv_vazia(),cria_arv_vazia()),
       constroi_arv('f',cria_arv_vazia(),cria_arv_vazia())
     )
   );

    calcula_altura_arvore(f);

    printf("%d", altura);

   return 0;
}

