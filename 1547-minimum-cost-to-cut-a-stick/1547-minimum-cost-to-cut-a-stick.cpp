class Solution {
public:
    int dp[101][101];
    
    int recur(int i, int j , int start , int end , vector<int>&cuts){
        if(i>j)return 0;
        // if(start>end)return INT_MAX/10;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans= INT_MAX;
        // cout<<end-start<<endl;
        for(int k=i;k<=j;k++){
           
            ans=min(ans,end-start+recur(k+1,j,cuts[k],end,cuts)+recur(i,k-1,start,cuts[k],cuts));
        }
        
        return dp[i][j]=ans;
    }
    int minCost(int n, vector<int>& cuts) {
        memset(dp,-1,sizeof(dp));
        sort(cuts.begin(),cuts.end());
        return recur(0,cuts.size()-1,0,n,cuts);
    }
};