class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int n = nums.size();
        for(auto &it : nums){
            if(it <= 0 or it > n){
                it = n + 1;
            }
        }
        
        for(auto & it : nums){
            
            if(abs(it) <= n   ){
                if(nums[abs(it) - 1] < 0)continue;
                nums[abs(it) - 1] *= -1;
            }
        }
        
        for(int i = 0 ; i < n ; i++){
            if(nums[i] >= 0 ){
                return i + 1;
            }
        }
        return n + 1 ;
    }
};