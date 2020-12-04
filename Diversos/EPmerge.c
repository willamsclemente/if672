#include<stdio.h>
#include<stdlib.h>


int main(){
int n, i;
scanf("%d", &n);
int v[n];

for(i=0; i<n; i++)
    scanf("%d", &v[i]);

 mergesort(0, n, v) ;
 for(i=0; i<n; i++)
    printf("%d ", v[i]);




}

void intercala(int p, int q, int r, int v[]){
int i, j, k=0, *w;
w=malloc((r-p)*sizeof(int));
i=p, j=q;
while(i<q && j<r){
    if(v[i]<= v[j])
        w[k++]=v[i++];
    else
        w[k++]=v[j++];
}

while(i < q)
    w[k++]=v[i++];
while(j < r)
    w[k++]=v[j++];


for(i=p; i<r; i++)
  v[i]=w[i-p];
}

void mergesort(int p, int r, int v[]){
int q;
if(p <r-1){
    q=(p+r)/2;
    mergesort(p, q, v);
    mergesort(q, r, v);
    intercala(p,q,r,v);
}



}

