#include<stdio.h>
#include<stdlib.h>

void intercala1(int p, int q, int r, int v[]);
void intercala2(int p, int q, int r, int v[]);
void mergesort(int p, int r, int v[]);





int main(){
int  p=0, r, i;

printf("Diga o tamanho do vetor que sera ordenado:");
scanf("%d", &r);
int v[r];
for(i=0; i< r; i++)
    scanf("%d", &v[i]);

 mergesort(p,r,v);
 for(i=0; i<r; i++)
    printf("\n%d", v[i]);


}





void intercala1(int p, int q, int r, int v[]){
int i, j, k=0, *w;
w=malloc((r-p)*sizeof(int));
i=p, j=q;
while(i < q && j<r){
     if(v[i]<= v[j])
       w[k++]=v[i++];
     else
       w[k++] = v[j++];

}

    while(i<q)
        w[k++]=v[i++];

    while(j<r)
        w[k++]=v[j++];



    for(i=p; i<r; i++)
        v[i]=w[i-p];


}

void intercala2(int p, int q, int r, int v[]){
int i,j,k, *w;
w=malloc((r-p)*sizeof(int));
for(i=p; i<q; i++)
  w[i-p]=v[i];
for(j=q; j<r; j++)
    w[r-p+q-j-1]=v[j];

i=0, j=r-p-1;

for(k=p; k<r; k++)
    if(w[i]<=w[j])
    v[k]=w[i++];
    else
    v[k]=w[j--];

free(w);
}

void mergesort(int p, int r, int v[]){

if(p < r-1){
    int q= (p+r)/2;
    mergesort(p,q,v);
    mergesort(q,r,v);
    intercala1(p,q, r, v);
}




}

