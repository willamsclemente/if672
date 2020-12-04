#include<stdio.h>
#include<stdlib.h>

int queen(int x, int i, int mat[][9]);
int ataca(int i, int j , int mat[][9]);


int main(){
int mat[9][9], i,j,x,y;

for(i=1; i<9; i++)
  for(j=1; j<9; j++)
    mat[i][j]=0;


scanf("%d %d", &x, &y);

mat[x][y]=1;


if(queen(x, 1, mat)){

for(i=1; i<9; i++){
    for(j=1; j<9; j++){
        printf("%d", mat[i][j]);
    }
     printf("\n");
}


}


}


int queen(int x, int i, int mat[][9]){
int j, p,q;
char url[]="notas.txt";
FILE *arq=fopen(url, "a");
if(i == x){
    i++;
    queen(x,i,mat);
}
for(j=1; j<9; j++){
      if(ataca(i, j, mat)){
        mat[i][j]=1;
        i++;
        fprintf(arq,"\n");
        for(p=1; p<9; p++){
          for(q=1; q<9; q++){
          fprintf(arq,"%d", mat[p][q]);
          }
         fprintf(arq,"\n");
        }
        fprintf(arq,"\n");

        if(i== 9)
           exit(1);

        if(!queen(x, i,mat)){
            i--;
            mat[i][j]=0;
            fprintf(arq, "\nentrando no queen");
            fprintf(arq,"\n");
            for(p=1; p<9; p++){
               for(q=1; q<9; q++){
               fprintf(arq,"%d", mat[p][q]);
               }
              fprintf(arq,"\n");
            }
            fprintf(arq,"\n");

        }
        return 1;


      }


}
fprintf(arq,"\nretornando 0");
return 0;








}

int ataca(int i, int j , int mat[][9]){
int p, q;
  for(p=1; p<9; p++)
      if(mat[p][j] == 1)
         return 0;

  for(q=1; q<9; q++)
        if(mat[i][q]== 1)
          return 0;


  for(p=i, q=j; p<9 && q<9; p++, q++)
        if(mat[p][q]== 1)
          return 0;


  for(p=i, q=j; p>=1 && q>=1 ; p--, q--)
        if(mat[p][q] == 1)
            return 0;

  for(p=i, q=j; p<9 && q>=1; p++, q--)
       if(mat[p][q]== 1)
         return 0;


   for(p=i, q=j; p>=1 && q<9; p--, q++)
        if(mat[p][q]== 1)
           return 0;


   return 1;

}
