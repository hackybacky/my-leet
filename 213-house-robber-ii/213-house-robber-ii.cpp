class Solution {
public:
    int giveans(int start_index,vector<int>&nums){
        int n = nums.size();
        vector<int>dp(n,0);
        for(int i = start_index;i<n-1+start_index;i++){
            
            int prev= 0;
            if(i-1>=start_index)prev=dp[i-1];
            int sp = 0;
            if(i-2>=start_index)sp=dp[i-2];
            sp+=nums[i];
            dp[i]=max(sp,prev);
        }
        return dp[n-1+start_index-1];
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        int ans = max(giveans(0,nums),giveans(1,nums));
        return ans;
    }
};