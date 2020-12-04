#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
int chave, ocorr;

}node;

int hash(int ch, int M);


int main(){
int M=97, ch, i,c,h;

node *tb=(node*)malloc(98* sizeof(node));
for(i=0; i<=M ; i++){
     tb[i].chave= -1;
}

while(1){
    scanf("%d", &ch);
    if(ch == -1)
        break;
    h= hash(ch, M);
    for(i=0; i<=M ; i++){
        c=tb[h].chave;
        if((c == -1)||(c==ch))
            break;

        h=(h+1) %M;
    }

    if(i > M)
        exit(1);
    else{
        tb[h].chave=ch;
        tb[h].ocorr++;
    }


}

for(i=0; i<=M; i++)
    printf("%d", tb[i].chave);


}


int hash(int ch, int M){
int h;

h= ch % M;
return h;

}

