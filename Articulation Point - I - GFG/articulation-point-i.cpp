//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<int> tin , low;
    int timer = 0;
    vector<int>ans;
    void dfs(int node , int par , vector<int>adj[] ){
        tin[node] = low[node] = timer++;
        int child = 0;
        
        for(auto it : adj[node]){
            if(it == par)continue;
            if(tin[it] != -1){
                low[node] = min(low[node] , tin[it]);
            }
            else{
                dfs(it , node , adj);
                low[node] = min(low[node] , low[it]);
                if(low[it] >= tin[node] and par != -1){
                    ans.push_back(node);
                }
                child++;
            }
        }
        if(par == - 1 and child > 1){
            ans.push_back(node);
        }
        
    }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        ans.clear();
        tin.assign(V , -1);
        low = tin;
        for(int i = 0 ; i < V ; i++){
            if(tin[i] == -1){
                timer = 0;
                dfs(i, -1 , adj );
            }
        }
        set<int>s(ans.begin() , ans.end());
        ans = vector<int>(s.begin() , s.end());
        if(ans.size() == 0){
            return {-1};
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends