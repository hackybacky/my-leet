class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
         vector<int> x = {1, -1, 0, 0};
            vector<int> y = {0, 0, 1, -1};   
        priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>> pq;
        
        pq.push({0,0,0});
        int n = heights.size(),m=heights[0].size();
        vector<vector<int>>mp(n+1,vector<int>(m+1,INT_MAX));
        int ans=INT_MAX;
        while(!pq.empty()){
            auto it = pq.top();
            int curx = it[1];
            int cury = it[2];
            int curd = it[0];
            pq.pop();
            if(curx==n-1 and cury==m-1){
                ans=min(ans,curd);
                break;
            }
            for(int i=0; i<4; i++){
                int nx = curx+x[i];
                int ny = cury+y[i];
                if(nx<0 or ny<0 or nx>=n or ny>=m)continue;
                int c = abs(heights[curx][cury]-heights[nx][ny]);
                c=max(c,curd);
                if(mp[nx][ny]<=c)continue;
                mp[nx][ny]=c;
                pq.push({c,nx,ny});
                
            }
        }
        return ans;
    }
};