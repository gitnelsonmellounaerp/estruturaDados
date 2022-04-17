#include <stdlib.h>
#include <stdio.h>

struct nodetype{
    int info;
    struct  nodetype *esq;
    struct nodetype *dir;
    
}; typedef struct nodetype *NODEPTR;

NODEPTR maketree(int x){
    
   NODEPTR p; 

    p = malloc(sizeof(NODEPTR));
    p->info = x;
    p->esq = NULL;
    p->dir = NULL;
    return (p);
}

setLeft(NODEPTR p, int x){
    
    if (p == NULL){
        printf("Insercao vazia.");
    }else if (p->esq != NULL){
        printf("Insercao incorreta");
    }else {
        p->esq = maketree(x);
    }
}

setRight(NODEPTR p, int x){
    if(p == NULL){
        printf("Insercao vazia.");
    }else if(p->esq != NULL){
        printf("Insecao incorreta");
    }else {
        p->dir = maketree(x);
    }
}




int main (){

    NODEPTR pArvore;
    NODEPTR p, q;

    int numero;

  

 

/* Le o primeiro número da arvore binária e seta ela como raiz */

    printf("\nDigite o primeiro numero da raiz: ");
    scanf("%d", &numero);
    pArvore = maketree(numero);


    while (scanf("%d", &numero) != EOF){
        
        p = q = pArvore;
        while (numero != p->info && q != NULL){
            p = q;
            if (numero < p ->info){
                q = p->esq;
            }else {
                q = p->dir;
            }
        }
        if (numero == p->info){
            printf("%d esta repetido", numero);
        }else if (numero < p->info) {
            setLeft(p, numero);
        }else {
            setRight(p, numero);
        }
        
        
    }
    






 return 0;
}