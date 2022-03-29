class Solution {
public:
    void dfs(vector<vector<int>> &graph , int node ,map<int,int>& cur ,vector<int>&visited ,vector<int>&dis ){
        
        visited[node]=1;
        for(auto it : graph[node]){
            
            
            if(visited[it]==0 and cur.find(it)!=cur.end() ){
                
                dis[it]=dis[node]+1;
                dfs(graph,it,cur ,visited,dis);
            }
        }
        
    }
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> graph(n+1);
        for(auto it : edges){
            graph[it[1]].push_back(it[0]);
            graph[it[0]].push_back(it[1]);
        }
        vector<int>ans(n-1,0);
        for(int mask=0;mask<(1<<n) ; mask++){
            map<int,int>cur;
            for(int i=0; i<=n; i++){
                if(((1<<i)&mask))cur[i+1]=1;
            }
            // for(auto it : cur)cout<<it<<" c ";
            // cout<<endl;
            if(cur.size()<2)continue;
            int lans =0;
            for(auto it : cur){
                vector<int>visited(16,0);
            
                vector<int>dis(16,0);
                

                dfs(graph,it.first,cur,visited,dis);
              //  for(auto it : dis)cout<<it<<" d ";
                //cout<<cur.size()<<" "<<cur[0]<<endl;
                bool flag=true;
                for(auto it2 : cur){if(visited[it2.first]==0){flag=false;break;}}
//                 vector<int>c={2,3,4};
//                 if(c==cur){
//                      for(auto it2 : cur)cout<<visited[it2]<<" ";
                    
//                 }
                                    if(!flag)continue;
                //cout<<endl;
                int maxi = *(max_element(dis.begin(),dis.end()));
                lans=max(lans,maxi);
                
            }   
            if(lans>0){
                
                ans[lans-1]++;
               
            }
        }
        return ans;
    }
    
};