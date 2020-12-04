#include<stdio.h>
#include<stdlib.h>

int separa(int v[], int p, int r);
void quicksort(int v[], int p, int r);


int main(){
int i, N, D,cont=-1, aux;
scanf("%d %d", &N, &D);
int v[N];
if((5 <= N)&& (N<= 1000)&&(0 <= D)&&(D <= 9)){
    for(i=0; i<N; i++){
       scanf("%d", &aux);
       if((aux%10)==D){
            cont++;
            v[cont]=aux;
       }
    }

    if(cont < 4){
       for(i=cont+1; i<=4; i++){
       v[i]=-1;
       cont++;
       }
    }


    quicksort(v,0,cont);
    printf("%d", v[cont-4]);
    printf("\n%d", v[cont-3]);
    printf("\n%d", v[cont-2]);
    printf("\n%d", v[cont-1]);
    printf("\n%d", v[cont]);




}




}

int separa(int v[], int p, int r){
int c=v[p], i=p+1, j=r,t;

while(i<=j){
   if(v[i]<= c)
        i++;
   else
      if(c < v[j])
      j--;
      else{
        t=v[i], v[i]=v[j], v[j]=t;
        i++, j--;
      }

}
v[p]=v[j], v[j]=c;
return j;
}

void quicksort(int v[], int p, int r){
int j;
while(p < r){
    j=separa(v,p,r);
    if(j-p < r-j){
        quicksort(v,p,j-1);
        p=j+1;
    }
    else{
        quicksort(v, j+1,r);
        r=j-1;
    }

}




}
