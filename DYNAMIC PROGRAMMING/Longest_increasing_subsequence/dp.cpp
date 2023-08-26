/*Given an integer array nums, return the length of the longest strictly increasing 
subsequence
Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.*/
int max(int a,int b){
    if (a>b) return a;
    else return b;
}
int lengthOfLIS(int* nums, int numsSize) {
    int dp[numsSize];
    for (int i = 0; i < numsSize; i++) {
        dp[i] = 1; // Initialize all elements with 1
    }
    for (int i = 1; i < numsSize; i++) {
        int lar = -1; // Initialize to an invalid index   
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                dp[i]=max(dp[i],dp[j]+1); // update dp[i] each time
            }
        }
    }
    int lar = dp[0];
    for (int i = 0; i < numsSize; i++) {
        if (dp[i] > lar) {
            lar = dp[i]; // Find the maximum LIS length
        }
    }
    return lar;
}
