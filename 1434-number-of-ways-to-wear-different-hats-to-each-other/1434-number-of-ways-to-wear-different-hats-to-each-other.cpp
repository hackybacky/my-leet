class Solution {
public:
    const int MOD=1e9+7;
    int numberWays(vector<vector<int>>& hats) {
        int person_size=hats.size();
        vector<vector<int>> person(41);
       // int person_size=10;
        for(int i=0 ; i< hats.size() ; i++ ){
            
            for(auto it : hats[i]){
                //cout<<it<<endl;
                person[it].push_back(i);
            }
        }
        
        int no_hats=40;
        
        vector<vector<int>> dp( no_hats+2 , vector<int>((1<<person_size),0));
        
        dp[0][0]=1;
       // for(int i=0 ;i<(1<<person_size); i++)dp[0][i]=1;
        
        for(int cur_hat=1; cur_hat<= no_hats; cur_hat++){
            
            for(int mask=0 ; mask < (1<<person_size) ; mask++){
                dp[cur_hat][mask]+=dp[cur_hat-1][mask];
                dp[cur_hat][mask]%=MOD;
                for(auto people : person[cur_hat]){
                    if(mask & (1 << people))continue;
                    //cout<<mask<<endl;
                    dp[cur_hat][mask|(1<<people)]+=dp[cur_hat-1][mask];
                   // cout<<dp[0][mask]<<endl;
                  //  cout<<dp[cur_hat][mask|(1<<people)]<<endl;
                    dp[cur_hat][mask|(1<<people)]%=MOD;
                }
            }
        }
        return dp[no_hats][(1<<person_size)-1];
        
    }
};