// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int partyHouse(int N, vector<vector<int>> &adj){
        // code here
        // vector<int>dis(N+1,-1);
      //  for(auto it :adj[1])cout<<it<<endl;
      int ldis=0;
        function<void(int,int,int)>dfs=[&](int node,int par,int dis){
        //  cout<<"hello"<<endl;
        // cout<<node<<endl;
        //  if(node==0)cout<<"d"<<endl;
          for(auto it : adj[node])  {
            
            
               
              if(it!=par){
                  
                //   dis[it]=dis[node]+1; 
                ldis=max(ldis,dis+1);
                  dfs(it,node,dis+1);
              }
          }
        };
        int ans = INT_MAX;
//dfs(1,-1);
        for(int i=1; i<=N; i++){
            ldis=0;
            dfs(i,-1,0);
            // for(auto it:dis)cout<<it<<" ";
            // cout<<endl;
        //    cout<<(*(max_element(dis.begin(),dis.end())))<<endl;
            ans=min(ans,ldis);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, x, y;
        cin>>N;
        vector<vector<int>> adj(N+1);
        for(int i = 0;i < N-1;i++){
            cin>>x>>y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        
        Solution ob;
        cout<<ob.partyHouse(N, adj)<<"\n";
    }
    return 0;
}  // } Driver Code Ends