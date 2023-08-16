class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0 , r = nums.size() - 1;
        int ans = 0;
        while(l <= r){
            int mid = (l + r)/2;
            if(nums[mid] < nums[r]){
                ans = mid;
                r = mid ;
            }
            else if(nums[mid] == nums[r]){
                r--;
            }
            else  l = mid + 1;
        }
        
        return nums[l];
    }
};