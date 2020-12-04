#include<stdio.h>
#include<stdlib.h>

typedef struct arvore{
int fb;
int key;
struct arvore *esq;
struct arvore *dir;
}node;

void insere(node **root, int k);
int alt(node *nodeR);
void rotacaoSD(node *nodeR, node *pai);
void rotacaoSE(node *nodeR, node *pai);
void rotacaoDUPLAD(node *nodeR, node *pai);
void rotacaoDUPLAE(node *nodeR, node *pai);
void exibirO(node *nodeR);
void exibirOS(node *nodeR);




int main(){
int key;
node *root=NULL;

 while(scanf("%d", &key)==1){
     insere(&root, key);
 }
exibirO(root);
printf("\n");
exibirOS(root);


}




void insere(node **root, int k){
node *pai;
if(*root == NULL){
    node *novo=(node*)malloc(sizeof(node));
    novo->key=k;
    novo->dir=NULL;
    novo->esq=NULL;
    novo->fb=0;
    *root=novo;
    return;
}
else{
     pai=*root;
    if(k >=(*root)->key){
      insere(&(*root)->dir,k);
      (*root)->fb=(alt((*root)->dir) -alt((*root)->esq));
      if((*root)->fb == 2)
        if((*root)->dir->key <= k){
            printf("\n\n%d %d", (*root)->key, pai->key);
            rotacaoSE(*root, pai);
        }
        else
            rotacaoDUPLAD(*root, pai);
      return;
    }
    else{
       insere(&(*root)->esq, k);
      (*root)->fb=(alt((*root)->dir) -alt((*root)->esq));
       if((*root)->fb == -2)
         if((*root)->esq->key > k)
         rotacaoSD(*root, pai);
         else
            rotacaoDUPLAE(*root, pai);

       return;
    }


}
}


void exibirO(node *nodeR){
if(nodeR != NULL){
   exibirO(nodeR->esq);
   printf("%d ", nodeR->key);
   exibirO(nodeR->dir);

}


}

void exibirOS(node *nodeR){
if(nodeR != NULL){
   exibirOS(nodeR->esq);
   printf("%d ", nodeR->fb);
   exibirOS(nodeR->dir);

}


}

int alt(node *nodeR){
int esq, dir;
if(nodeR == NULL)
    return -1;
esq=alt(nodeR->esq);
dir=alt(nodeR->dir);

if(esq > dir)
    return esq+1;
else
    return dir+1;

}

void rotacaoSD(node *nodeR, node *pai){
node *aux;
printf("rsd1");
printf("lá vem o pai");
pai->esq=nodeR->esq;
printf("\n%d", pai->key);
aux= nodeR->esq->dir;
nodeR->esq->dir=nodeR;
nodeR->esq=aux;

printf("rsd2");

}

void rotacaoSE(node *nodeR, node *pai){
node *aux;
printf("\n%d", nodeR->key);
printf("rse1");
printf("lá vem o pai");
pai->dir=nodeR->dir;
printf("\n%d", pai->key);
aux= nodeR->dir->esq;
nodeR->dir->esq=nodeR;
nodeR->dir=aux;
printf("rse2");



}

void rotacaoDUPLAE(node *nodeR, node *pai){
node *aux, *aux1;
printf("rde1");
pai->esq=nodeR->esq->dir;
aux =nodeR->esq->dir->esq;
aux1 =nodeR->esq->dir->dir;

nodeR->esq->dir->esq= nodeR->esq;
nodeR->esq->dir->dir= nodeR;

nodeR->esq->dir=aux;
nodeR->esq=aux1;

printf("rde2");


}

void rotacaoDUPLAD(node *nodeR, node *pai){
node *aux, *aux1;
printf("rdd1");
pai->dir= nodeR->dir->esq;
aux=nodeR->dir->esq->esq;
aux1=nodeR->dir->esq->dir;

nodeR->dir->esq->esq=nodeR;
nodeR->dir->esq->dir=nodeR->dir;

nodeR->dir=aux;
nodeR->dir->esq=aux1;

printf("rdd2");

}

