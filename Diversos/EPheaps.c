#include<stdio.h>
#include<stdlib.h>

void maxheapify(int f, int m, int v[]);
void constroiHeap(int m, int v[]);
void heapsort(int m, int v[]);



int main(){

int m, i;
scanf("%d", &m);
int v[m];
for(i=1; i<=m; i++)
    scanf("%d", &v[i]);

heapsort(m, v);

for(i=1; i<=m; i++)
    printf("%d ", v[i]);


}


void maxheapify(int f, int m, int v[]){
int maior=f, e=2*f, d=(2*f)+1, aux;

if(e<=m && v[e] > v[maior])
    maior=e;

if(d<=m && v[d] >v [maior])
    maior=d;


if(maior != f){
   aux=v[f];
   v[f]=v[maior];
   v[maior]=aux;
   maxheapify(maior, m, v);
}


}

void constroiHeap(int m, int v[]){
int f;
for(f=m; f>=1; f--)
maxheapify(f,m,v);


}

void heapsort(int m, int v[]){
constroiHeap(m,v);
int aux;
while(m>=1){
    aux=v[1];
    v[1]=v[m];
    v[m]=aux;
    m--;
    maxheapify(1,m,v);
}








}

