#include<stdio.h>
#include<stdlib.h>


typedef struct Node{
int v;
struct Node *prox;
}node;

void inserearesta(int u, int w, node *grafo);
int dfs(node *grafo, int N);
int dfsvisit(char cor[], int pai[], int i, node *grafo);




int main(){
 char C, cont=0;
int N, M,i, u,w;
while(scanf("%d"  ,&N)==1){
        scanf("%d", &M);
cont++;
if ((cont>=1)&&(cont<=100)){
    node *grafo=(node*)malloc(N*sizeof(node));


    //if((2 <= N)&&(N<= 200)&&(0 <= M)&&(M <= N*(N-1)/2)){

        for(i=0; i<N; i++){
        (grafo+i)->v=i;
        (grafo+i)->prox=NULL;
        }



        for(i=0; i<M; i++){
        scanf("%d %d", &u, &w);
        inserearesta(u,w,grafo);
        }
        scanf("%c", &C);

        int res=0;
        res=dfs(grafo, N);
        if(res == 1)
            printf("%d 1\n", cont);
        else
            printf("%d 0\n", cont);
    //}

}
else
   break;
}
return 0;
}


void inserearesta(int u, int w, node *grafo){

   if((grafo+u)->prox == NULL){

    node *novo=(node*)malloc(sizeof(node));
    novo->v=w;
    novo->prox=NULL;
    (grafo+u)->prox=novo;
   }else{

   node *tmp=(grafo+u)->prox;
   while(tmp->prox != NULL)
   tmp=tmp->prox;


   node *novo=(node*)malloc(sizeof(node));
   novo->v=w;
   novo->prox=NULL;
   tmp->prox=novo;

   }


   if((grafo+w)->prox == NULL){

    node *novo=(node*)malloc(sizeof(node));
    novo->v=u;
    novo->prox=NULL;
    (grafo+w)->prox=novo;

   }else{

   node *tmp=(grafo+w)->prox;

   while(tmp->prox != NULL)
   tmp=tmp->prox;

   node *novo=(node*)malloc(sizeof(node));
   novo->v=u;
   novo->prox=NULL;
   tmp->prox=novo;

   }


}

int dfs(node *grafo, int N){
int res;
int pai[N],i;
char cor[N];
for(i=0; i<N; i++){
    pai[i]=-1;
    cor[i]='B';
}

for(i=0; i<N; i++){
    if(cor[i] == 'B')
        res=dfsvisit(cor, pai, i, grafo);
        if(res == 1)
            return 1;
}
return 0;
}

int dfsvisit(char cor[], int pai[], int i, node *grafo){
cor[i]='C';

node *tmp=(grafo+i);
while(tmp != NULL){
    if(cor[tmp->v] == 'B'){
        pai[tmp->v]=(grafo+i)->v;
        dfsvisit(cor, pai, tmp->v, grafo);
    }
    else{
        if((pai[(grafo+i)->v] != tmp->v )&& (tmp->v != (grafo+i)->v)){
         return 1;
        }
    }
    tmp=tmp->prox;
}

cor[i]='P';



}
