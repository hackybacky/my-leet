class Solution {
public:
    unordered_map<string , bool > dp;
    bool recur(string  s , string a){
        if(s == a){
            return true;
        }
        if(dp.find(s+a) != dp.end()){
            return dp[s+a];
        }
        string ds = s;
        string da = a;
        sort(ds.begin() , ds.end());
        sort(da.begin() , da.end());
        if(ds != da){
            return false;
        }
        bool flag = false;
        int n = s.size();
        for(int i = 0 ; i < s.size()-1  ; i++){
            string fs = s.substr(0, i + 1);
            string ss = s.substr(i + 1);
            string fa = a.substr(0 , i + 1);
            string sa = a.substr(i + 1);
            
            flag |= (recur(fs , fa) & recur(ss , sa));
            flag |=( recur(fs , a.substr(n - i - 1)) & recur(ss , a.substr(0,n-i- 1)));
            
        }
        return dp[s+a] = flag;
    }
    bool isScramble(string s1, string s2) {
        
        return recur(s1 , s2);
    }
};