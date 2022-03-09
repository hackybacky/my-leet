class Solution {
public:
    vector<vector<int>>dp;
    int recur(int k ,int n ){
        if(n==0 or n==1)return n;
        if(k==1)return n;
        
        if(dp[k][n]!=-1)return dp[k][n];
        int l=1,r=n;
        int ans = INT_MAX;
        int temp=0;
        while(l<=r){
            int mid = (l+r)/2;
            int left  = recur( k-1, mid-1);
            int right = recur(k,n-mid);
            
            temp= 1+max( left,right );
            if(left<right){
                l=mid+1;
            }
            else r=mid-1;
            ans=min(ans,temp);
        }
        
        return dp[k][n]=ans;
        
    }
    int superEggDrop(int k, int n) {
        dp.assign(k+1,vector<int>(n+1,-1))    ;
        
        return recur(k,n);
    }
};