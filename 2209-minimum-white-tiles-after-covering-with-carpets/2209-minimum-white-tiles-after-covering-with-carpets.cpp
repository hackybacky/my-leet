class Solution {
public:
    vector<vector<int>> dp;
    int avail;
    int n;
    int l;
    int recur(int i ,int used,string &floor){
        if(i==n)return 0;
        if(dp[i][used]!=-1)return dp[i][used];
        if(avail<=used or i+l>n){
            int ans=0;
            
            for(int j=i;j<n; j++){
                ans+=(floor[j]=='1');
            }
            if(used<avail){
                return  dp[i][used]= max(0,ans-(avail-used)*l);
            }
            return dp[i][used]=ans;
        }
        
        int ans;
        if(floor[i]=='0'){
            ans= recur(i+1,used,floor);
        }
        else{
            ans = min(1+recur(i+1,used,floor),recur(i+l,used+1,floor));
        }
        return dp[i][used]=ans;
    }
    
    int minimumWhiteTiles(string floor, int num, int len) {
        n = floor.size();
        l=len;
        avail= num;
        //cout<<n;
        dp.assign(n+5,vector<int>(num+5,-1));
        
        int ans = recur(0,0,floor);
        return ans;
    }
};