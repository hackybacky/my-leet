class Solution {
public:
    vector<vector<int>> dp;
    
    int n ;
    int K;
    int recur(int i , int k ,vector<vector<int>> &piles){
        if(i==n or k==K)return 0;
        
        if(dp[i][k]!=-1)return dp[i][k];
        
        int ans =0;
        int ans2 = recur(i+1,k,piles);
        for( int j=0; j<piles[i].size() and j<K-k ; j++ ){
            ans=max(ans, piles[i][j]+recur(i+1,k+j+1,piles));
        }

        return dp[i][k]=max(ans,ans2);
    }
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        
        n = piles.size();
        K=k;
        dp.resize(n+1,vector<int>(2001,-1));
        for(int i=0; i<n ; i++){
            for(int j=1; j<piles[i].size();j++){
                piles[i][j] +=piles[i][j-1];
            }
        }
        int ans =recur(0,0,piles);
        return ans;
    }
};