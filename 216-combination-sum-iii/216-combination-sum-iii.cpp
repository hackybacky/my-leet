class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int>>ans;
        
        for(int mask=1 ; mask<(1<<10) ; mask++){
            int set = __builtin_popcount(mask);
            if(set!=k)continue;
            int su=0;
            vector<int>cur;
            for(int j=1; j<11; j++){
                if(mask&(1<<j))su+=j,cur.push_back(j);
            }
            if(su==n and cur.size()==k)ans.push_back(cur);
        }
        
        return ans;
    }
};