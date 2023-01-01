class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            if(nums[i] <= 0 )nums[i] = n + 1;
        }
        
        for(int i = 0 ; i < n ;i++){
            int cur = abs(nums[i]);
            if(cur >= 1 and cur <= n and nums[cur - 1] > 0){
                nums[cur - 1] *= -1;
            }
        }
        for(int i = 0 ; i < n ;i++){
            if(nums[i] > 0)return i + 1;
        }
        return n + 1;
    }
};