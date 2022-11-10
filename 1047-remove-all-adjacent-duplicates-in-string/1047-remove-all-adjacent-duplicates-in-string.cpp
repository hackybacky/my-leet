class Solution {
public:
    string removeDuplicates(string s) {
        
        stack<char > st;
        
        for(auto it : s){
            char cur = it;
            if(st.empty()){
                st.push(it);
            }
            else{
                char t = st.top();
                if(t == cur){
                    st.pop();
                }
                else{
                    st.push(cur);
                }
            }
        }
        string ans =  "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};