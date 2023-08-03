class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        for(auto it : num){
            while(!st.empty() and st.top() > it and k){
                st.pop();
                k--;
            }
            st.push(it);
        }
        while(!st.empty() and k){
            st.pop();
            k--;
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin() , ans.end());
        int i = 0;
        while(i < ans.size() and ans[i] == '0'){
            i++;
        }
        ans = string(ans.begin() + i , ans.end());
        return ans.size() == 0 ? "0" : ans;
    }
};