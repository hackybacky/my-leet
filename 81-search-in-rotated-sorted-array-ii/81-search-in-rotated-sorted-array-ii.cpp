class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0 , r = n-1;
        
        while(l<=r){
            int mid =(l+r)/2;
            if(nums[mid]==target)return true;
            if(nums[l]==nums[mid] and nums[r]==nums[mid])l++,r--;
            else if(nums[l]<=nums[mid]){
                if(nums[l]<=target and nums[mid]>target)r=mid-1;
                else l = mid+1;
            }
            else{
                if(nums[mid]<target and nums[r]>=target)l=mid+1;
                else r=mid-1;
            }
        }
        
        // 'if(l-1>=0){
        //     return nums[l-1]==target;
        // }'
        return false;
    }
};