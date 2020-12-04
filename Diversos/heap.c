#include<stdio.h>

void buildHeap(int v[]);
void maxheapify(int i, int v[]);
void heapsort(int v[]);




int m;
int main(){

 scanf("%d", &m) ;
int n=m;
int v[m],i;




for(i=1; i<=m; i++)
scanf("%d", &v[i]);
heapsort(v);
printf("\n");
for(i=1; i<=n; i++)
    printf("%d ", v[i]);


}

/*void buildHeap(int v[]){
int i,aux;
for(i=1; i<m; i++){
  int f=i+1;
  while(f > 1 && v[f/2] <v[f]){
      aux=v[f/2];
      v[f/2]=v[f];
      v[f]=aux;
      f/=2;
  }


}



}*/




void maxheapify(int i, int v[]){
int maior=i, l= 2*i, r=(2*i)+1, aux;

if(l<= m && v[l]> v[maior])
    maior=l;

 if(r<=m && v[r] > v[maior])
        maior=r;

 if(i != maior){
    aux=v[i];
    v[i]=v[maior];
    v[maior]=aux;
    maxheapify(maior, v);
 }

}

buildHeap(int v[]){
int i;
for(i=m; i>=1; i--)
    maxheapify(i, v);

}



void heapsort(int v[]){
 int aux,i;
buildHeap(v);

while(m >= 1){
    aux=v[1];
    v[1]=v[m];
    v[m]=aux;
    m--;
    maxheapify(1,v);


}

}


