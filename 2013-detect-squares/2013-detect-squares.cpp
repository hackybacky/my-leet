class DetectSquares {
public:
    int dp[1001][1001];
    DetectSquares() {
        memset(dp,0,sizeof(dp));
    }
    
    void add(vector<int> point) {
        dp[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        
        int x = point[0],y = point[1];
        int ans=0;
        for(int curx=0;  curx<=1000; curx++){
            if(x!=curx and dp[curx][y]){
                
                int siz = curx-x;
                if(y+siz<=1000 and y+siz>=0)
                ans+=dp[curx][y+siz]*dp[x][y+siz]*dp[curx][y];
                if(y-siz<=1000 and y-siz>=0){
                    ans+=dp[curx][y-siz]*dp[x][y-siz]*dp[curx][y];
                }
                
            }
        }
        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */