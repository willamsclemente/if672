#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node{
int num;
struct Node *prox;
struct Node *ant;
}node;

int cont, cont0, cont1;;

void inicia(node *TOi, node *T1i, node *T0f, node *T1f);
int compara(char op[]);
node *aloca();
void insereD(node *Tf, node *Ti);
void insereE(node *Tf, node *Ti);
node *retiraD(node *T);
node *retiraE(node *T);


int main(){
  char op[3];
  int opt;

node *T0i=(node*)malloc(sizeof(node));
if(!T0i){
    exit(1);
}

node *T0f=(node*)malloc(sizeof(node));
if(!T0f){
    exit(1);
}


node *T1i=(node*)malloc(sizeof(node));
if(!T1i){
    exit(1);
}

node *T1f=(node*)malloc(sizeof(node));
if(!T0f){
    exit(1);
}


inicia(T0i, T1i, T0f, T1f);

while(scanf(" %s", op) == 1){


   fflush(stdin);
   opt=compara(op);
   node *tmp=NULL;


       switch(opt){

       case 1:
       insereD(T0f, T0i);
       cont0++;
       break;

       case 2:
       tmp=retiraD(T0f);
       printf("%d\n", tmp->num);
       cont0--;
       break;

       case 3:
       insereE(T1f, T1i);
       cont1++;
       break;

       case 4:
       insereD(T1f, T1i);
       cont1++;
       break;

       case 5:
       tmp=retiraE(T1i);
       printf("%d\n", tmp->num);
       cont1--;
       break;

       case 6:
       tmp=retiraD(T1f);
       printf("%d\n", tmp->num);
       cont1--;
       break;

       case 7:
       printf("%d\n", cont0);
       printf("%d\n", cont1);
       printf("\n");
       inicia(T0i, T1i, T0f, T1f);
       break;






   }

}

  free(T0i);
  free(T1i);
  free(T0f);
  free(T1f);
  return 0;

}

void inicia(node *TOi, node *T1i, node *T0f, node *T1f){
TOi->prox= NULL;
T1i->prox= NULL;
T0f->ant=NULL;
T1f->ant=NULL;
cont= -1;
cont0=0;
cont1=0;
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

void insereD(node *Tf, node *Ti){
if(Tf->ant == NULL){
node *novo=aloca();
cont++;
novo->num=cont;
Tf->ant=novo;
novo->prox=Tf;
novo->ant=Ti;
Ti->prox=novo;
}
else{
node *novo=aloca();
cont++;
novo->num=cont;
node *oldHeadf=Tf->ant;
Tf->ant=novo;

novo->ant=oldHeadf;
novo->prox=Tf;
oldHeadf->prox=novo;
}

}

void  insereE(node *Tf, node *Ti){
if(Ti->prox == NULL){
node *novo=aloca();
cont++;
novo->num=cont;
Ti->prox=novo;
novo->prox=Tf;
novo->ant=Ti;
Tf->ant=novo;
}
else{
node *novo=aloca();
cont++;
novo->num=cont;
node *oldHeadi= Ti->prox;
Ti->prox=novo;

novo->prox= oldHeadi;
novo->ant=Ti;
oldHeadi->ant=novo;
}
}

node *retiraD(node *T){
    if(T->ant== NULL){
        return NULL;
    }
    else{
    node *tmp=T->ant;
    T->ant=tmp->ant;
    tmp->ant->prox=T;
    return tmp;
    }
}



node *retiraE(node *T){
    if(T->prox == NULL){
        return NULL;
    }
    else{
    node *tmp=T->prox;
    T->prox= tmp->prox;
    tmp->prox->ant=T;
    return tmp;
    }
}




