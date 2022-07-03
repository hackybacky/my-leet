// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    map<string, bool>mp;
    vector<string>ans;
    void backtrack(int i ,string& s , string &cur , string &a ){
        if(i==s.size()){
            if(mp[cur]){
                if(a.size())ans.push_back(a+' '+cur);
                else ans.push_back(cur);
            }
            return ;
        }
        cur=cur+s[i];
        if(mp[cur]){
            string b;
            if(a.size()>0 and cur.size())
             b=a+' '+cur;
            else b =cur;
            string e="";
            backtrack(i+1,s,e,b);
        }
        backtrack(i+1,s,cur,a);
    }
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        // code here
        for(auto it: dict)mp[it]=true;
        string d="";
        string e="";
        backtrack(0,s,e,d);
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends