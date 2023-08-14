#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int rmc(int p[],int i,int j){
   
     if (i==j){
        return 0;
     }

     int k;
     int min = INT_MAX;
     int count;

     for(k=i;k<j;k++){
        count =rmc(p,i,k)+ rmc(p,k+1,j)+p[i-1]*p[k]*p[j];

     
     if (count<min){
        min = count;
     }

     }
     return min;
}

int main(){
    
    int arr[] ={1,2,3,4,3};
    int N = sizeof(arr)/sizeof(arr[0]);

    printf("minimum cost is :  %d\n",rmc(arr,1,N-1));

    getchar();

    return 0;
}


