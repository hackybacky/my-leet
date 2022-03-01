class Solution {
public:
    int n;
    unordered_map<string,bool> dp;
    bool recur(string s , vector<string>& wordDict   ){
        
        if(s.size()==0)return 1;
        if(dp.find(s)!=dp.end())return dp[s];
        bool ans=false;
        for(int i=0; i<wordDict.size(); i++){
            
            if(wordDict[i]==s.substr(0,wordDict[i].size())){
                ans|= recur(s.substr(wordDict[i].size()),wordDict);
            }
        }
        return dp[s]=ans;
        
        
        
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n=s.size();
        return recur(s,wordDict);
    }
};