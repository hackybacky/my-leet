class Solution {
public:
    vector<string>fans;
    void dfs(int i , string s , string  ans , int take , int cur){
        if(i == s.size()){
            if(take == 3 and ans.back() != '.')
            fans.push_back(ans);
            return ;
        }
        if(isdigit(s[i]) == false or (cur == 0  and  ans.back() == '0'))return;
        int ncur = cur* 10 + (s[i] - '0');
        if(ncur > 255)return;
        ans += s[i];
        ans += ".";
        
        dfs(i + 1  , s ,ans , take+ 1 , 0 );
        ans.pop_back();
        dfs(i + 1 , s , ans , take , ncur);
    }
    vector<string> restoreIpAddresses(string s) {
        string ans = "";
        dfs(0 , s , ans , 0 , 0);
        return fans;
    }
};