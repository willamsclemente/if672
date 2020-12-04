#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node{
int num;
struct Node *prox
}node;

int cont;

void inicia(node *TO, node *T1);
int compara(char op[]);
int vazia(node *T);
node *aloca();
void insereD(node *T);
void insereE(node *T);
node *retiraD(node *T);
node *retiraE(node *T);
void libera(node *LISTA);
void contagem(node *T);


int main(){
  char op[3];
  int opt;

node *T0=(node*)malloc(sizeof(node));
if(!T0){
    exit(1);
}

node *T1=(node*)malloc(sizeof(node));
if(!T1){
    exit(1);
}


inicia(T0, T1);

while(scanf(" %s", op) == 1){


   fflush(stdin);
   opt=compara(op);
   node *tmp=NULL;


       switch(opt){

       case 1:
       insereD(T0);
       break;

       case 2:
       tmp=retiraD(T0);
       printf("%d\n", tmp->num);
       break;

       case 3:
       insereE(T1);
       break;

       case 4:
       insereD(T1);
       break;

       case 5:
       tmp=retiraE(T1);
       printf("%d\n", tmp->num);
       break;

       case 6:
       tmp=retiraD(T1);
       printf("%d\n", tmp->num);
       break;

       case 7:
       contagem(T0);
       contagem(T1);
       printf("\n");
       libera(T0);
       libera(T1);
       inicia(T0,T1);
       break;






   }

}

  free(T0);
  free(T1);
  return 0;

}

void inicia(node *TO, node *T1){
TO->prox= NULL;
T1->prox= NULL;
cont= -1;
}

int compara(char op[]){

if((strcmp(op,"E0")==0))
    return 1;
  else{
    if((strcmp(op,"S0"))==0)
        return 2;
    else{
        if((strcmp(op,"E1E"))==0)
            return 3;
        else{
           if((strcmp(op,"E1D"))==0)
              return 4;
           else{
            if((strcmp(op,"S1E"))==0)
                return 5;
            else{
                if((strcmp(op,"S1D"))==0)
                    return 6;
                else{
                    if((strcmp(op,"FIM"))==0)
                        return 7;
                    else
                        return 8;
                }

            }
           }

    }
  }
}
}

int vazia(node *T){
if(T->prox == NULL)
    return 1;
else
    return 0;
}

node *aloca(){
node *novo=(node*)malloc(sizeof(node));
if(!novo)
    exit(1);
else
   return novo;
}

void insereD(node *T){
node *novo=aloca();
novo->prox=NULL;
cont++;
novo->num=cont;

if(vazia(T))
  T->prox=novo;
else{
   node *tmp=T->prox;

   while(tmp->prox != NULL)
    tmp= tmp->prox;

   tmp->prox=novo;

}

}

insereE(node *T){
node *novo=aloca();
cont++;
novo->num=cont;
node *oldHead= T->prox;
T->prox=novo;

novo->prox= oldHead;

return novo;

}

node *retiraD(node *T){

if(T->prox == NULL)
  return NULL;
else{
    node *ultimo=T->prox, *penultimo=T;
    while(ultimo->prox !=NULL){
        penultimo=ultimo;
        ultimo=ultimo->prox;
    }
    penultimo->prox=NULL;
    return ultimo;
}


}

node *retiraE(node *T){
if(T->prox == NULL)
    return NULL;
else{
    node *tmp=T->prox;
    T->prox= tmp->prox;
    return tmp;
}

}


void libera(node *LISTA){
  node *proxNode=NULL, *atual=NULL;
  atual= LISTA->prox;

  while(atual != NULL){
    proxNode=atual->prox;
    free(atual);
    atual=proxNode;
  }





}

void contagem(node *T){
    int contador=0;
    node *tmp=T->prox;
    while(tmp != NULL){
      contador++;
      tmp= tmp->prox;
    }
    printf("%d\n",contador);


}
