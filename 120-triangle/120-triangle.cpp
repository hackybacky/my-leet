class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int  n = triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j =0 ;j<=i;j++){
                if(i==0)dp[i][j]=triangle[i][j];
                else{
                    
                    dp[i][j]=min((j-1>=0?dp[i-1][j-1]:INT_MAX),(j<=i-1?dp[i-1][j]:INT_MAX))+triangle[i][j];
                    // cout<<dp[i][j]<<" ";
                }
            }
            // cout<<endl;
        }
        
        int ans = INT_MAX;
        for(int i=0;i<triangle[n-1].size();i++){
            ans=min(dp[n-1][i],ans);
        }
        return ans;
    }
};