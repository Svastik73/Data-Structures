#include <stdio.h>
#include <stdlib.h>

struct node {
  int vertex;
  struct node* next;
};
struct node* createNode(int);

struct Graph {
  int numVertices;
  struct node** adjLists; // create array which stores memeory addresses!
   int *visit;
    
};


struct node* createNode(int v) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}

struct Graph* createAGraph(int vertices) {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->numVertices = vertices;

  graph->adjLists = malloc(vertices * sizeof(struct node*));//struct node * as it will store adresse of nodes only
   graph->visit=malloc(vertices*sizeof(int));
  int i;
  for (i = 0; i < vertices; i++){
    graph->adjLists[i] = NULL;
    graph->visit[i]=0; // 0 for non visited!
      
  }
  return graph;
}
void addEdge(struct Graph* graph, int src, int dest){
  //for unidirected graph
  struct node* newNode = createNode(dest);
  newNode->next = graph->adjLists[src];
  graph->adjLists[src] = newNode;

  /* edge from d to s for having a both directed graph!
  newNode = createNode(src);
  newNode->next = graph->adjLists[dest];
  graph->adjLists[dest] = newNode;
  */ 
}

// Print the graph
void printGraph(struct Graph* graph) {
  int v;
  for (v = 0; v < graph->numVertices; v++) {
    struct node* temp = graph->adjLists[v];
    printf("%d:: ", v);
    while (temp!=NULL){ // while(temp) == automaticall while temp is not null value!
      printf("%d ", temp->vertex);
      temp = temp->next;
    }
    printf("\n");
  }
}

int main() {
  struct Graph* graph = createAGraph(4);
  for(int i=0;i<4;i++){
   int n;
   printf("Enter adjacents of vertex %d :",i);
   do{  
   scanf("%d",&n);
   if(n!=-1) addEdge(graph,i,n);

   }
   while(n!=-1);
  }

  printGraph(graph);

  return 0;
}
