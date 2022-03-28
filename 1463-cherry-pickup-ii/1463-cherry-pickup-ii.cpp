class Solution {
public:
    
    int dp[71][71][71];
    int n,m;
    vector<int>x;
    int recur(int i, int j , int k , vector<vector<int>>&grid){
        if(  j<0 or j>=m  or k<0 or k>=m  ) return -1e5;
        if(i==n )return 0;
       // cout<<x[2]<<endl;
       if(dp[i][j][k]!=-1)return dp[i][j][k];
        
        int ans =0;
        int cur;
        if( j==k)cur=grid[i][j];
        else cur = grid[i][j]+grid[i][k];
        for(int t =0 ; t<x.size(); t++){
            for(int p=0; p<x.size(); p++)
            ans=max(ans,cur+recur(i+1,j+x[t],k+x[p],grid));
        }
        return dp[i][j][k]=ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        n= grid.size();
        m = grid[0].size();
        memset(dp,-1,sizeof(dp));
        x={-1,0,1};
       cout<<x[2]<<endl;
        //return 0;
        return recur(0,0,m-1,grid);
    }
};