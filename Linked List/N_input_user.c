#include<stdio.h>
#include<stdlib.h>
struct node {
int data;
struct node *next;
};
int main(){
int t; scanf("%d",&t);  //Entering the size of linked list by user!!
struct node *head=NULL;   //Creating head pointer to store address of first node!
struct node *ptr=NULL;    //Creating a pointer who traverses throughout nodes!!
for(int i=0;i<t;i++){
struct node *n=malloc(sizeof(struct node));         //running for loop for creating n nodes!!
n->data=i+1;  // Assigning data to nodes

if(i==0){
ptr=n;
head=n;
}
else if(i==t-1){
   ptr->next=n;
    n->next=NULL;   // if last node is reached assigning the address of struct node *next data type=NULL!!
else if(i>0){
    ptr->next=n;   // Assigning address of new node to "ptr->next"
    ptr=n;
}
}

while(head!=NULL){
    printf("%d\n",head->data);
    head=head->next;          //OUTPUT OF THE LINKED LIST!!
    
 }
}
