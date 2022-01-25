class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        
        int n=seats.size();
        int m=seats[0].size();
        vector<vector<int>> dp(n+1,vector<int>((1<<m),-1));
            
        vector<int> avail(n+1,0);
        
        for(int i=0; i<n ; i++){
            for(int j=0; j<m; j++){
                if(seats[i][j]=='.'){
                    avail[i+1]|=(1<<j);
                }
            }
        
        }
        for(int i=0; i<(1<<m);i++)dp[0][i]=0;
        
        for(int i=1; i<=n ;i++){
            for(int premask=0;premask<(1<<m);premask++){
                if(dp[i-1][premask]==-1)continue;
                for(int mask=0;mask<(1<<m); mask++){
                    if((avail[i]&mask)!=mask)continue;
                    
                    if(mask&(mask>>1))continue;
                    if(mask&(premask<<1) or mask&(premask>>1))continue;
                    dp[i][mask]=max(dp[i-1][premask]+__builtin_popcount(mask),dp[i][mask]);
                }
            }
        }
                       
        return *max_element(dp[n].begin(),dp[n].end());
        
    }
};