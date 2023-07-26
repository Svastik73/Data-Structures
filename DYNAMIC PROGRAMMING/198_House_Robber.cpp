class Solution {
public:
    int rob(vector<int>& nums) {
        int arr[nums.size()+1];
        arr[0]=0;
        arr[1]=nums[0];
        // strivers method !
        // select index 2;
        //perform ooperations on it
        // Ex: arr[2]=max(arr[0]+nums[2],arr[1]);
        for(int i=1;i<nums.size();i++){
            arr[i+1]=max(arr[i],arr[i-1]+nums[i]);
        }
        return arr[nums.size()];
    }
};
