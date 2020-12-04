#include<stdio.h>


void subsetsum(int p[],int n, int c);

int main(){

int c, n, i;
scanf("%d %d", &n, &c);

int p[n];
p[0]=0;
for(i=1; i<=n; i++){
    scanf("%d", &p[i]);

}


subsetsum(p,n,c);
}


void subsetsum(int p[],int n, int c){
int i, j, mat[n][c];

for(i=0; i<=n; i++){
  mat[i][0]=1;
}
for(j=1; j<=c; j++)
    mat[0][j]=0;


for(i=0; i<=n; i++)
    printf("%d", mat[i][0]);


for(i=1; i<=n; i++){
    for(j=1; j<=c; j++){
        if((mat[i-1][j] == 1)&&((i-1 )>=1)){
            mat[i][j]=1;
            printf("\n%d %d da linha acima", i,j);
        }
         else{
            if(p[i]==j){
               mat[i][j]=1;
               printf("\n%d %d quando e igual", i,j);
            }
            else{
                if((mat[i][(j-p[i])] ==1) && ((j-p[i]) >=1)){
                    mat[i][j]=1;
                   printf("\n%d %d quando e somado", i,j);
                }
                else
                    mat[i][j]=0;
            }
         }

    }
}

printf("\n");

for(i=0; i<=n; i++){
   for(j=0; j<=c; j++){
    printf("%d", mat[i][j]);
   }
   printf("\n");
}
}

