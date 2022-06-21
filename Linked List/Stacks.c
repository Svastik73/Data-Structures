#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};
void create(struct node **s){
 *s=NULL;   //*s is a pointer!!
}
void push(struct node **s,int n){
    struct node *p=(struct node *)malloc(sizeof(struct node));
    p->data=n;
    p->next=*s;
    *s=p;

}

int main(){
 struct node *ptr;
 create(&ptr);
     push(&ptr,2);   push(&ptr,3); push(&ptr,); push(&ptr,2); push(&ptr,2);

     while(ptr!=NULL){
         printf("%d ",ptr->data);
         ptr=ptr->next;
     }





}
