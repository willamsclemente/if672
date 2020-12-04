#include<stdio.h>
#include<string.h>

int imprimir(int i,int j, int m, char res[][m+1], char s2[m+1]);



int main(){


int n,m, i, j, resposta;

scanf("%d %d", &n, &m);
char s1[n+1], s2[m+1], res[n+1][m+1];
int tab[n+1][m+1];

for(i=1; i<=n; i++)
    scanf(" %c", &s1[i]);

for(j=1; j<=m; j++)
    scanf(" %c", &s2[j]);

for(i=0; i<=n; i++)
    tab[i][0]=0;

for(j=0; j<=m; j++)
    tab[0][j]=0;


 for(i=1; i<=n; i++){
    for(j=1; j<=m; j++){
        if(s1[i]==s2[j]){
            tab[i][j]=(tab[i-1][j-1]+1);
            res[i][j]='I';
        }
       else{
          if(tab[i-1][j] >= tab[i][j-1]){
            tab[i][j]=tab[i-1][j];
            res[i][j]='C';
          }
          else{
            tab[i][j]=tab[i][j-1];
            res[i][j]='L';
          }
       }

    }
 }



 for(i=0; i<=n; i++){
   for(j=0; j<=m; j++){
    printf("%d ", tab[i][j]);
   }
    printf("\n");
 }

 printf("\n%d\n\n", tab[n][m]);



 i=n, j=m;
 resposta=imprimir(i,j, m, res, s2);




return 0;

}


int imprimir(int i, int j, int m, char res[][m+1], char s2[m+1]){
    if((i == 0)||(j == 0)){
     return 3;
    }
    else{
        if(res[i][j] == 'I'){
            imprimir(i-1, j-1,m, res, s2);
             printf("%c ", s2[j]);
        }
        else{
            if(res[i][j] == 'C')
            imprimir(i-1, j,m, res, s2);
            else
              imprimir(i, j-1,m, res, s2);


        }
    }


}

