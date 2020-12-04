#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node{
int num;
struct Node *prox
}node;

int cont;

void inicia(node *TO, node *T1, node *saida);
int compara(char op[]);
int vazia(node *T);
node *aloca();
node *insereD(node *T);
node *insereE(node *T);
node *retiraD(node *T);
node *retiraE(node *T);
void exibe(node *saida);
void libera(node *LISTA);
int contagem(node *T);





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

node *saida=(node*)malloc(sizeof(node));
if(!saida){
    exit(1);
}
inicia(T0, T1, saida);

while(scanf(" %s", op) == 1){

   opt=compara(op);
   node *tmp=NULL, *ret=NULL;
   switch(opt){

       case 1:
       tmp=insereD(T0);
       cont++;
       tmp->num=cont;
       break;

       case 2:
       tmp= insereD(saida);
       ret= retiraD(T0);
       tmp->num=ret->num;
       break;

       case 3:
       tmp=insereE(T1);
       cont++;
       tmp->num=cont;
       break;

       case 4:
       tmp=insereD(T1);
       cont++;
       tmp->num=cont;
       break;

       case 5:
       tmp= insereD(saida);
       ret= retiraE(T1);
       tmp->num=ret->num;
       break;

       case 6:
       tmp= insereD(saida);
       ret= retiraD(T1);
       tmp->num=ret->num;
       break;

       case 7:
       tmp =insereD(saida);
       tmp->num=contagem(T0);
       tmp=insereD(saida);
       tmp->num=contagem(T1);
       exibe(saida);
       libera(T0);
       libera(T1);
       libera(saida);
       inicia(T0,T1,saida);
       break;





   }

}
  free(T0);
  free(T1);
  free(saida);
  return 0;


}

void inicia(node *TO, node *T1, node *saida){
TO->prox= NULL;
T1->prox= NULL;
saida->prox=NULL;
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

node *insereD(node *T){
node *novo=aloca();
novo->prox=NULL;

if(vazia(T))
  T->prox=novo;
else{
   node *tmp=T->prox;

   while(tmp->prox != NULL)
    tmp= tmp->prox;

   tmp->prox=novo;

   return novo;

}

}

node *insereE(node *T){
node *novo=aloca();


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

void exibe(node *saida){

    node *tmp=saida->prox;
    while(tmp != NULL){
      printf("%d\n", tmp->num);
      tmp= tmp->prox;
    }
    printf("\n");
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

int contagem(node *T){
    int contador=0;
    node *tmp=T->prox;
    while(tmp != NULL){
      contador++;
      tmp= tmp->prox;
    }
    return contador;

}

