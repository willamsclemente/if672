#include<stdio.h>
#include<stdlib.h>

void quicksort(int v[], int p, int r);
int separa(int v[], int p, int r);


int main(){
int n,i;
scanf("%d", &n);
int v[n];

for(i=0; i<n ;i++)
    scanf("%d", &v[i]);

quicksort(v,0,n-1);

for(i=0; i<n ;i++)
    printf("%d ", v[i]);

    return 0;

}

int separa(int v[],int p, int r){
int c=v[p], i=p+1, j=r, t;
while(i<=j){
    if(v[i] <= c)
        i++;
    else
        if(c < v[j])
        j--;
        else{
          t=v[i], v[i]=v[j], v[j]=t;
        }

}
v[p]=v[j], v[j]=c;
return j;
}

void quicksort(int v[], int p, int r){
int j;
while(p<r){
    j=separa(v,p,r);
    if(j-p < r -j){
        quicksort(v, p, j-1);
        p=j+1;
    }
    else{
        quicksort(v, j+1, r);
        r=j-1;
    }

}



}
