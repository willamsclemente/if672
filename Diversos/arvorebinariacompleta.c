#include<stdio.h>
#include<stdlib.h>

typedef struct arvore{
int key;
struct arvore *dir;
struct arvore *esq;

}node;

node *aloca();
void exibirO(node *nodeR);
void exibirPR(node *nodeR);
void exibirPS(node *nodeR);
void inserir(node *nodeR, int k);
void maximo(node *nodeR);
void minimo(node *nodeR);
node *retirar(node *nodeR, int k);





node *root;

int main(){
    int k;

int opt;
	do{
	printf("Escolha a opcao\n");
	printf("0. Sair\n");
	printf("1. Exibir ORDEM\n");
	printf("2. Exibir PRE ORDEM\n");
	printf("3. Exibir POS ORDEM\n");
	printf("4. inserir\n");
	printf("5. buscar e Retirar\n");
	printf("6. maximo\n");
	printf("7. minimo\n");
	printf("Opcao: "); scanf("%d", &opt);
	system("cls || clear");


	switch(opt){


     case 0:
         printf("\nFIM");
         break;

     case 1:
         exibirO(root);
         break;

     case 2:
         exibirPR(root);
         break;

     case 3:
         exibirPS(root);
         break;

     case 4:
         printf("\nDigite o dado:\n");
         scanf("%d", &k);
         inserir(root,k);
         break;

     case 5:
         printf("\nDigite o dado a ser retirado\n");
         scanf("%d", &k);
         node *tmp=retirar(root,k);
         printf("\n%d\n", tmp->key);
         break;

     case 6:
         maximo(root);
         break;

     case 7:
         minimo(root);
         break;

     default:
        printf("\nOperação inexistente\n");

	}



	}while(opt);


}

node *aloca(){
node *novo=(node*)malloc(sizeof(node));
if(!novo){
    exit(1);
}
return novo;
}

void inserir(node *nodeR, int k){
node *novo= nodeR;

if(nodeR == NULL){
    nodeR=aloca();
    nodeR->key=k;
    nodeR->dir=NULL;
    nodeR->esq=NULL;
    root=nodeR;
}
else{
    node *anterior;
    while(novo != NULL){
            anterior= novo;

          if(k>= novo->key)
          novo= novo->dir;

          else
            novo=novo->esq;

    }
    novo=aloca();
    novo->esq=NULL;
    novo->dir=NULL;
    novo->key=k;

    if(k >= anterior->key)
        anterior->dir=novo;
    else{
        anterior->esq=novo;
    }

}


}


void exibirO(node *nodeR){
if(nodeR != NULL){
   exibirO(nodeR->esq);
   printf("%d ", nodeR->key);
   exibirO(nodeR->dir);

}


}

void exibirPR(node *nodeR){
if(nodeR != NULL){
   printf("%d ", nodeR->key);
   exibirPR(nodeR->esq);
   exibirPR(nodeR->dir);

}


}

void exibirPS(node *nodeR){
if(nodeR != NULL){
   exibirPS(nodeR->esq);
   exibirPS(nodeR->dir);
   printf("%d ", nodeR->key);


}


}

void maximo(node *nodeR){
if(nodeR == NULL){
    printf("\n%d\n", nodeR->key);
}
else{
   maximo(nodeR->dir);

}



}

void minimo(node *nodeR){
if(nodeR->esq == NULL){
    printf("\n%d\n", nodeR->key);
}
else{
   minimo(nodeR->esq);
}


}

node *retirar(node *nodeR, int k){
node *tmp= nodeR;
node *anterior;
while(tmp->key != k){
     anterior=tmp;

     if(k > tmp->key)
        tmp=tmp->dir;
     else
        tmp=tmp->esq;

}

if((tmp->esq==NULL) && (tmp->dir==NULL)){
    if(k> anterior->key){
        anterior->dir=NULL;
        return tmp;
        }
    else{
       anterior->esq=NULL;
        return tmp;
    }
}else{
    if((tmp->esq==NULL) || (tmp->dir==NULL)){
        if(k > anterior->key){
            if(tmp->esq != NULL){
               anterior->dir=tmp->esq;
               return tmp;
            }
            else{
                anterior->dir=tmp->dir;
                return tmp;
            }

        }
        else{
            if(tmp->esq != NULL){
                anterior->esq=tmp->esq;
                return tmp;
            }
            else{
                anterior->esq=tmp->dir;
                return tmp;
            }

        }
    }else{

    node *aux=tmp->dir;
    node *previous;
    while(aux->esq != NULL){
        previous=aux;
        aux= aux->esq;

    }

    if(aux->key > previous->key)
        previous->dir=aux->dir;
    else
        previous->esq=aux->dir;

    if(k > anterior->key){
        anterior->dir=aux;
        aux->dir=tmp->dir;
        aux->esq=tmp->esq;
        return tmp;
    }else{

        anterior->esq=aux;
        aux->dir=tmp->dir;
        aux->esq=tmp->esq;
        return tmp;


    }





    }




}





}


