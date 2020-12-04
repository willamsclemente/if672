#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
int v;
char nome[10];
struct Node *prox;
}node;

typedef struct Vet{
int n, peso;
struct Vet *next;
}vet;

void inserearesta(int pos, int p, node *grafo);
int dijkstra(int n , int busca, int destino, node *grafo);



int main(){
int s,n, i, cont,p, cont1,r, res;
char busca[10], destino[10],C;
scanf("%d", &s);
if(s <= 10){
for(i=0; i< s; i++){
    scanf("%d", &n);
    //if(n < 10000){

       node *grafo=(node*)malloc(n*sizeof(node));
       for(cont=0; cont < n; cont++){
        (grafo+cont)->v=cont+1;
        (grafo+cont)->prox=NULL;
        fflush(stdin);
        scanf("%10[^\n]", (grafo+cont)->nome);
        scanf("%d", &p);
        inserearesta(cont, p, grafo);
       }
       scanf("%d", &r);
       int bus[r], des[r];
       for(cont=0; cont<r; cont++){
        fflush(stdin);
        scanf("%10[^\n] %10[^\n]", busca, destino);

        for(cont1=0; cont1<n; cont1++){
           if(strcmp((grafo+cont1)->nome, busca)==0)
                bus[cont]=(grafo+cont1)->v;

           if(strcmp((grafo+cont1)->nome, destino)==0)
               des[cont]=(grafo+cont1)->v;
        }
       }
      scanf("%c", &C);

      for(cont=0; cont <r; cont++){
        res=dijkstra(n, bus[cont], des[cont], grafo);
        printf("%d\n", res);

      }






    //}










}

}




}


void inserearesta(int pos, int p, node *grafo){
int i, nr, custo;
for(i=0; i<p; i++){
   if((grafo+pos)->prox == NULL){
    scanf("%d %d", &nr, &custo);
    vet *novo=(vet*)malloc(sizeof(vet));
    novo->n=nr;
    novo->peso= custo;
    novo->next=NULL;
    (grafo+pos)->prox=novo;
   }else{

   scanf("%d %d", &nr, &custo);
   vet *tmp=(grafo+pos)->prox;

   while(tmp->next != NULL)
    tmp= tmp->next;

   vet *novo=(vet*)malloc(sizeof(vet));
   novo->n=nr;
   novo->peso=custo;
   novo->next=NULL;
   tmp->next=novo;



   }



}



}


int dijkstra(int n , int busca, int destino, node *grafo){
int d[n], res=0, menor=20001, pvet, i;
char vis[n];

for(i=1; i<=n; i++){
    d[i]=20001;
    vis[i]='n';
}
i= busca, d[i]=0;
while(1){
    vet *tmp=(grafo+(i-1))->prox;

    while(tmp != NULL){
        if(vis[tmp->n] == 'n'){
          if(d[tmp->n] > d[i] + tmp->peso){
              d[tmp->n]= d[i] + tmp->peso;

            if(menor >=d[tmp->n]){
             menor=d[tmp->n];
             pvet=tmp->n;
            }

          }

        }

       tmp=tmp->next;

    }

    if(menor == 20001){
        tmp=(grafo+(i-1))->prox;

        while(tmp != NULL){
            if(vis[tmp->n] == 'n'){
             d[tmp->n]= d[i] + tmp->peso;

             if(menor >=d[tmp->n]){
             menor=d[tmp->n];
             pvet=tmp->n;
            }
        }
        tmp=tmp->next;

    }
    }


    vis[i]='s';
    menor=20001;
    if(pvet == destino)
      break;
    else{
      i=pvet;
    }
}
res=d[destino];
return res;

}

