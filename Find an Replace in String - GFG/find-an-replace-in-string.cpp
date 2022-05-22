// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    string findAndReplace(string S ,int Q, int index[], string sources[], string targets[]) {
        // code here
        int n = S.size();
        vector<int>vc;
        for(int i=0; i<Q ; i++ ){
            
            int j=index[i];
            int k=0;
            while(j<n and S[j]==sources[i][k])j++,k++;
            if(k==sources[i].size()){
                vc.push_back(i);
            }
        }
        
        for(int i=vc.size()-1;i>=0; i--){
            auto it = vc[i];
            int sindi = index[it];
            string s = targets[it];
            int siz = sources[it].size();
            S=S.substr(0,sindi)+s + S.substr(sindi+siz);
           // cout<<S<<endl;
        }
        return S;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        
        int Q;
        cin>>Q;
        int index[Q];
        string sources[Q], targets[Q];
        
        for(int i=0; i<Q; i++)
            cin>>index[i];
        for(int i=0; i<Q; i++)
            cin>>sources[i];
        for(int i=0; i<Q; i++)
            cin>>targets[i];

        Solution ob;
        cout<<ob.findAndReplace(S,Q,index,sources,targets)<<endl;
    }
    return 0;
}  // } Driver Code Ends