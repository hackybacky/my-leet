// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        
        priority_queue<pair<int,int>>pq;
        pq.push({0,0});
        vector<int>dis(V,INT_MAX);
        vector<int>vis(V,0);
        while(!pq.empty()){
            auto t = pq.top();
            pq.pop();
           
            int d = -t.first;
            int v = t.second;
            vis[v]=true;
            for(auto cur:adj[v]){
                if(vis[cur[0]]==0 and cur[1]<dis[cur[0]]){
                    dis[cur[0]]=cur[1];
                    pq.push({-cur[1],cur[0]});
                }
            }
        }
        int su=0;
        for(auto it : dis){
            if(it!=INT_MAX)su+=it;
        }
        return su;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends