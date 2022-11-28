class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2);
        
        map<int,int> cur;
        set<int>player;
        for(auto i : matches){
            
                player.insert(i[0]);
                player.insert(i[1]);
                cur[i[1]]++;
            
        }
        
        for(auto it : player){
            if(cur[it]==0){
                ans[0].push_back(it);
            }
            else if(cur[it]==1){
                ans[1].push_back(it);
            }
        }
        return ans;
    }
};