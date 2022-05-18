// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    vector<string>ans;
    void recur(string s , int i , string cur){
        if(i==s.size()-1){ans.push_back(cur+s[i]);return;}
        
        // for(int j=i; j<s.size()-1; j++){
            string t = cur;
            
            cur+=s[i];
            cur+=" ";
            recur(s,i+1,cur);
            cur=t+s[i];
            recur(s,i+1,cur);
        
    }
    vector<string> permutation(string S){
        // Code Here
        recur(S,0,"");
        return ans;
    }
};

// { Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}
  // } Driver Code Ends