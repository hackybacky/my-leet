class Solution {
public:
    unordered_map<string, int> mp;
    static bool cmp(string & a , string & b){
        return a.size()< b.size();
    }
    int recur(string & s){
        int n = s.size();
        vector<int>dp(n + 1, 0);
        dp[0] = 1;
        for(int i = 1 ; i <= n ; i++){
            string cur = "";
            for(int j = i ; j <= n; j++){
                cur += s[j - 1];
                
                if(mp.find(cur) != mp.end()){
                    dp[j] |= dp[i- 1];
                    // cout << "helo"<< endl;
                }
            }
        }
        return dp[n];
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        
        sort(words.begin() , words.end() , cmp);
        vector<string>ans;
        for(auto it : words){
            string &cur = it;
            // cout << cur << endl;
            bool flag = recur(cur);
            if(flag){
                ans.push_back(cur);
            }
            mp[cur] = 1;
        }
        return ans;
    }
};