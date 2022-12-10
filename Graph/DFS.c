#include <stdio.h>
#include<stdlib.h>
//dfs
struct node {
    int data;
   struct node *next;
};
struct graph{
    int num; int * visit;
    struct node **adjlist;
};
struct graph* create_graph(int vert){
   struct graph * Graph=malloc(sizeof(struct graph));
   Graph->visit=malloc(sizeof(int)*vert);
   Graph->adjlist=malloc(vert*sizeof(struct node *));
   for(int i=0;i<vert;i++){
    Graph->visit[i]=0;
    Graph->adjlist[i]=NULL;
   }
   return Graph;
}
void addEdge(struct graph * g,int src,int dest){
    struct node*newp=malloc(sizeof(struct node));
    newp->data=dest;   //insert at linear time!1
    if(g->adjlist[src]==NULL){   g->adjlist[src]=newp; newp->next=NULL;}
    else
    {
        newp->next=g->adjlist[src];
        g->adjlist[src]=newp;
    }
}
void dfs(struct graph* g,int ver){
      struct node *temp=g->adjlist[ver];
      int tem;
      g->visit[ver]=1;
      printf("Viisted %d \n",ver);
      while(temp->next!=NULL){
            tem=temp->data;
            if(g->visit[tem]==0) dfs(g,tem);
            temp=temp->next;
      }
}
int main(){
    struct graph *gr=create_graph(7);
    addEdge(gr,0,1);  addEdge(gr,0,2); addEdge(gr,0,4); addEdge(gr,1,6); addEdge(gr,1,3); addEdge(gr,3,4);
    addEdge(gr,2,4); addEdge(gr,6,2);

    for(int i=0;i<5;i++){
        if(gr->visit[i]==0) dfs(gr,i);
    }
    return 0;
}
