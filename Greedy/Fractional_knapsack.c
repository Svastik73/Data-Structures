#include<stdio.h>
#include<stdlib.h>
typedef struct item{
    int wt;
    int profit;
    float ratio;
}item;
float frac_knapsack(item arr[],int n,int tot_wt){
     int max;
     for(int i=0;i<n-1;i++){
         max=i;
         for(int j=i+1;j<n;j++){
             if(arr[j].ratio>arr[max].ratio) max=j;
         }
         int t1=arr[i].wt; int t2=arr[i].profit; float t3=arr[i].ratio;
         arr[i].wt=arr[max].wt; arr[i].profit=arr[max].profit; arr[i].ratio=arr[max].ratio;
         arr[max].wt=t1; arr[max].profit=t2; arr[max].ratio=t3;
     }
     int i=0; int curr=0; float net=0;
     while(i<n && curr<tot_wt){
         if(curr+arr[i].wt<=tot_wt){
             net=net+(float)arr[i].profit;
             curr=curr+arr[i].wt;
             i++;
         }
         else
         {
             net=net+(float)arr[i].profit*((float)(tot_wt-curr)/arr[i].wt);
             curr=tot_wt;  // important to update here , else will become infinite loop!
         }
     }
     return net;
}
int main(){
    int n;
    printf("Enter the number of elements available: ");
    scanf("%d",&n);
    item arr[n];
    printf("\nEnter the details of items:\n ");
    for(int i=0;i<n;i++){   scanf("%d %d ",&arr[i].wt,&arr[i].profit);
      arr[i].ratio=(float)arr[i].profit/arr[i].wt;
    }
    fflush(stdin);
    printf("\nEnter the size of knapsack in kg's :");
    int tot; scanf("%d",&tot);
    int t=frac_knapsack(arr,n,tot);
    printf("\n Maximum profit is: %d",t);
}
