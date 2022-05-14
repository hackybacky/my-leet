class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        priority_queue<pair<int,int>>pq;
        vector<vector<pair<int,int>>> graph(n+10);
        for(auto it : times){
            graph[it[0]].push_back({it[1],it[2]});
        }
        
        pq.push({0,k});
        vector<int>dis(n+1,INT_MAX);
        dis[k]=0;
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            
            auto edge = top.second;
            auto w = -top.first;
           
            for(auto it : graph[edge]){
                int nd = w+it.second;
                
                if(dis[it.first]>nd){pq.push({-nd ,it.first});dis[it.first]=nd;}
            }
        }
        auto it = *max_element(dis.begin()+1,dis.end());
        
        return it==INT_MAX?-1:it;
    }
};