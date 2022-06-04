class Solution {
public:
    vector<int> x = {1, -1, 0, 0};
    vector<int> y = {0, 0, 1, -1};
    int orangesRotting(vector<vector<int>>& grid) {
        
        priority_queue<pair<int,pair<int,int>>>q;
        
        int n = grid.size();
        int m = grid[0].size();
        int ans=0;
        int cnt=0;
        vector<vector<int>>dis(n,vector<int> (m,INT_MAX));
        for(int i=0 ;i<n ;i++)for(int j=0 ; j<m ;j++){if(grid[i][j]==2)q.push({0,{i,j}}),dis[i][j]=0;
                                                      if(grid[i][j]==1)cnt++;}
        int curv=0;
        while(!q.empty()){
            auto t= q.top();
            q.pop();
            int d = abs(t.first);
            
            int cx = t.second.first;
            int cy= t.second.second;
            // cout<<cx <<" "<<cy << " " << d <<endl;
            ans=max(ans,d);
            for(int i=0;i<4; i++){
                int nx = cx+x[i];
                int ny = cy+y[i];
                if(nx<0 or ny<0 or  nx>=n or ny>=m or grid[nx][ny]==0 or grid[nx][ny]==2 )continue;
                int curd = d+1;
                if(dis[nx][ny]>curd){q.push({-curd,{nx,ny}});dis[nx][ny]=curd;curv++;}
                
            }
        }
        
        if(curv!=cnt)return -1 ;
        return ans;
        
    }
};