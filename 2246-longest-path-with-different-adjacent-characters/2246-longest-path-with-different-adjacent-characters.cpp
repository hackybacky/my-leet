class Solution {
public:
    vector<int>dis;
    vector<vector<pair<int,char>>>graph;
    int ans;
    
    int dfs(int node , int par,char c){
        multiset<int>v;
        for(auto child :graph[node]){
            if(child.first==par)continue;
            
            if(c==child.second){
                dfs(child.first,node, child.second);
                continue;
            }
            int cur = dfs(child.first,node, child.second);
            v.insert(cur+1);
            if(v.size()>2)v.erase(v.begin());
        }
        int su=0,maxi=0;
        for(auto it :v){
            su+=it;
            maxi=max(maxi,it);
        }
        ans=max(ans,su);
        return maxi;
    }
    int longestPath(vector<int>& parent, string s) {
        int n = s.size();
        dis.assign(n+10,0);
        graph.resize(n+1,{});
        for(int i=1;i<parent.size();i++){
            graph[parent[i]].push_back({i,s[i]});
            graph[i].push_back({parent[i],s[i]});
        }
        dfs(0,-1,s[0]);
        return ans+1;
    }
};