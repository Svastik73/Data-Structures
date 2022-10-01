#include<stdio.h>
int main(){          //graph using matrix
    int arr[6][6];
    for(int i=0;i<6 ; i++){
        int ans; 
       scanf("%d",&ans);      
       while(ans!=-1){
        
           scanf("%d",&ans);
        if(ans>=0)  arr[i][ans]=1;
       }
    }
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            if(arr[i][j]!=1) arr[i][j]=0;
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}
