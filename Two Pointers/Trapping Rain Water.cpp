class Solution {
public:
    int trap(vector<int>& height) {
        int l=0; // leftmost highest tower
        int r=height.size()-1; // rigthmost interator
        int maxl=0;        int maxr=0;
        int ans=0;
        while(l<=r){            
              if(height[l]<height[r]){
                  if(height[l]>maxl) maxl=height[l];
                  ans+=maxl-height[l];
                  l++;
              }
              else
              {
                  if(maxr<height[r]) maxr=height[r];
                  ans+=maxr-height[r];
                  r--;
              }
        }
        return ans;
    }
};
