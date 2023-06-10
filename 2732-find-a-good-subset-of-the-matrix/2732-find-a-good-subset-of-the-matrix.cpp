class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        map<int , int > mp;
        int m = grid[0].size();
        for(int i = 0 ; i < n ;i++){
            int cur = 0;
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1)
                   cur +=  (1 << j);
            }
            
            if(cur == 0)return {i};
            for(int j = 0 ; j < (1 << m); j++){
                if( (j & cur) == 0 and mp[j] ){
                    return {mp[j] - 1 , i};
                }
            }
            mp[cur] = i + 1;
        }
        return {};
    }
};