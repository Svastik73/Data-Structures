#include <stdio.h>
#include <stdlib.h>
struct queue {
  int arr[30];
  int front;
  int rear;
};
struct node {
  int vertex;
  struct node* next;
};
struct Graph {
  int num;
  struct node** adjLists;
  int* visited;
};
struct node* createNode(int v) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}
struct Graph* createGraph(int vertices) {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->num = vertices;
  graph->adjLists = malloc(vertices * sizeof(struct node*));
  graph->visited = malloc(vertices * sizeof(int));
  for (int i = 0; i < vertices; i++) {
    graph->adjLists[i] = NULL;
    graph->visited[i] = 0;
  }
  return graph;
}
void addEdge(struct Graph* graph, int src, int dest) {
  struct node* newNode = createNode(dest);
  newNode->next = graph->adjLists[src];
  graph->adjLists[src] = newNode;
}
struct queue* createQueue() {
  struct queue* q = malloc(sizeof(struct queue));
  q->front = -1;
  q->rear = -1;
  return q;
}
void enqueue(struct queue* q, int value) {
    if (q->front ==-1)
      q->front = 0;    q->rear++;
    q->arr[q->rear] = value;
}
int dequeue(struct queue* q) {
  int item;
    item = q->arr[q->front];
    q->front++;
    if (q->front > q->rear) {
      q->front = q->rear = -1;
    }
  return item;
}
int isEmpty(struct queue* q) {
  if (q->rear == -1)
    return 1;
  else
    return 0;
}
void bfs(struct Graph* graph, int start) {
  struct queue* q = createQueue();
  graph->visited[start] = 1;
  enqueue(q, start);
  while (!isEmpty(q)) {
    int cur = dequeue(q);
    printf("Visited %d\n", cur);
    struct node* temp = graph->adjLists[cur];
    while (temp) {
      int curver = temp->vertex;
      if (graph->visited[curver] == 0) {
        graph->visited[curver] = 1;
        enqueue(q, curver);
      }
      temp = temp->next;
    }
  }
}
int main() {
  struct Graph* gr = createGraph(6);
addEdge(gr,0,2);  addEdge(gr,0,4); addEdge(gr,4,3); addEdge(gr,3,0); addEdge(gr,4,2); addEdge(gr,5,1);
    addEdge(gr,4,1); addEdge(gr,3,5);
  bfs(gr, 0);
  return 0;
}
