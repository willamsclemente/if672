#include<stdio.h>
#include<stdlib.h>


typedef struct Node{
int num;
struct Node *prox;
}node;

void insereInicio(node *LISTA, int n);
void exibe(node *LISTA);

int main(){
int n;
node *LISTA= (node*)malloc(sizeof(node));
LISTA->prox=NULL;
if(!LISTA){
    exit(1);
}else{
    while(scanf("%d", &n)==1)
        insereInicio(LISTA,n);

    exibe(LISTA);


}
 free(LISTA);
 return 0;


}

void insereInicio(node *LISTA, int n){
node *novo=(node*)malloc(sizeof(node));
if(!novo){
    exit(1);
}
node *oldHead= LISTA->prox;
LISTA->prox= novo;
novo->prox= oldHead;

novo->num= n;


}

void exibe(node *LISTA){
node *tmp;
tmp= LISTA->prox;

while(tmp != NULL){
    printf("%d ", tmp->num);
    tmp= tmp->prox;
}

}
