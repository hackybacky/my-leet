#define vl vector<int> 
class Solution {
public:
     vl x = {1, -1, 0, 0};
        vl y = {0, 0, 1, -1};

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        int sx= entrance[0],sy= entrance[1];
        
        queue<vector<int>> q;
        q.push({sx,sy,0});
        int n = maze.size();
        int m = maze[0].size();
        while(!q.empty()){
            auto v = q.front();
            q.pop();
            int cx = v[0],cy= v[1];
            if((cx==0 or cy==0 or cx==n-1 or cy==m-1 ) and (cx!=sx or cy!=sy)){
                
                    return v[2];
            }
            for(int i=0; i<4; i++){
                int nx = cx+x[i],ny= cy+y[i];
                if(nx<0 or ny<0 or nx>=n or ny>=m or maze[nx][ny]=='+')continue;
                maze[nx][ny]='+';
                q.push({nx,ny,v[2]+1});
            }
            
        }
        return -1;
    }
};