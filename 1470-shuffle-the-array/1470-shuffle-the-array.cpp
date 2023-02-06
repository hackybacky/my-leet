class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>ans;
        
        for(int i = n ; i < 2 * n ; i++){
            ans.push_back(nums[i - n] );
            ans.push_back(nums[i]);
        }
        return ans;
    }
};