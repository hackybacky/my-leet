class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        
        vector<vector<int>> dp(26);
        
        for(int i=0 ; i< s.size() ;  i++ ){
            dp[s[i]-'a'].push_back( i );
        }
        
        int ans=0;
        for(auto it : words){
            int prev=-1;
            for(auto it2 : it ){
                int ele = it2-'a';
                auto it3= lower_bound( dp[ele].begin(),dp[ele].end() , prev+1);
                if(it3==dp[ele].end()){
                    goto next;
                }
                prev= *it3;
            }
            ans++;
            next:;
        }
        return ans;
    }
};