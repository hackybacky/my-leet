class Solution {
public:
    bool ans;
void check(int node , vector<vector<int>>&graph,vector<int>&color){
        
        for(auto it : graph[node]){
            if(color[it]==-1){
                color[it]=color[node]^1;
                check(it,graph,color);
            }
            else{
                if(color[it]==color[node]){
                    ans=false;
                    return ;
                }
            }
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        ans=true;
        vector<int>color(graph.size()+1,-1);
        for(int i=0; i<graph.size();i++){
            if(color[i]==-1)
            check(i,graph,color);
        }
        
        
        return ans;
    }
};