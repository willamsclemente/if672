#include<stdio.h>
#include<stdlib.h>


typedef struct Node{
int chave, ocorr;
struct Node *prox;
}node;

int hash(int ch, int M);


int main(){
 int ch, M=97,i,h;
  node **tb;
  node *p;
   tb=(node**)malloc(M* sizeof(node*));
   for(i=0; i<=M; i++)
    tb[i]=NULL;
while(1){
   scanf("%d", &ch);
   if(ch == -1)
        break;

   h= hash(ch,M);
   p=tb[h];
   while((p != NULL) && (p->chave != ch)){
       p=p->prox;
   }
   if(p != NULL){
      p->ocorr += 1;
      printf("%d", p->ocorr);
   }
   else{
     p= (node*)malloc(sizeof(node));
     p->chave=ch;
     p->ocorr = 1;
     p->prox=tb[h];
     tb[h]=p;
     printf("%d", p->chave);
   }

}
}

int hash(int ch, int M){
int h;
  h= ch % M;
  return h;
}


