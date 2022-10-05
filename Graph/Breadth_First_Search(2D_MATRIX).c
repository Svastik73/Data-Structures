
/*
  node :  connected to                                                                
   0   :  1,3
   1   :  0
   2   :  0,1,3,4
   3   :  0,1,2,4
   4   :  2,3,5,6
   5   :  1,4
   6   :  0,2,4
*/
#include <stdio.h>
#include <stdlib.h>  //BFS USES QUEUE for implementation
struct queue{
  int size; int f; int r; int *arr;
};
int isEmpty(struct queue *q){
  if(q->r==q->f) return 1;
  else return 0;
}
int isFull(struct queue *q){
  if(q->r==q->size-1) return 1;
  else return 0;
}
void enqueue(struct queue *q,int val){
  if(isFull(q)) printf("QUEUE IS FULL");
  else {
    q->r++;
    q->arr[q->r]=val;

  }
}
int dequeue(struct queue * q){
  int a=-1; if(isEmpty(q)) printf("queue is empty!\n");
  else{
    q->f++;
    a=q->arr[q->f];
  }
  return a;
}

int main(){
   struct queue q;
   q.size=400;  q.f=q.r=0;
   q.arr=(int *)malloc(q.size*sizeof(int));
  int visit[7]={0,0,0,0,0,0,0};  //for visitation
  int arr[7][7]={
  {0,1,0,1,0,0,0},  
  {1,0,0,0,0,0,0},
  {1,1,0,1,1,0,0},
  {1,1,1,0,1,0,0},
  {0,0,1,1,0,1,1},
  {0,1,0,0,1,0,0},
  {1,0,1,0,1,0,0}};
int i=0;   //start BFS FROM HERE!!
printf("%d ",i); visit[i]=1;
enqueue(&q,i);// enqueue i for exploration!!
while(!isEmpty(&q)){

  int node=dequeue(&q);
  for(int j=0;j<7;j++){
    if(arr[node][j]==1 && visit[j]==0){  //if nodes are interconnected & not visitd yet!
           printf("%d ",j); 
           visit[j]=1;
           enqueue(&q,j);
    }
  }
}
}
