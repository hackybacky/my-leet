// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    vector<vector<int>>graph;
    int ans;
    void dfs(int node,vector<int>&visited,int d){
        if(node==d){
            ans++;
            return;
        }
        
        for(auto it : graph[node]){
            if(visited[it]==0){
                visited[it]=1;
                dfs(it,visited,d);
                visited[it]=0;
            }
        }
    }
	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	    // Code here
	    graph.assign(n+1,{});
	    for(auto it :edges){
	        int a = it[0];
	        int b = it[1];
	        graph[a].push_back(b);
	        
	    }
	    ans=0;
	    vector<int>visited(n+1,0);
	    visited[s]=1;
	    dfs(s,visited,d);
	    return ans;
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, s, d;
		cin >> n >> m >> s >> d;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			edges.push_back({u,v});
		}
		Solution obj;
		int ans = obj.possible_paths(edges, n, s, d);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends