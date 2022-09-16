import java.util.*;

public class hello{ 
  
    public static int parti(int [] arr,int l,int h){
        int pivo=h;
        int i=0; int ptr=-1;//ptr is pointing to left side of;
        while(i<pivo){
          if(arr[i]<arr[pivo]){
            ptr++;
            int t=arr[i];
            arr[i]=arr[ptr];
            arr[ptr]=t;
            i++;
          }
          else i++;
        }
        ptr++;
        int t=arr[pivo];
        arr[pivo]=arr[ptr];
        arr[ptr]=t;
     return ptr;
}
public static void qisort(int [] arr,int l,int h){
if(l<h){ 
      int piv=parti(arr,l,h);
      qisort(arr , l, piv-1 ) ;
      qisort(arr, piv+1, h);
       }
 }
 public static void main(String []args) { 
         int n; System.out.println("Enter size of array! ");
         Scanner inp=new Scanner(System.in);
         n=inp.nextInt();
  inp.nextLine();
          int [] arr=new int[n];
          for(int i=0;i<n;i++){
            arr[i]=inp.nextInt();
          }
          
          qisort(arr,0,n-1);
  for(int i=0;i<n;i++){
        System.out.print(arr[i]+" ");
  }
   }

}
