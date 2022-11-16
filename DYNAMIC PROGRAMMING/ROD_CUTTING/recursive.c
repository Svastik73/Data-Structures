#include<stdio.h>
#include<math.h>
int cut_rod_recurse(int arr[],int n){
  int maxr;
  if(n==0) return 0;
  maxr=arr[n];
  for(int i=1;i<=n-1;i++){ // dont count for whole apiece as it is already considered in maxr=arr[n]!!
      int val=cut_rod_recurse(arr,n-i);
      if(maxr<val+arr[i]) maxr=arr[i]+val;
  }
  return maxr;
}
int main(){
  int n;
  printf("Enter the number of elements in which rod is to be cut : ");
  scanf("%d",&n);
  int arr[n+1];  //keep size =n+1 rfor easy access!!

  for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
  int res=cut_rod_recurse(arr,n);
  printf("Maximum profit generated is: %d ",res);
}
