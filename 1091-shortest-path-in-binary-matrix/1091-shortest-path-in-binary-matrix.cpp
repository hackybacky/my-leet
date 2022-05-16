class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        priority_queue<pair<int,pair<int,int>>>pq;
        if(grid[0][0]==1)return -1;
        pq.push({-1,{0,0}});
        int n = grid.size();
        vector<vector<int>>dis(n,vector<int>(n,INT_MAX));
        dis[0][0]=1;
        while(!pq.empty()){
            auto tp = pq.top();
            
            pq.pop();
            int d = -(tp.first);
            int x = tp.second.first;
            int y = tp.second.second;
            for(int i=-1;i<2;i++){
                for(int j=-1;j<2;j++){
                    int nx = x + i;
                    int ny = y + j;
                    if(nx<0 or ny<0 or nx>=n or ny>=n or grid[nx][ny]==1)continue;
                    // cout<<nx<<" "<<ny<<" "<<d+1<<endl;
                    if(dis[nx][ny]>d+1){
                        dis[nx][ny]=d+1;
                        pq.push({-dis[nx][ny],{nx,ny}});
                    }
                }
            }
        }
        return dis[n-1][n-1]==INT_MAX?-1:dis[n-1][n-1];
    }
};