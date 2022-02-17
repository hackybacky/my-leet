class Solution {
public:
    vector<int> smallestMissingValueSubtree(vector<int>& p, vector<int>& a) {
        int n=p.size();
        vector<vector<int>> graph(n+1);
        int node=0;
        for(int i=0; i<n; i++){
            graph[i].push_back(p[i]);
            if(p[i]!=-1)
                graph[p[i]].push_back(i);
            if(a[i]==1)node=i;
        }
        vector<bool>visited(n+2,false);
        function<void(int ,int)> dfs=[&](int child,int par){
            visited[a[child]]=true;
            //cout<<a[child]<<endl;
            for(auto it : graph[child]){
                if(it!=par and !visited[a[it]]){
                    dfs(it,child);
                }
            }
        };
        int ans=1;
        vector<int>an(n,1);
        //cout<<node<<endl;
        while(node!=-1){
            dfs(node,p[node]);
            while(visited[ans])ans++;
            an[node]=ans;
            node=p[node];
        }
        return an;
    }
};