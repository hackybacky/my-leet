class Solution {
public:
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> lans;
        int n=nums.size();
        for(int mask=0; mask< (1<<n); mask++){
            
            vector<int>ans;
            for(int j=0; j<n; j++){
                if((1<<j)&mask){
                    ans.push_back(nums[j]);
                }
            }
            lans.push_back(ans);
        }
        
        return lans;
    }
};