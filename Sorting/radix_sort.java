import java.io.*;
import java.util.*;

class sort{
    public static int max_arr(int arr[], int n)
    {
        int max=arr[0];
        for(int i=1;i<n;i++)
            if(arr[i]>max)   max = arr[i];
        return max;
    }
    static void count_sort(int arr[], int n, int div)
    {
        int final1[]=new int[n];
        int i;
        int count[] = new int[10];  //size 10 to store 0 to ...9 digits!
        for(i=0;i<10;i++) count[i]=0;

        for(i=0;i<n;i++) count[(arr[i]/div)%10]++;  //increase count

        for(i=1;i<10;i++)   count[i]+=count[i-1];  //cumilative count

        for (i=n-1;i>=0;i--) {
            final1[count[(arr[i]/div)%10]-1]=arr[i];  // rearrange array elements
            count[(arr[i]/div)%10]--;
        }

        for(i=0;i<n;i++)  arr[i]=final1[i];
    }

    public static void radix_sort(int arr[],int n)
    {
        int max=max_arr(arr, n);


        for (int divisor=1; max/divisor>0; divisor*= 10)
            count_sort(arr, n, divisor);
    }

    public static void main(String[] args)
    {
        Scanner inp=new Scanner(System.in);
        System.out.print("Enter number of elements: ");
        int n=inp.nextInt();
        int []arr=new int[n];
        System.out.println("Enter the elements: ");
        for(int i=0;i<n;i++) arr[i]=inp.nextInt();


        radix_sort(arr, n);
        System.out.println("After sorting elemenst are: ");
        for(int i=0;i<n;i++) System.out.print(arr[i]+" ");
    }
}
