class Solution {
public:
    vector<vector<int>> graph;
    int cnt = 0;
    int ans = 0;
    int dfs(int node , int par , int dis ,vector<bool>& hasApple){
        
        int cnt = 0 ;
        for(auto it : graph[node]){
            if(it == par)continue;
            cnt += dfs(it , node , dis + 1 , hasApple);    
        }
        if(hasApple[node ] ){
            ans +=2 * dis;
            cnt++;
        }
        if(cnt > 1){
            ans -=(cnt - 1) *2 * dis;
        }
        // if(hasApple[node] and cnt == 1)ans += dis;
        return cnt >= 1 ;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        graph.assign(n + 1  , {});
        
        for(auto it : edges){
            int u = it[0] , v = it[1];
            graph[v].push_back(u);
            graph[u].push_back(v);
        }
        int lans = dfs(0 , -1 , 0 , hasApple);
        return ans ;
    }
};