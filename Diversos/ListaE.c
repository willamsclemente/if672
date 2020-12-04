#include <stdio.h>
#include <stdlib.h>

struct Node{
	int num;
	struct Node *prox;
};
typedef struct Node node;

void inicia(node *LISTA);
int menu(void);
void opcao(node *LISTA, int op);
node *criaNo();
void insereFim(node *LISTA);
void insereInicio(node *LISTA);
void exibe(node *LISTA);
void libera(node *LISTA);
node *retiraInicio(node *LISTA);
node *retiraFim(node *LISTA);

int main(void)
{
	node *LISTA = (node *) malloc(sizeof(node));
	if(!LISTA){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
	inicia(LISTA);
	int opt;

	do{
		opt=menu();
		opcao(LISTA,opt);
	}while(opt);

	free(LISTA);
	return 0;
}

void inicia(node *LISTA)
{
	LISTA->prox = NULL;
}

int menu(void)
{
	int opt;

	printf("Escolha a opcao\n");
	printf("0. Sair\n");
	printf("1. Exibir lista\n");
	printf("2. Adicionar node no inicio\n");
	printf("3. Adicionar node no final\n");
	printf("4. Zerar lista\n");
	printf("5. Retirar do inicio\n");
	printf("6. Retirar do fim\n");
	printf("Opcao: "); scanf("%d", &opt);

	return opt;
}

void opcao(node *LISTA, int op)
{
    node *tmp;
	switch(op){
		case 0:
			libera(LISTA);
			break;

		case 1:
			exibe(LISTA);
			break;

		case 2:
			insereInicio(LISTA);
			break;

		case 3:
			insereFim(LISTA);
			break;

		case 4:
			inicia(LISTA);
			break;

		case 5:
            tmp= retiraInicio(LISTA);
            printf("Retirado: %3d\n\n", tmp->num);
            break;

        case 6:
            tmp= retiraFim(LISTA);
            printf("Retirado: %3d\n\n", tmp->num);
            break;

		default:
			printf("Comando invalido\n\n");
	}
}

int vazia(node *LISTA)
{
	if(LISTA->prox == NULL)
		return 1;
	else
		return 0;
}


void insereFim(node *LISTA)
{
	node *novo=(node *) malloc(sizeof(node));
	if(!novo){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
	printf("Novo elemento: "); scanf("%d", &novo->num);
	novo->prox = NULL;

	if(vazia(LISTA))
		LISTA->prox=novo;
	else{
		node *tmp = LISTA->prox;

		while(tmp->prox != NULL)
			tmp = tmp->prox;

		tmp->prox = novo;
	}
}

void insereInicio(node *LISTA)
{
	node *novo=(node *) malloc(sizeof(node));
	if(!novo){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
	printf("Novo elemento: "); scanf("%d", &novo->num);

	node *oldHead = LISTA->prox;

	LISTA->prox = novo;
	novo->prox = oldHead;
}

void exibe(node *LISTA)
{
	if(vazia(LISTA)){
		printf("Lista vazia!\n\n");
		return ;
	}

	node *tmp;
	tmp = LISTA->prox;

	while( tmp != NULL){
		printf("%5d", tmp->num);
		tmp = tmp->prox;
	}
	printf("\n\n");
}

void libera(node *LISTA)
{
	if(!vazia(LISTA)){
		node *proxNode,
			  *atual;

		atual = LISTA->prox;
		while(atual != NULL){
			proxNode = atual->prox;
			free(atual);
			atual = proxNode;
		}
	}
}

node *retiraInicio(node *LISTA){

if(LISTA->prox == NULL){
    printf("Lista vazia\n");
    return NULL;
}else{

node *tmp= LISTA->prox;
LISTA->prox= tmp->prox;
return tmp;


}


}

node *retiraFim(node *LISTA){

if(LISTA->prox == NULL){
    printf("Lista ja vazia\n\n");

}else{
node *ultimo = LISTA->prox, *penultimo= LISTA;

while(ultimo->prox == NULL){
    penultimo = ultimo;
    ultimo= ultimo->prox;
}

penultimo->prox = NULL;
return ultimo;



}



}
