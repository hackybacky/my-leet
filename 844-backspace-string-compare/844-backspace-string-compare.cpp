class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        stack<char> st;
        stack<char> ss;
        int i=0,j=0;
        
        while(i<s.size() or j<t.size()){
            if(i<s.size())
                if(s[i]=='#'){
                    i++;
                    if(ss.empty())continue;
                    ss.pop();
                    
                }
                else ss.push(s[i]),i++;
            if(j<t.size())
                  if(t[j]=='#'){
                      j++;
                    if(st.empty())continue;
                    st.pop();
                    
                }
                else st.push(t[j]),j++;
  
        }
        while(!st.empty() and !ss.empty()){
            if(st.top()!=ss.top()){cout<<st.top()<<" "<<ss.top();return false;}
            else st.pop(),ss.pop();
        }
        
        return st.empty() and ss.empty();
    }
};