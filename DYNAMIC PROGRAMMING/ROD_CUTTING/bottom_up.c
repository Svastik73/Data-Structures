#include<stdio.h>
int max(int a,int b){
  if(a>b) return a;
  else return b;
}
int memorize(int arr[],int n){
  int profit[n+1];
  profit[0]=0;
  int maxp;
  for(int i=1;i<=n;i++){
    maxp=-1;
    for(int j=0;j<i;j++){
      maxp=max(maxp,arr[j]+profit[i-j-1]);
      profit[i]=maxp;
    }
  }
  return maxp;
}
int main(){
  int n;
  printf("Enter the number of elements in which rod is to be cut : ");
  scanf("%d",&n);
  int arr[n];

  for(int i=0;i<n;i++) scanf("%d",&arr[i]);
  int res=memorize(arr,n);
  printf("Maximum profit generated is: %d ",res);
}
