#include<stdio.h>
#include<math.h>

int cut_rod_memo(int arr[],int n,int mem[]){
  if( mem[n]>=0) return mem[n]; // if found in memory return this!
  if(n==0){  mem[0]=0; return 0;} // intiialise first mem[0]=0;
  int maxr=arr[n];
  for(int i=1;i<=n-1;i++){ // dont count for whole apiece as it is already considered in maxr=arr[n]!!
      int val=cut_rod_memo(arr,n-i,mem);
      if(maxr<val+arr[i]) maxr=arr[i]+val;
  }
  mem[n]=maxr; // update max value for each sub cases!!
  return maxr;
}
int main(){
  int n;
  printf("Enter the number of elements in which rod is to be cut : ");
  scanf("%d",&n);
  int arr[n+1];  //keep size =n+1 rfor easy access!!
  int r[n+1];
   for(int i=0;i<=n;i++){
  r[i]=-1;
 }
  for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
  int res=cut_rod_memo(arr,n,r);
  printf("Maximum profit generated is: %d ",res);
}
