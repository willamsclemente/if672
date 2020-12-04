#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node{
int num;
struct Node *prox
}node;

int cont,contador=0;

void inicia(node *TO, node *T1);
int compara(char op[]);
node *aloca();
void insereD(node *T);
void insereE(node *T);
node *retiraD(node *T);
node *retiraE(node *T);
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
       contador=0;
       contagem(T0);
       contador=0;
       contagem(T1);
       printf("\n");
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


node *aloca(){
node *novo=(node*)malloc(sizeof(node));
if(!novo)
    exit(1);
else
   return novo;
}

void insereD(node *T){
if(T->prox == NULL){
  node *novo=aloca();
  novo->prox=NULL;
  cont++;
  novo->num=cont;
  T->prox=novo;

}
else{
   insereD(T->prox);
}

}

void insereE(node *T){
node *novo=aloca();
cont++;
novo->num=cont;
node *oldHead= T->prox;
T->prox=novo;

novo->prox= oldHead;

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

void contagem(node *T){

    if(T->prox != NULL){
        contador++;
        contagem(T->prox);
    }
    else
     printf("%d\n", contador);


}


