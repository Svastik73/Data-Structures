/*
case=[3,1,2,4]
  

*/
int lengthOfLIS(int* nums, int numsSize) {
    int dp[numsSize];
    
    for (int i = 0; i < numsSize; i++) {
        dp[i] = 1; // Initialize all elements with 1
    }
    
    for (int i = 1; i < numsSize; i++) {
        int lar = -1; // Initialize to an invalid index
        
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                if (lar == -1 || nums[j] > nums[lar]) {
                    lar = j; // Find value just smaller than nums[i]
                }
            }
        }
        
        if (lar != -1) {
            dp[i] = dp[lar] + 1; // Change length by 1 if condition is satisfied
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
