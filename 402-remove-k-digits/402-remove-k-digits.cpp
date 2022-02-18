class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        
        for(auto it : num){
            while(!s.empty() and it<s.top() and k){
                s.pop();
                k--;
            }
            s.push(it);
        }
        
        while(!s.empty() and k){
            s.pop();
            k--;
        }
        
        string ans="";
        while(!s.empty()){
            ans+=s.top();
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        int i=0;
        while(i<ans.size() and ans[i]=='0')i++;
        ans=string(ans.begin()+i,ans.end());
        if(ans.size()==0)return "0";
        return ans;
    }
};