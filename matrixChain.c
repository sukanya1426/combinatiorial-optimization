#include<stdio.h>
#include<limits.h>
int s[100][100];
int m[100][100];

int matrixChain(int p[],int n){

     int j,k,cost;
     

     for(int i=0;i<=n;i++){
        m[i][i]=0;
     }

     for(int l=2;l<=n;l++){
        for(int i=1;i<=(n-l+1);i++){
             j=i+l-1;
             m[i][j]=INT_MAX;
             for(k=i;k<j;k++){
                cost = m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(cost< m[i][j]){
                     m[i][j]= cost;
                     s[i][j]=k;
                }
             }
        }
     }

    return cost;
}
void printMatrix(int i,int j)
{
    if(i==j){
        printf("A%d",i);
    }else {
        printf("(");
        printMatrix(i,s[i][j]);
        printMatrix(s[i][j]+1,j);
        printf(")");
}
}


int main(){
     int num,cost;
     printf("enter the number of matrix : ");
     scanf("%d",&num);

     int dimantion[num+1];
     printf("enter the dimentions : ");
     for(int i=0;i<=num;i++){
        scanf("%d",&dimantion[i]);
     }
    matrixChain(dimantion,num);
    printMatrix(1,num);
    printf("cost = %d",m[1][num]);
    return 0;

}