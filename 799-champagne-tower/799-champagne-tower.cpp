class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(101,vector<double>(101,0));
        
        dp[0][0]=poured*1.0;
        
        for(int i=0; i<=query_row +1; i++){
            for(int j=0; j<=i; j++){
                
                if( i-1>=0){
                    if(j-1>=0)dp[i][j]+=max(0.0,(dp[i-1][j-1]-1)/2),dp[i-1][j-1]=min(1.0,dp[i-1][j-1]);
                    dp[i][j]+=max(0.0,(dp[i-1][j]-1)/2);
                    
                }
            }
        }
        return dp[query_row][query_glass];
    }
};