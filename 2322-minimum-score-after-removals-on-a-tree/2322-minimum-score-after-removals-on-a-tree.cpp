class Solution {
public:
    vector<int>dis;
    vector<vector<int>>graph;
    vector<int>vis;
    vector<int>tin,tout;
    int cnt;
    
   
    
    void dfs(int node,vector<int>&nums){
        vis[node]=1;
        tin[node]=cnt++;
        dis[node]=nums[node];
        for(auto it : graph[node]){
            if(vis[it]==0){
                dfs(it,nums);
                dis[node]^=dis[it];
            }
        }
        tout[node]=cnt++;

    }
     bool isAncestor(int u, int v) {
        return tin[u]<=tin[v]&&tout[v]<=tout[u];
    }
    
    
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        graph.assign(n+1,{});
        dis.assign(n,0);
        vis.assign(n+1,0);
        tin.assign(n+1,0);
        tout=tin;
        for(auto it :edges){
            int a = it[0],b=it[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        cnt=0;
        dfs(0,nums);
        int ans = INT_MAX;
        
        for(int u=1;u<n;u++){
            for(int v=u+1;v<n;v++){
                int i=u, j=v;
                if(isAncestor(i,j) or isAncestor(j,i) ){
                    if(isAncestor(j,i))swap(i,j);
                    int a = dis[j];
                    int b = dis[i]^dis[j];
                    int c = dis[0]^dis[i];
                    // cout<<i<<" "<<j<<" "<<a<<" a "<<b<<" "<<c<<endl;
                    ans=min(ans,max({a,b,c})-min({a,b,c}));
                    
                }
                else{
                    int a = dis[i];
                    int b = dis[j];
                    int c = dis[0]^a^b;
                    // cout<<i<<" "<<j<<" "<<a<<" "<<b<<" "<<c<<endl;
                    ans=min(ans,max({a,b,c})-min({a,b,c}));
                }
                // cout << ans << endl;
            }
        }
        cout<<isAncestor(0,1)<<endl;
       
        return ans;
        
    }
};