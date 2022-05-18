class Solution {
public:
    vector<vector<int>>graph;
    vector<vector<int>>ans;
    vector<int>par;
    vector<int> visited;
    int timer=1;
    vector<int>low,dis;
    void dfs(int u ){
        visited[u]=1;
        low[u]=dis[u]=timer++;
        for(auto v : graph[u] ){
            if(visited[v]==0){
                par[v]=u;
                
                dfs(v);
                // cout<<"hello"<<" "<<low[u]<<" "<<low[v]<<endl;
                low[u]=min(low[u],low[v]);
                if(low[v]>dis[u]){
                    ans.push_back({u,v});
                }
            }
            else if( v!=par[u])low[u]=min(low[u],dis[v]);
        }
        
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        graph.assign(n+1,{});
        par.assign(n+1,-1);
        visited.assign(n+1,0);
        low=dis=visited;
        for(auto it: connections){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        
        dfs(0);
        return ans;
    }
};