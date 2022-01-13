class Solution {
public:
    bool check(string s){
        stack<char> st;
        
        for(auto it : s){
            if(it=='(')st.push(it);
            else if(!st.empty())st.pop();
            else return false;
        }
        
        return st.empty();
    }
    vector<string > s;
    void generate(int i,int j , string ans){
        if(i==0 and j==0){
            s.push_back(ans);
        }
        if(i<0)return ;
        if(j<0)return ;
        generate(i-1,j,ans+'(');
        generate(i,j-1,ans+')');
    }
    vector<string> generateParenthesis(int n) {
        //string p;
        generate( n, n ,"");
        vector<string> ans;
        for(auto it : s){
            if(check(it)){
                ans.push_back(it);
            }
        }
        return ans;
    }
};