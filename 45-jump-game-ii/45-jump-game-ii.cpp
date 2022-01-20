class Solution {
public:
    int jump(vector<int>& a) {
        int n=a.size();
        vector<int > dp(n,1e9);
        dp[n-1]=0;
        for(int i=n-1; i>=0 ; i--){
            for(int j=i+1 ; j<=a[i]+i and j<n;j++){
                dp[i]=min(1+dp[j],dp[i]);
            }
        }
        
        return dp[0];
        
    }
};