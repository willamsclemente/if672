#include<stdio.h>


int main(){
int n, c, i, j;

scanf("%d %d", &n, &c);

int v[(n+1)], p[(n+1)], tab[(n+1)][(c+1)];

for(i=1; i<=n; i++)
    scanf("%d %d", &p[i], &v[i]);

for(i=0; i<=c; i++)
    tab[0][i]=0;

for(j=0; j<=n; j++)
    tab[j][0]=0;


for(i=1; i<=n; i++){
    for(j=1; j<=c; j++){
        if(p[i] <= j){
            if((v[i] + tab[i-1][(j - p[i])]) > (tab[i-1][j])){
            tab[i][j]=(v[i]+tab[i-1][(j-p[i])]);
            }
            else
                tab[i][j]=tab[i-1][j];

        }
         else{
            tab[i][j]=tab[i-1][j];
         }
    }
}

    printf("\n");

for(i=0; i<=n; i++){
    for(j=0; j<=c; j++){
        printf("%d  ", tab[i][j]);
    }
    printf("\n");
}

printf("\n%d", tab[n][c]);


}
