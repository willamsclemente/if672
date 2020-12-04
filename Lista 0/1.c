#include<stdio.h>


int main(){
int n,i;
scanf("%d", &n);
int mat[n], mat1[n];

for(i=0; i<n; i++)
scanf("%d", &mat[i]);

for(i=0; i<n; i++)
scanf("%d", &mat1[i]);

for(i=0; i<n; i++){
    printf("%d\n", mat[i]);
    printf("%d\n", mat1[i]);
}

return 0;
}
