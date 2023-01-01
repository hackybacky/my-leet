class Solution {
public:
    int trap(vector<int>& height) {
        int leftmost = 0 , rightmost = 0;
        int n = height.size();
        int ans = 0;
        int l = 0 , r = n - 1 ;
        while(l <= r){
            if(height[l] <= height[r]){
                if(height[l] >= leftmost){
                    leftmost = height[l];
                }
                else {
                    ans += leftmost - height[l];
                }
                l++;
            }
            else{
                if(height[r] >= rightmost){
                    rightmost = height[r];
                }
                else {
                    ans += rightmost - height[r];
                }
                r--;
            }
            
        }
        return ans;
    }
};