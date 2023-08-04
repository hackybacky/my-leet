class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int l = 0 , r = nums.size();
        if(r == 1)return nums[0];
        int ans = nums[0];
        while(l <= r){
            int mid = (l + r)/2;
            if(mid % 2 == 1){
                if(nums[mid] != nums[mid - 1]){
                    ans = nums[mid];
                    r = mid - 1;
                }
                else l = mid + 1;
            }
            else{
                if(nums[mid + 1] != nums[mid]){
                    r = mid - 1;
                    ans = nums[mid];
                }
                else l = mid + 1;
            }
        }
        return ans;
    }
};