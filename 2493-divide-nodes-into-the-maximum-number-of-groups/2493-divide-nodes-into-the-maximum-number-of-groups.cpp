class Solution {
public:
    
    vector<vector<int>> graph;
    vector<int>cur;
    bool check(int node , vector<int> &color , int c){
        color[node] = c;
        cur.push_back(node);
        int ans = true;
        for(auto it : graph[node]){
            if(color[it] == -1){
                ans &= check(it , color , c ^ 1);
            }
            else{
                int current = color[it];
                if(current == c){
                    return false;
                }
            }
            
        }
        return ans;
    }
    vector<vector<int>> dis;
    void bfs(int source){
        
        queue<pair<int , int >> q;
        q.push({source , 0});
        dis[source][source] = 0;
        while(!q.empty()){
            auto f = q.front();
            int d = f.second;
            q.pop();
            int node = f.first;
            for(auto it : graph[node]){
                int ndis = d + 1;
                if(dis[source][it] > ndis){
                    dis[source][it] = ndis;
                    q.push({it , ndis});
                }
            }
        }
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        graph.assign(n + 1, {});
        for(auto it : edges){
            int a = it[0] , b = it[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        vector<int>color(n + 1, -1);
     
        dis.assign(n + 1, vector<int>(n + 1, INT_MAX));
        for(int i = 1 ;i <= n ; i++){
            bfs(i);
        }
        int fans = 0;
        
        for(int  i = 1 ;i <= n ;i++ ){
            if(color[i] == -1){
                cur.clear();
                bool flag = check(i,  color , 0);
                if(!flag){
                    return -1;
                }
                int ans = INT_MIN;
                for(auto it : cur){
                    for(auto it2 : cur){
                        ans = max(ans , dis[it][it2]);
                    }
                }
                fans += ans + 1;
            }
        }
        return fans ;
    }
};