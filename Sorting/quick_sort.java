import java.util.*;
public class Main {

  static int partition(int arr[],int low,int high) {
    int pivot = array[high];
    int i=low-1;
    for(int j=low;j<high;j++) {
      if(array[j]<=pivot){
        i++;   //swap with pointer pointing to left side of partition
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
      }
    }
    int temp=arr[i+1];
    arr[i+1]=arr[high];  // arr[p+1] denotes position of pivot!!
    arr[high]=temp;      // swapped arr[high] NOT pivot !
    return (i + 1);
  }

  static void quicksort(int arr[],int low,int high) {
    if (low<high) {
      int pivot= partition(arr,low,high);
      quicksort(arr,low,pivot-1);
      quicksort(arr,pivot+1,high);
    }
  }
  public static void main(String args[]) {
         Scanner inp=new Scanner(System.in);
         System.out.println("Enter number of elements: ");
         int n=inp.nextInt(); int []arr=new int[n];
         for(int i=0;i<n;i++) arr[i]=inp.nextInt();
         System.out.println("<----QUICK SORT---->");
         quicksort(arr,0,n-1);
         System.out.println("Sorted array is: ");
         for(int i=0;i<n;i++) System.out.print(arr[i]+" ");



  }
}
