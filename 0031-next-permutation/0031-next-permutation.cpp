class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2 ;
        while(i >= 0 and nums[i] >= nums[i + 1])i--;
        if(i == -1){
            reverse(nums.begin() , nums.end());
            return ;
        }
        reverse(nums.begin() + i + 1 , nums.end());
        auto it = upper_bound(nums.begin() + i + 1 , nums.end() , nums[i]);
        swap(nums[i] , *it);
        
        return ;
        
    }
};