class Solution {
public:
    vector<vector<int>> graph;
    vector<int>vis , res;
    bool dfs(int node ){
        vis[node] = 1;
        res[node] = 1;
        bool flag = false;
        for(auto it : graph[node]){
            if(!vis[it]){
                flag |= dfs(it);
            }
            else if(res[it]){
                flag = true;
            }
        }
        res[node] = 0;
        return flag;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph.assign(numCourses , {});
        for(auto it : prerequisites){
            int u = it[0] , v = it[1];
            graph[u].push_back(v);
        }
        
        vis.assign(numCourses , 0);
        res = vis;
        
        for(int i = 0 ; i  < numCourses ; i++){
            if(!vis[i]){
                bool cycle = dfs(i);
                if(cycle)return false;
            }
        }
        return true;
        
        
    }
};