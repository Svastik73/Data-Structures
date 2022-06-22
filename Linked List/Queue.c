#include<stdio.h>
#define MAX 10
struct queue{
  int arr[MAX];
  int fir,las;
};
void create(struct queue *s){
    s->fir=0;
    s->las=-1;
}
void enqueue(struct queue *s,int n){
    s->las++;
    if(s->las==MAX){
        printf("Queue is full\n");    }
    s->arr[s->las]=n;
}
void disp(struct queue *s){
    for(int i=0;i<=s->las;i++){
        printf("%d ",s->arr[i]);
    }
    printf("\n");
}
int dequeue(struct queue *s){
    int a=1;
    if(s->las == -1) printf("Empty queue");
    else
    {
        a=s->arr[0];
        for(int i=0;i < s->las ;i++){
            s->arr[i]=s->arr[i+1];
        }
        s->las--;
    }
    return a;
}
void isempty(struct queue *s){
    if(s->las==-1) printf("Empty!!\n");
    else printf("Not empty!\n");
}
int size(struct queue s){
    int j=0;              //We didn't used pointers because we need to only count nuber of elements inside the queue!!!
     for(int i=0;i <= s.las ;i++){
        j++;
    }
    return j;
}
int seek(struct queue s){
    return s.arr[0];
}
int main(){
   struct queue a;
   create(&a);
     enqueue(&a,368);   enqueue(&a,673);
     enqueue(&a,30);
     enqueue(&a,31);
     enqueue(&a,32);      dequeue(&a);      dequeue(&a);
     enqueue(&a,32);
    printf("First element at the moment is:%d\n", seek(a));

     enqueue(&a,33);
     enqueue(&a,55);
     dequeue(&a);
  printf("Size is %d\n",size(a));  //without using pointer!!
  disp(&a);

  isempty(&a);






}
