#include<stdio.h>
#include<stdlib.h>
#define MAX 10
struct node{
   int data;
   struct node *next;
};
 void enqueue(struct node **s,int n){
  struct node *neu=(struct node *)malloc(sizeof(struct node));
  neu->data=n;
  neu->next=NULL;
  (*s)->next=neu;
  *s=neu;
 }
 void seek(struct node **s){
  printf("\n%d is at top of queue\n",(*s)->data);
 }
  void dequeue(struct node **s){
   struct node *temp=*s;
   *s=(*s)->next;
   free(temp);
  }
  int size(**s){
  int c=0;
  while((*s)->next!=NULL){
    c++; (*s)=(*s)->next;
    }
   return c;
}
int main(){
  struct node * head;
  struct node *ptr;
  enqueue(&ptr,7);
  head=ptr;
  enqueue(&ptr,5);
  enqueue(&ptr,6);
   printf("%d",ptr->data);
    dequeue(&head);
    enqueue(&ptr,45);
    enqueue(&ptr,66);
    seek(&head);
    size(&head);
}
