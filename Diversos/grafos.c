#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
int V;
struct Node *prox;
}node;

void inserearesta(node *grafo, int v, int w, int num);



int main(){
int num,i, ch,v,w;
scanf("%d", &num);
node *grafo=(node*)malloc(num*sizeof(node));
node *tmp;
for(i=0; i<num; i++){
  scanf("%d", &ch);
  tmp=(grafo+i);
  tmp->V=ch;
  tmp->prox=NULL;
}

while(scanf("%d", &v)==1){
         scanf("%d", &w);
       inserearesta(grafo, v,w,num);

}




for(i=0; i<num; i++){
  printf("\n%d", (grafo+i)->V);

  tmp=(grafo+i)->prox;
  while(tmp != NULL){
    printf("->%d", tmp->V);
    tmp=tmp->prox;
  }

}
return 0;
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
            }
            else{
                node *tmp=(grafo+i)->prox;
                while(tmp->prox != NULL)
                   tmp=tmp->prox;

                node *novo=(node*)malloc(sizeof(node));
                novo->V=w;
                novo->prox=NULL;
                tmp->prox=novo;

            }
        }
    }

     for(i=0; i<num; i++){
        if((grafo+i)->V == w){
            if((grafo+i)->prox == NULL){
                node *novo=(node*)malloc(sizeof(node));
                novo->V=v;
                novo->prox=NULL;
                (grafo+i)->prox=novo;
            }
            else{
                node *tmp=(grafo+i)->prox;
                while(tmp->prox != NULL)
                   tmp=tmp->prox;

                node *novo=(node*)malloc(sizeof(node));
                novo->V=v;
                novo->prox=NULL;
                tmp->prox=novo;

            }
        }
    }


}


void bfs(node *grafo, int s , int num){








}


