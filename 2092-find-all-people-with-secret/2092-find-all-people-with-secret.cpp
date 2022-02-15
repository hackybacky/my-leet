class Solution {
public:
    static bool cmp(vector<int> &v1, vector<int> &v2){
        return v1[2]<v2[2];
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& mt, int f) {
        int m=mt.size();
        vector<vector<pair<int,int>>> graph(n+2);
       
        for(int i=0; i< m ; i++){
            int a=mt[i][0],b=mt[i][1],w=mt[i][2];
            graph[a].push_back({b,w});
            graph[b].push_back({a,w});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        vector<bool > visited(n+1,false);
        
        q.push({0,0});
        q.push({0,f});
        while(!q.empty()){
            auto fr=(q.top());
            int node =fr.second;
            q.pop();
            if(visited[node])continue;
            int time =fr.first;
            
             visited[node]=true;
            for(auto it :graph[node]){
                if(it.second>=time){
                    q.push({it.second,it.first});
                   
                }
            }
        }
        vector<int>ans;
        for(int i=0; i<=n; i++)if(visited[i])ans.push_back(i);
        return ans;
    }
};