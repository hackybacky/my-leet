class Solution {
public:
    vector<int> x = {1, -1, 0, 0};
vector<int> y = {0, 0, 1, -1};
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>dis(n,vector<int>(n,INT_MAX));
        
        
        priority_queue<pair<int,pair<int,int>>>pq;
        pq.push({-grid[0][0],{0,0}});
        dis[0][0]=0;
        while(!pq.empty()){
            auto t = pq.top();
            pq.pop();
            int d=-t.first;
            int cx = t.second.first;
            int cy = t.second.second;
            // cout<<d<<endl;
            for(int k=0 ;  k< 4 ; k++){
                int nx = cx+x[k];
                int ny = cy +y[k];
                
                if(nx<0 or ny<0 or nx>=n or ny >=n)continue;
                
                int curd = max(d,grid[nx][ny]);
//                 if(abs(gap)>d){
//                     curd+=abs(gap);
                    
//                 }
                if(curd<dis[nx][ny])dis[nx][ny]=curd,pq.push({-curd,{nx,ny}});
            }
        }
        return dis[n-1][n-1];
    }
};