class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        stack<int > st;
        int n = s.size();
        vector<int> r;
        for(int i=0; i< n;  i++){
            if(s[i]=='('){
                st.push(i);
            }    
            else if(s[i]==')'){
                if( !st.empty() )st.pop();
                else r.push_back(i);
            }
        }
        while(!st.empty()){
            r.push_back(st.top());
            st.pop();
        }
        
        sort(r.begin(),r.end());
        int j=0;
        string ans="";
        for(int i=0; i<n; i++){
            if(j<r.size() and i==r[j]){
                j++;
                continue;
            }
            else ans+=s[i];
        }
        return ans;
    }
};