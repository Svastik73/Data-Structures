#include<stdio.h>
#include<stdlib.h>
#define max 20
int m=4; // max colors are 4
int x[max];
void answer(int n){
       for(int i=1;i<=n;i++) printf("vertex %d has color %d",i,x[i]);
}
int place(int arr[][max],int k,int color){
    for(int i=1;i<k;i++){
        if(arr[k][i]!=0 && color==x[i]) return 0;
    }
    return 1;
}
void mcolor(int arr[][max],int k,int n){
    int color;
    for(color=1;color<=m;color++){
        if(place(arr,k,color)==1){
            x[k]=color;
            if(k==n){
                answer(n); exit(0);
            }
            else
            {
                mcolor(arr,k+1,n);
            }
        }
    }
}
int main(){
  int graph[max][max];
  int n; printf("Enter number of vetices: ");
  scanf("%d",&n);
  for(int i=0;i<=n;i++){
      for(int j=0;j<=n;j++){
          graph[i][j]=0;
      }
  }
  int inp;
  for(int i=1;i<=n;i++){  // start indexing from 1
      printf("enter adjacents of %d node",i);
      do{
          scanf("%d",&inp);
          graph[i][inp]=1;
      }
      while(inp>=0);
  }
  mcolor(graph  ,1,n);
}
