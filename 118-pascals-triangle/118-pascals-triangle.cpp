class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> ans(numRows);
        ans[0].resize(1,1);
        for(int i=1; i<numRows; i++){
            ans[i].resize(i+1,0);
            for(int j=0; j<= i; j++){
                // if(i-1>=0)
                if(j<i)
                 ans[i][j]=ans[i-1][j];
                if(j-1>=0)
                 ans[i][j]+=ans[i-1][j-1];
                
            }
        }
        return ans;
    }
};