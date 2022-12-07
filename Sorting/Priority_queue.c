#include<stdio.h>
#include<stdlib.h>
typedef struct process{
    int id;
    int key; // priority assigned!
}process;
int find_max(process p[]){
       return p[0].id;
}
void heapify(process arr[],int i,int n){
    int max=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && arr[l].key>arr[max].key) max=l;
    if(r<n && arr[r].key>arr[max].key) max=r;
    if(max!=i){
        int t=arr[i].key; int t2=arr[i].id;
        arr[i].key=arr[max].key; arr[i].id=arr[max].key;
        arr[max].key=t; arr[max].id=t2;
        heapify(arr,max,n);
    }

}
int extract_max(process p[],int n){
    int temp=p[0].id;
    p[0].id=p[n-1].id;
    p[0].key=p[n-1].id;
    heapify(p,0,n--);
    return temp;
}

void build_max_heap(process arr[],int n){
    for(int i=n/2-1;i>=0;i--) heapify(arr,i,n);
}

int main(){
    int n; printf("Enter number of elements in priority queue: ");
    scanf("%d",&n);

    process pq[n];
    for(int i=0;i<n;i++){
        printf("enter id: "); scanf("%d",&pq[i].id);
        printf("enter key if this id: "); scanf("%d",&pq[i].key);
    }
    build_max_heap(pq,n);
    printf("%d",pq[0].key);
    int t=extract_max(pq,n);
    printf("%d",pq[0].key);
}
