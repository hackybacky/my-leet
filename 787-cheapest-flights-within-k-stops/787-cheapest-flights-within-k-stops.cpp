class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        
        queue<vector<int>> q;
        q.push({src,0,0});
        vector<vector<pair<int,int>>> graph(n+12);
        
        for(auto it : flights){
            graph[it[0]].push_back({it[1],it[2]});
         //   graph[it[1]].push_back({it[0],it[2]});
        }
        vector<int> dis(n+10,INT_MAX);
        dis[src]=0;
        int ans = INT_MAX;
        while(!q.empty()){
            auto  it = q.front();
            int node = it[0];
            int k = it[1];
            int d= it[2];
            q.pop();
            for(auto it : graph[node] ){
                if(dis[it.first]>d+it.second){
                   dis[it.first]=d+it.second;
                   // cout<<node <<" "<<k<<endl;
                   q.push({it.first, k+1 , dis[it.first] }) ;
                   if(it.first==dst and k<=K) ans=min(ans,dis[dst]);
                }
            }
        }
        //cout<<par[dst]<<endl;
        if(ans==INT_MAX)return -1;
        return ans;
    }
};