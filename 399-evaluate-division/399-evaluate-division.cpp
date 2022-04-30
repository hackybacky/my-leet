class Solution {
public:
    map<string,vector<pair<string,double>>>graph;
    double ans;
    double dfs(string node , string reach , map<string,bool >&visited){
        visited[node]=true;
        if(node ==reach and graph.find(node)!=graph.end() )return 1;
        for(auto it : graph[node]){
            if(it.first==reach)return it.second;
        }
        
        for(auto it : graph[node]){
            if(visited.find(it.first)==visited.end()){
                
                double t =dfs(it.first,reach,visited);
                if(t!=0)
                return (it.second*t);
                
            }
           // else continue;
        }
        return 0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
       
        
        int n = equations.size();
        
        for(int i=0; i<n; i++){
            graph[equations[i][0]].push_back({equations[i][1],values[i]});
            graph[equations[i][1]].push_back({equations[i][0],1/values[i]});
        }
        
        vector<double>anss;
        for(auto it : queries){
            map<string,bool >visited;
            
            double d= dfs(it[0],it[1],visited);
            // auto d=ans;
            
            if(d!=0)
            anss.push_back(d);
            else anss.push_back(-1);
        }
        return anss;
        
    }
};