class Solution {
public:
    vector<vector<int>> mp;
    vector<vector<int>> dp;
    int mod = 1e9 + 7;
    int recur(int i , int j , vector<string>&words , string &target){
        if(i == target.size()) return 1;
        if(j == words[0].size())return 0;
        if(dp[i][j] != -1)return dp[i][j];
        
        int ans = mp[j][target[i] - 'a'];
        ans = ((long)(ans * (long )(recur(i + 1 , j + 1 , words , target))%mod)%mod + recur(i , j + 1 , words, target)%mod)%mod;
        return dp[i][j] = ans % mod;
        
    }
    int numWays(vector<string>& words, string target) {
        
        int n = words[0].size();
        mp.assign(n , vector<int>(26 , 0));
        dp.assign(target.size() , vector<int>(n , -1));
        for(int i = 0 ; i < words.size() ; i++){
            for(int j = 0 ; j < n ;  j++){
                mp[j][words[i][j] - 'a']++;
            }
        }
        
        return recur(0 , 0 , words , target);
        
        
    }
};