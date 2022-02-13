class Solution {
public:

    int maximumANDSum(vector<int>& a, int k) {
        int n = a.size();
        for(int i=0; i<2*k; i++)a.push_back(0);
        n=2*k;
        vector<int> dp(1<<n+1,0);
        int ans=0;
        for(int i=0; i < (1<<n) ; i++){
            int cnt=__builtin_popcount(i);
            int slot =(cnt+1)/2;
            for(int j=0; j<n; j++){
                if( (i &(1<<j)) )
                dp[i]=max(dp[i],dp[ i^(1<<j) ] + (slot & a[j]));
            }
            ans=max(ans,dp[i]);
        }
        
        return ans;
    }
};