class Solution {
public:
    vector<string>ans;
    map<string,multiset<string>>graph;
   void dfs(string node){
        
        while( !graph[node].empty()){
            
            auto cur = *(graph[node].begin());
            graph[node].erase(graph[node].begin());
            dfs(cur);
        }
        ans.push_back(node);
    }
    vector<string> findItinerary(vector<vector<string>>& t) {
        
        for(auto it : t){
            graph[it[0]].insert(it[1]);
        }
        
        dfs("JFK");
        reverse(ans.begin(),ans.end());
        return ans;
        
        
    }
};