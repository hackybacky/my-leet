class Solution {
public:
        vector<vector<int>>graph;
    vector<bool>visited;
    pair<int,int> ans;
    bool flag=false;
    void dfs(int child ,int par){
        visited[child]=true;
        for(auto it : graph[child]){
            if(visited[it] and it!=par){
                flag=true;return;
            }
            if(it!=par)
            dfs(it,child);
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        
        graph.assign(n+1,{});
        for(int i=0; i< n ; i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
            visited.assign(n+1,false);
            dfs(edges[i][0],edges[i][1]);
            if(flag)return {edges[i][0],edges[i][1]};
        }
        return {};
    }
};