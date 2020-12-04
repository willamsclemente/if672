#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
int num;
struct Node *prox;

}node;

node *aloca();
void insereInicio(node * LISTA, int k);
void insereFim(node *LISTA, int k);
node *retiraInicio(node *LISTA);
node *retiraFim(node *LISTA);
void exibe(node *LISTA);






int main(){

int opt, k;
node *LISTA=(node*)malloc(sizeof(node));
if(!LISTA)
    exit(1);
LISTA->prox=NULL;

do{

	printf("Escolha a opcao\n");
	printf("0. Sair\n");
	printf("1. Exibir lista\n");
	printf("2. Adicionar node no inicio\n");
	printf("3. Adicionar node no final\n");
	printf("4. Retirar do inicio\n");
	printf("5. Retirar do fim\n");
	printf("Opcao: "); scanf("%d", &opt);

	switch(opt){
      node *tmp;

     case 0:
         printf("\nFim");
         break;

     case 1:
         exibe(LISTA);
         break;

     case 2:
        printf("\nDiga o novo elemento:");
        scanf("%d", &k);
        insereInicio(LISTA,k);
        break;

     case 3:
        printf("\nDiga o novo elemento:");
        scanf("%d", &k);
        insereFim(LISTA,k);
        break;


     case 4:
        tmp=retiraInicio(LISTA);
        printf("\n%d\n", tmp->num);
        break;

     case 5:
        tmp=retiraFim(LISTA);
        printf("\n%d\n", tmp->num);
        break;


     default:
        printf("Operacao inexistente");






	}

}while(opt);


return 0;


}

node *aloca(){
node *novo=(node*)malloc(sizeof(node));
if(!novo)
    exit(1);
return novo;

}


void insereInicio(node * LISTA, int k){

node *novo=aloca();
novo->num=k;
node *tmp=LISTA->prox;

LISTA->prox=novo;
novo->prox=tmp;

}


void insereFim(node *LISTA, int k){
node *novo=aloca();
novo->num=k;
novo->prox=NULL;
if(LISTA->prox ==NULL)
    LISTA->prox=novo;
else{
  node *tmp=LISTA->prox;

  while(tmp->prox != NULL)
    tmp=tmp->prox;

  tmp->prox=novo;

}

}

node *retiraInicio(node *LISTA){

if(LISTA->prox == NULL){
    printf("\nLista vazia");
    return NULL;
}
else{
node *tmp=LISTA->prox;
LISTA->prox=tmp->prox;
return tmp;
}


}

node *retiraFim(node *LISTA){

if(LISTA->prox == NULL){
    printf("\nLista vazia");
    return NULL;
}
else{
    node *tmp=LISTA->prox;
    node *anterior;

    while(tmp->prox != NULL){
        anterior=tmp;
        tmp=tmp->prox;
    }

    anterior->prox=NULL;
    return tmp;
}




}

void exibe(node *LISTA){
node *tmp=LISTA->prox;

while(tmp != NULL){
    printf("%d ", tmp->num);
    tmp=tmp->prox;
}

}

  for(j=0; j<n; j++){
     if(mesa[j] == meias[i]){
        aux=1;
        mesa[j]=0;
        cont--;
        break;
     }


  }

  if(aux==0){
    for(t=0; t<n; t++)
       if(mesa[t]==0){
         mesa[t]= meias[i];
         cont++;
         if(cont>max)
            max=cont;
         break;
       }
  }

  aux=0;
