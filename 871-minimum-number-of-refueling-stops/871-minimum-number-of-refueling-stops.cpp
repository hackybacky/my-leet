class Solution {
public:
//     int dp[501][501];
//     int recur( int i , int take){
//         if(i==stations.size()){
//             return 0;
//         }
//         if(dp[i][take]!=-1)return dp[i][take];
        
        
//     }
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n =stations.size();
        vector<long long int>dp(n+1,0);
        dp[0]=startFuel;
        for(int i=0;i<n;i++){
            for(int t = i; t>=0;--t){
                
                if(dp[t]>=stations[i][0]){
                    
                    dp[t+1]=max(dp[t+1],dp[t]+stations[i][1]);
                }
            }
        }
        for(int i=0;i<=n;i++){
            if(dp[i]>=target)return i;
        }
        return -1;
    }
};