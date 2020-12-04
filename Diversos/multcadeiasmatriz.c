#include<stdio.h>


int main(){

int n,i,j;
scanf("%d", &n);
int mat[n][2];

for(i=0; i<n; i++)
    for(j=0; j<2; j++)
    printf("%d", &mat[i][j]);

for(i=0; i<n; i++)
    for(j=0; j<2; j++)
    printf("%d", mat[i][j]);




}
