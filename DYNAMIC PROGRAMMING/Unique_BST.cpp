/*
Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.
*/
class Solution {
public:
    int numTrees(int n) {
        // each node will surely become root!
        //DP problem!
        if(n==1 || n==0) return 1;
        int arr[n+1];
        arr[0]=1;
        arr[1]=1;
        int sum=0;
        for(int i=2;i<=n;i++){// each subtree will repeat itself hence use DP!
             sum=0;
             for(int j=0;j<i;j++){
                 sum+=arr[j]*arr[i-1-j];
                 // similar to isomerism in organic chemistry
             }
             arr[i]=sum;
        }
        return arr[n];
    }
};
