// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    vector<int>color;
    bool ans;
    void recur(int node , vector<int>adj[]){
        
        for(int i=0;i<adj[node].size();i++){
            int cur_node=adj[node][i];
            if(color[cur_node]!=-1){
                if(color[cur_node]^color[node]==0){
                    ans=false;
                    return;
                }
            }
            else{
                color[cur_node]=color[node]^1;
                recur(cur_node,adj);
            }
        }
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    color.assign(V,-1);
	    ans=true;
	    
	    for(int i=0;i<V;i++){
	        if(color[i]==-1){
	            color[i]=0;
	            recur(i,adj);
	        }
	    }
	    return ans;
	}

};

// { Driver Code Starts.
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
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends