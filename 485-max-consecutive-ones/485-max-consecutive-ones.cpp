class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        
        int current_one = 0;
        int n = nums.size();
        for(int i=0;i<n ;i++){
            if(nums[i]==0){
                ans = max(ans,current_one);
                current_one=0;
            }
            else current_one++;
        }
        ans = max(ans,current_one);
        
        return ans;
    }
};