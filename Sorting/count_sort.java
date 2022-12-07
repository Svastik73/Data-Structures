 import java.util.*;
import java.lang.*;
public class count_sort{
    public static int max_arr(int []arr,int n){
        int maxi=arr[0];
        for(int i=1;i<n;i++){
            if(arr[i]>maxi) maxi=arr[i];
        }
        return maxi;
    }

    public static void count_sort(int []arr,int n){
        int max=max_arr(arr, n);
        int []count= new int[max+1];  // count array will be of (size +1)
        int [] final1=new int[n];
        for(int i=0;i<=max;i++) count[i]=0;
        for(int i=0;i<n;i++){
            count[arr[i]]++;
        }
        for(int i=1;i<=max;i++){
            count[i]=count[i]+count[i-1];   // cummilative count
        }
      for(int i=n-1;i>=0;i--){
          final1[count[arr[i]]-1]=arr[i];    // put final1[count[arr[i]]-1]  because index need to be decreased by 1!
          count[arr[i]]--;
      }
        for(int i=0;i<n;i++){
            arr[i]=final1[i];
        }
    }

    public static void main(String []args){
        Scanner inp=new Scanner(System.in);
        System.out.print("Enter number of elements: ");
        int n=inp.nextInt();
        int []arr=new int[n];
        System.out.println("Enter the elements: ");
        for(int i=0;i<n;i++) arr[i]=inp.nextInt();
        count_sort(arr,n);
        System.out.println("After count sort: ");
        for(int i=0;i<n;i++) System.out.print(arr[i]+" ");


    }
}
