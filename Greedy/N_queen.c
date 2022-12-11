#include<stdio.h>
#include<stdlib.h>
int x[50];  // x[i] will store column no. of queen number i!
int place(int k,int xk){  
    int j;
    for(j=1;j<=k;j++){
        if(x[j]==xk || abs(x[j]-xk)==abs(j-k)){
            return 0;
            //  xk is position not acceptable for queen!
        }
    }
    return 1;
}
void display(int n){
    int i;
    for(i=1;i<=n;i++){
        printf("\nPosition of %d queen is:%d ",i,x[i]);
    }
}
void Nqueen(int k,int n){  // k is row
    int column;  // k is the number of queen entered !
    for(column=1; column<=n; column++){   // this ensure automatic backtrack!!
        if(place(k,column)==1){   // back tracking is done using recursion() inside a  loop!
            x[k]=column;
            if(k==n){  // means last queen so no more recursion
                display(n);
                exit(0); // if exit(0) is not placed it will print all the solutions!
            }
            else Nqueen(k+1,n);
        }
    }
}
int main(){
  int n; printf("Enter value of sides in chessboard: \n"); scanf("%d",&n);
  Nqueen(1,n);  // pass k==1 here to start from entering 1 queen only!
}
