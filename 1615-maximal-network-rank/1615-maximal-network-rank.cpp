class Solution {
public:
    vector<vector<int>>graph;
    vector<int>vis;
    vector<int>in;
    int ans = 0;
    void dfs(int node , int &maxi){
        vis[node] = 1;
        maxi =max(maxi , (int)graph[node].size());
        for(auto it : graph[node]){
            ans = max(ans , (int)graph[node].size() + (int)graph[it].size() - 1);
            if(!vis[it]){
                dfs(it , maxi);
            }
        }
    }
    
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        graph.assign(n , vector<int>(n , 0));
        vector<int>indeg(n , 0);
        for(auto it : roads){
            graph[it[0]][it[1]] = 1;
            graph[it[1]][it[0]] = 1;
                  indeg[it[0]]++;
                  indeg[it[1]]++;
        }
        int fans = 0;
        for(int i = 0 ; i < n; i++){
            for(int j = i + 1 ; j < n; j++){
                int ans = indeg[i] + indeg[j];
                if(graph[i][j] == 1)ans--;
                fans = max(fans , ans);
            }
        }
                  return fans;
    }
};