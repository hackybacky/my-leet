class Solution {
public:
    vector<vector<int>>graph;
    vector<int>ans;
    vector<int> dfs(int node , int par ,string & labels){
        vector<int>cur(26 , 0);
        cur[labels[node] - 'a' ]++;
        for(auto it : graph[node]){
            if(it == par)continue;
            auto childv = dfs(it , node , labels);
            for(int i = 0 ; i < 26 ; i++){
                cur[i] += childv[i];
            }
        }
        ans[node] = cur[labels[node] - 'a'];
        return cur;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        graph.assign(n + 1 , {});
        ans.assign(n , -1);
        for(auto it : edges){
            int u = it[0] , v = it[1];
            graph[v].push_back(u);
            graph[u].push_back(v);
        }
        dfs(0 , -1 , labels);
        return ans;
    }
};