class Solution {
public:
    string makeGood(string s) {
        stack<char > st;
        int n = s.size();
        for(int i = 0 ; i < n ; i++){
            
            if(st.empty()){
                st.push(s[i]);
            }
            else{
                char c = st.top();
                char cur = s[i];
                if( (tolower(c) == cur and isupper(c)) or (islower(c) and toupper(c) == cur)){
                    st.pop();
                }
                else st.push(cur);
            }
        }
        
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};