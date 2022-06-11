class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        vector<int>dp(n,0);
        
        for(int i=0;i<n;i++){
            
            dp[i]+=(i-1>=0?dp[i-1]:0)+nums[n-1-i];
        }
        int ps=0;
        int ans = INT_MAX;
        for(int i=0; i<=n; i++){
            
            ps+=(i-1>=0?nums[i-1]:0);
            int rem = x-ps;
            auto it = lower_bound(dp.begin(),dp.end(),rem);
            int dis=(it-dp.begin());
            if(it!=dp.end() and *it==rem and n-dis-1>=i ){
                ans=min(ans,i+dis+1);
            }
            if(rem==0)ans=min(ans,i);
        }
        if(ans==INT_MAX)return -1;
        return ans;
        
    }
};