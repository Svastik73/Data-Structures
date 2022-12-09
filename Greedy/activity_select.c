#include<stdio.h>
#include<stdlib.h>

typedef struct activity{
    int start;
    int end;
}activity;
void ssort(activity arr[],int n){
    for(int i=0;i<n-1;i++){
        int maz=arr[i].end;
        for(int j=i+1;j<n;j++){
            if(arr[j].end<maz) maz=arr[j].end;
        }

    int t1=arr[i].start; int t2=arr[i].end;
    arr[i].start=arr[maz].start; arr[i].end=arr[maz].end;
    arr[maz].start=t1; arr[maz].end=t2;
    }
}
int activity_select(activity arr[],int n){
       ssort(arr,n); int count=1;
      int max=arr[0].end;
       printf("Activity 1 selected and time of end is %d: ",arr[0].end);
     for(int i=1;i<n;i++){
        if(arr[i].start>=max){
            printf("\nActivity %d selected and time of end is %d: ",i+1,arr[i].end);
            max=arr[i].end;
            count++;
        }
     }
     return count;
}
int main(){
    int n;
    printf("Enter the number of events: ");
    scanf("%d",&n);
    activity arr[n];
    printf("\nEnter the details of activity\n ");
    for(int i=0;i<n;i++){ printf("\nenter start:");  scanf("%d",&arr[i].start);
    printf("\nenter end: "); scanf("%d",&arr[i].end);

    }
        fflush(stdin);
    for(int i=0;i<n;i++){ printf("%d ",arr[i].start);
    printf("%d ",arr[i].end);

    }
    int t=activity_select(arr,n);
    printf("\n total events scheduled are : %d",t);

}
