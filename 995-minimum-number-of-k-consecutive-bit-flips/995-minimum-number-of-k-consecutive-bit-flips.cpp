class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        
        int n=nums.size();
        int ans=0;
        vector<int> dp(n,0);
        for(int i=0;i<n; i++){
            int val;
            if(i>=1)dp[i]=dp[i-1];
            
            if(i-k>=0)val=dp[i]-dp[i-k];
            
            else val=dp[i];
            int cur=nums[i];
            if(val%2==1){
                cur^=1;
            }
            
            if(cur==0){
                if(i+k>n)return -1;
                dp[i]++,ans++;
            }
               
        }
        return ans;
        
    }
};