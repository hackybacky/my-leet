class Solution {
public:
   
    
    string longestPalindrome(string s) {
        int n=s.size();
        int dp[n][n];
        memset(dp,-1,sizeof(dp));
        function <int(int,int)> recur=[&](int i,int j ){
            if(i>j)return 1;
            
            if(dp[i][j]!=-1)return dp[i][j];
            if(s[i]==s[j] and recur(i+1,j-1)){
                
                dp[i][j]&=recur(i+1,j-1);
            }
            else{
                
                dp[i][j]=0;
                recur(i+1,j);
                recur(i,j-1);
                
            }
            return dp[i][j];
        };
        recur(0,n-1);
        string ans="";
        int start=0;
        int sz=0;
        for(int i=0 ; i< n ; i++){
            for(int j =0 ; j< n ; j++){
                //cout<<dp[i][j]<<" ";
                if(j-i+1 > sz and dp[i][j]==1){
                    start=i;
                    sz=j-i+1;
                }
            }
            //cout<<endl;
        }
        return s.substr(start,sz);
        
        
        
    }
};