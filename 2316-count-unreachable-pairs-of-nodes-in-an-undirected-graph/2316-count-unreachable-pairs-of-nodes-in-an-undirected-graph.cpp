class Solution {
public:
    vector<vector<int>>graph;
    vector<int>vis;
    int sz;
    void dfs(int node){
        vis[node]=1;
        sz++;
        // cout<<node<<endl;
        for(auto it : graph[node]){
            if(vis[it]==0){
                dfs(it);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        graph.assign(n+4,{});
        vis.assign(n+4,0);
        for(auto it:edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                sz=0;
                dfs(i);
                ans+=(long long)sz*(long long)(n-sz);
            }
        }
        return ans/2;
        
        
    }
};