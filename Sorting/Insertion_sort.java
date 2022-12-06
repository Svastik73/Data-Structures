import java.util.*;
public class Insertion_sort{              // <FILE NAME>.java MUST BE SAME AS PUBLIC CLASS <NAME>
     public void insert_sort(int []arr,int n){
         for(int i=1;i<n;i++){
            int key=arr[i];
            int j=i-1;
            while((j>=0)&&(arr[j]>key)){
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=key;
        }
     }
    public static void main(String []args){
        Scanner inp=new Scanner(System.in);
        System.out.println("Enter the array size: ");
        int n=inp.nextInt();
        System.out.println("Enter array elements: ");
        int []arr=new int[n];
        for(int i=0;i<n;i++) arr[i]=inp.nextInt();
        insert_sort(arr,n);
        System.out.println("Selection sort");
        System.out.println("Sorted array is: ");
        for(int i=0;i<n;i++) System.out.print(arr[i]+ " ");

    }
}
