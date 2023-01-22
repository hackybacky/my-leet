class Solution {
public:
    bool pal(string &s){
        int l = 0; 
        int h = s.size()-1;

        while(l < h){
            if(s[l] != s[h])  return false;
            l++;
            h--;
        }
        return true;
    }


    void solve(int ind, string &s, string s1, vector<vector<string>> &res, vector<string> ans){
       int n = s.size();
       
       if(ind >= n){
           if(pal(s1) && (s1.size() > 0)){
               ans.push_back(s1);
               res.push_back(ans);
           }
           return;
       }
       
      
       solve(ind+1, s, s1+s[ind], res, ans);
    
       
       if(pal(s1) && (s1.size() > 0)){
           ans.push_back(s1);
           if(ind < n){
           s1=s[ind];
           solve(ind+1, s, s1, res, ans);
           }
           else{
               ans.push_back(s1);
               res.push_back(ans);
               return;
           }
       }
       return; 
    }
    vector<vector<string>> partition(string s) {
        
       vector<vector<string>> res;
       vector<string> ans;
       string s1 = "";
       s1+=s[0];

       solve(1, s, s1, res, ans);
       return res;
    }
};