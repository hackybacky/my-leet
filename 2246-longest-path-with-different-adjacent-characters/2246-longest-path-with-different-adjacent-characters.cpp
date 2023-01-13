class Solution {
public:
    vector<vector<int>> graph;
    int ans = 0;
    int dfs(int node , int par , string & s){
        int cur = 1;
        int a = 0 , b = 0;
        for(auto it : graph[node]){
            if(it == par)continue;
            int dis_child = dfs(it , node , s);
            if(s[it] != s[node]){
                cur = max(cur , dis_child + 1);
                if(dis_child > a)b = a , a= dis_child ;
                else if(dis_child > b)b = dis_child;
            }
        }
        // cout << node << "a "<< a << " b " << b << endl;
        ans = max(ans ,a + b + 1);
        ans = max(ans , cur);
        return cur;
    }
    int longestPath(vector<int>& parent, string s) {
        int n = s.size();
        graph.assign(n , {});
        for(int i = 1 ; i < n ; i++){
            graph[i].push_back(parent[i]);
            graph[parent[i]].push_back(i);
        }
        dfs(0 , -1 , s);
        return ans;
    }
};