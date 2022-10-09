class Solution {
public:
        map<char , int > mp;
    char c (){
        for(auto it : mp){
            if(it.second != 0){
                return it.first;
            }
        }
        return 'a';
    }
    string robotWithString(string s) {
        int n = s.size();
        string ans = "";
        stack<char > st;
        for(auto it : s){
            mp[it]++;
        }
        int cur = 0;
        for(int i = 0 ; i < n ; i++){
            st.push(s[i]);
            mp[s[i]]--;
            while(!st.empty()  and st.top() <= c()){
                ans += st.top();
                
                st.pop();
            
            }
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};