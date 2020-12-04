#include <stdio.h>
#include <stdlib.h>

struct Node{
	int num;
	struct Node *prox;
};
typedef struct Node node;

void insereFim(node *LISTA);
void busca(node *LISTAA, int tamA, node *LISTAB, int tamB);


int main(void)
{
    int i,tamA, tamB;
	node *LISTAA = (node *) malloc(sizeof(node));
	if(!LISTAA){
		exit(1);
	}
	LISTAA->prox=NULL;
	node *LISTAB=(node *)malloc(sizeof(node));
	if(!LISTAB){
        exit(1);
	}
	LISTAB->prox=NULL;

	scanf("%d", &tamA);
    for(i=0; i<tamA; i++)
    insereFim(LISTAA);

    scanf("%d", &tamB);
    for(i=0; i<tamB; i++)
    insereFim(LISTAB);

    busca(LISTAA, tamA, LISTAB, tamB);


	free(LISTAA);
	free(LISTAB);
	return 0;
}


void insereFim(node *LISTA)
{
	node *novo=(node *) malloc(sizeof(node));
	if(!novo){
		exit(1);
	}
    scanf("%d", &novo->num);
	novo->prox = NULL;

	if(LISTA->prox == NULL)
		LISTA->prox=novo;
	else{
		node *tmp = LISTA->prox;

		while(tmp->prox != NULL)
			tmp = tmp->prox;

		tmp->prox = novo;
	}
}

void busca(node *LISTAA, int tamA, node *LISTAB, int tamB)
{
    int i,j, C=0;
	node *tmpA;
	tmpA = LISTAA->prox;

	node *tmpB;
	tmpB= LISTAB->prox;

	for(i=0; i<tamB; i++){
       for(j=0; j<tamA; j++){
          if((tmpB->num)==(tmpA->num)){
             C++;
             break;
          }
            tmpA = tmpA->prox;
       }
       	tmpA = LISTAA->prox;
        tmpB = tmpB->prox;
	}

	if(C==tamB)
        printf("1");
    else
        printf("0");

}


