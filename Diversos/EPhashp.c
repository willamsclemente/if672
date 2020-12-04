#include<stdio.h>
#include<stdlib.h>


typedef struct Node{
int chave, ocorr;
}node;


int main(){
int ch, M=97, i,c, h;

node *tb=(M *sizeof(97*sizeof(node)))
for(i=0; i<=M; i++)
tb[i].chave=-1;

while(1){
    scanf("%d", &ch);

    h=hash(ch, M)

    for(i=0, i<=M; i++){
        c=tb[h].chave;
        if((c==-1) || (c==ch))
         break;

        h=(h+1)%M;
    }

    tb[h].chave=ch;
    tb[h].chave++

}


}

int hash(int ch, int M){

int h= ch%M;
return j;
}
