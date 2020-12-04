#include<stdio.h>


int main(){

int k, mat[4][4], i,j;
while(1){
scanf("%d", &k);
if(k == 0)
 break;
for(j=0; j<4; j++)
    for(i=0; i<4; i++)
    scanf("%d", &mat[i][j]);

for(i=0; i<4; i++){
    for(j=0; j<4; j++){
        if(i == j)
            printf("%d ", mat[i][j]*k);
        else
            printf("%d ", mat[i][j]);


    }
    printf("\n");


}

}
   return 0;

}

