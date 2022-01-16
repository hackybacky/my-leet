class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        
        int n=questions.size();
        vector<long long> dp(n+1,0);
        long long ans=0;
        for(int i= n-1; i>=0 ; i--){
            
            dp[i]=questions[i][0];
            
            int next=questions[i][1];
            if(i+next+1<n){
                dp[i]+=dp[i+next+1];
            }
            dp[i]=max(dp[i],dp[i+1]);
            //ans=max(dp[i],ans);
            
        }
        return dp[0];
        
    }
};