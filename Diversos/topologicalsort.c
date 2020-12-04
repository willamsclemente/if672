#include<stdio.h>
#include<stdlib.h>


typedef struct Node{
int V;
struct Node *prox;
}node;


void inserearesta(node *grafo, int v, int w, int num);
void topologicalsort(node *grafo, int num);
node * dfs(node *grafo, int num);
int dfsvisit(char cor[], int pai[], int i, node *grafo, int num);



int main(){
int num, ch, i,v,w;

 scanf("%d", &num);
 node *grafo=(node*)malloc(num *sizeof(node));
 node *tmp;

 for(i=0; i<num; i++){
    scanf("%d", &ch);
    tmp=(grafo+i);
    tmp->V=ch;
    tmp->prox=NULL;
 }

 while(scanf("%d", &v)== 1){
    scanf("%d", &w);
    inserearesta(grafo, v, w, num);
 }

printf("\n");
topologicalsort(grafo, num);


}

void inserearesta(node *grafo, int v, int w, int num){
int i;

for(i=0; i<num; i++){
 if((grafo+i)->V == v){
    if((grafo+i)->prox == NULL){
        node *novo=(node*)malloc(sizeof(node));
        novo->V=w;
        novo->prox=NULL;
        (grafo+i)->prox=novo;
    }else{
      node *tmp=(grafo+i)->prox;

      while(tmp->prox != NULL)
         tmp=tmp->prox;

      node *novo=(node*)malloc(sizeof(node));
      novo->prox=NULL;
      novo->V=w;

      tmp->prox=novo;



    }
 }

}


    }


void topologicalsort(node *grafo, int num){

node *res=dfs(grafo, num);

node *tmp=res->prox;

while(tmp != NULL){
    printf("%d ", tmp->V);
    tmp=tmp->prox;
}



}

node * dfs(node *grafo, int num){
int i, pai[num], res;
char cor[num];
node *vet=(node*)malloc(sizeof(node));
vet->prox=NULL;
for(i=0; i<num; i++){
    cor[i]='B';
    pai[i]=-1;
}

for(i=0; i<num; i++){
    if(cor[i] ==  'B'){
    res=dfsvisit(cor, pai, i, grafo, num);
    printf("%d\n", res);
    if(vet->prox == NULL){
        node *novo=(node*)malloc(sizeof(node));
        novo->prox=NULL;
        novo->V=res;
        vet->prox=novo;
    }else{
       node *novo=(node*)malloc(sizeof(node));
       novo->prox=NULL;
       novo->V=res;

       node *tmp=vet->prox;
       vet->prox=novo;
       novo->prox=tmp;


    }
    }


}


return vet;
}

int dfsvisit(char cor[], int pai[], int i, node *grafo, int num){
int j=0;
cor[i]='C';


node *tmp=(grafo+i);

while(tmp != NULL){
    for(j=0; j<num; j++)
      if(((grafo+j)->V) == tmp->V){
          if(cor[j] == 'B'){
           pai[j]=tmp->V;

           dfsvisit(cor, pai, j, grafo, num);
          }
      }
          tmp=tmp->prox;


}

cor[i]='P';
printf("%d\n", (grafo+i)->V);

 return ((grafo+i)->V);


}


