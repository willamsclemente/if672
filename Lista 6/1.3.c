#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int l[9];
int c[9];
int diagonalP[15];
int diagonalS[15];
int cont;

void busca(int i, int x, int y);


int main(){
 int x, y, i,c;
 memset(l,0,sizeof(l));
 memset(diagonalP,0,sizeof(diagonalP));
 memset(diagonalS,0,sizeof(diagonalS));
 cont = 0;
 scanf("%d", &c);
 for(i=0; i<c; i++){
 scanf("%d %d", &x, &y);
 printf("SOLN       COLUMN\n");
 printf(" #      1 2 3 4 5 6 7 8\n\n");
 busca(1, x, y);
 cont=0;
 if(i!= c-1)
    printf("\n");
}
 return 0;
}

void busca(int i, int x, int y){
 int j;

 if(i<=8){
  for(j=1;j<=8;j++){
   if(l[j]==0 && diagonalP[i+j-2]==0 && diagonalS[i-j+7]==0){
    c[i] = j;
    l[j]=i;
    diagonalP[i+j-2]=1;
    diagonalS[i-j+7]=1;
    busca(i+1, x, y);
    l[j]=0;
    c[i] = 0;
    diagonalP[i+j-2]=0;
    diagonalS[i-j+7]=0;
   }
  }
 }else{
  if(c[y]==x){
  cont++;
  if(cont <= 9)
  printf(" %d      ",cont);
  else
  printf("%d      ", cont);
  printf("%d",c[1]);
  for(j=2;j<=8;j++){
   printf(" %d",c[j]);
  }
  printf("\n");
  }
 }
}

