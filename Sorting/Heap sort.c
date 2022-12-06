#include <stdio.h>
#include<stdlib.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int arr[], int n, int i){
    int max=i;
    int l=2*i+1;
    int r=2*i+2;
      if(l<n && arr[l]>arr[max]) max=l;
      if (r< n && arr[r]> arr[max])       max=r; //dont use max here

      if (max!= i) {
      swap(&arr[i],&arr[l]);
      heapify(arr,n,l);
    }
}
void build_max_heap(int arr[],int n){
    for (int i=n/2-1;i>=0;i--)  heapify(arr,n,i);
}
  void heap_sort(int arr[], int n) {
       for (int i=n-1;i>=0;i--) {
      swap(&arr[0], &arr[i]);
      heapify(arr, i, 0);
    }
  }
int main() {
  int n; printf("Enter array size: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elemenst...\n");
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    printf("HEAP SORT\n");
    heap_sort(arr,n);
    printf("Sorted array is: ");
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
  }

}
