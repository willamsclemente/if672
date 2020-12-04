#include<stdio.h>
#include<stdlib.h>

int separa(int v[], int p, int r);
quicksort(int v[], int p, int r);



int main(){
int p=0, r, i;

scanf("%d", &r);
int v[r];
for(i=0; i<r; i++)
    scanf("%d", &v[i]);




quicksort(v,p,r-1);
for(i=0; i<r; i++)
    printf("\n%d", v[i]);

}

int separa(int v[], int p, int r){
int i=p+1, c=v[p], j=r, t;

while(i<=j){
    if(v[i]<= c)
        i++;
    else
        if(c < v[j])
        j--;
        else{
          t=v[i],v[i]=v[j],v[j]=t;
          i++, j--;
        }


}
v[p]=v[j], v[j]=c;
return j;

}

quicksort(int v[], int p, int r){
int j;
while(p < r){
    j=separa(v,p,r);
    if(j-r < r-j){
    quicksort(v,p, j-1);
    p=j+1;
    }
    else{
        quicksort(v, j+1, r);
        r=j-1;
    }

}




}
