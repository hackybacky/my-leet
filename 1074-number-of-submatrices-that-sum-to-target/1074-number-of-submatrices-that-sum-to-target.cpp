class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m  = matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        
        
        for(int i=0;i<n ;i++){
            for(int j=0;j<m;j++){
                dp[i][j]=matrix[i][j]+(j-1>=0?dp[i][j-1]:0);
            }
        }
        
        int ans=0;
        for(int i=0;i<m; i++){
            for(int j=i;j<m;j++ ){
                int su=0;
                unordered_map<int,int>mp;
                mp[0]=1;
                for(int k=0;k<n ;k++){
                    su+=dp[k][j]-(i-1>=0?dp[k][i-1]:0);
                    if(mp.find(su-target)!=mp.end())
                    ans+=mp[su-target];
                    mp[su]++;
                }
            }
        }
        return ans;
    }
};