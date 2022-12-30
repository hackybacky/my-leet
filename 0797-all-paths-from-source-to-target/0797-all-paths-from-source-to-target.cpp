class Solution {
public:
    
    vector<vector<int>> fans;
    int last;
    void dfs(int node , vector<int>&ans , vector<vector<int>>&graph , vector<int>&vis){
        vis[node] = 1;
        ans.push_back(node);
        for(auto it : graph[node]){
            if(!vis[it]){
                dfs(it , ans , graph , vis);
            }
        }
        vis[node] = 0;
        if(node == last)fans.push_back(ans);
        ans.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<int>ans;
        last = graph.size() - 1;
        vector<int>vis;
        vis.assign(last + 1, 0);
        dfs(0 , ans , graph , vis);
        return fans;
    }
};