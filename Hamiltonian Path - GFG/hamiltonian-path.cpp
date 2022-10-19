//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<vector<int >> graph;
    bool ans = false;
    int n;
    void dfs(vector<int>&vis , int node , int start ){
        // cout << vis[0] << endl;
        if(vis.size() == n){
            // if(find(graph[node].begin() , graph[node].end() , 1) != graph[node].end() ){
            //     ans = true;
            // }
            ans = true;
            return;
        }
        
        for(auto it : graph[node]){
            if(find(vis.begin() , vis.end() , it) == vis.end())
            vis.push_back(it),
            dfs(vis ,it , start),
            
            vis.pop_back();
        }
    }
    bool check(int N,int M,vector<vector<int>> Edges)
    {
        // code here
        ans = false;
        n = N;
        graph.assign(N + 1, {});
        for(auto it : Edges){
            int a = it[0] , b = it[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        vector<int>vis;
        for(int i = 1 ; i <= N  ;i++){
        vis.push_back(i);
            // cout << vis[0] << endl;
           dfs(vis , i , i);
            vis.pop_back();
        }
        return ans;
        
    }
};
 

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}
// } Driver Code Ends