class Solution {
public:
    int n ,m,initial;
    void dfs(vector<vector<int>>&image, int x,int y , int color){
        if(x<0 or y<0 or x>=n or y>=m or image[x][y]!=initial)return ;
        
        image[x][y]=color;
        dfs(image,x+1,y,color);
        dfs(image,x-1,y,color);
        dfs(image,x,y+1,color);
        dfs(image,x,y-1,color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        n = image.size();
        m = image[0].size();
        initial = image[sr][sc];
        // dfs(image, sr,sc,color);
        if(initial!=color)dfs(image,sr,sc,color);
        return image;
    }
};