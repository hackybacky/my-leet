class Solution {
public:
    vector<vector<string>>lans;
    void recur(int i , string &s , vector<string>ans ){
        if(i==s.size()){
            lans.push_back(ans);
            return ;
        }
        string cur="";
        for(int j=i; j < s.size() ; j++){
            
            cur+=s[j];
            
            string rev = cur;
            reverse(rev.begin(),rev.end());
            
            if(rev==cur){
                // cout<<cur<<j<<endl;
                ans.push_back(cur);
                recur(j+1,s,ans);
                ans.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>a;
        recur(0,s,a);
        return lans;
    }
};