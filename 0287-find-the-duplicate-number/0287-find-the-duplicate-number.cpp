class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        for(auto it : nums){
            int cur = abs(it);
            
            if(nums[cur - 1] < 0){
                return abs(it);
            }
            nums[cur - 1] *= -1;
        }
        return nums.size();
    }
};