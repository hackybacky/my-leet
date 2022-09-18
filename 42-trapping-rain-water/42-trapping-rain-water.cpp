class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        
        int l=0,r=n-1;
        int rightmost=0,leftmost=0;
        int ans=0;
        while(l<=r){
            if(height[l]<=height[r]){
                if(height[l]>=leftmost)leftmost=height[l];
                else ans+=leftmost-height[l];
                l++;
            }
            else {
                if(height[r] > rightmost)rightmost=height[r];
                else ans+=rightmost-height[r];
                r--;
            }
        }
        return ans;
    }
};