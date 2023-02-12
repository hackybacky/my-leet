class Solution {
public:
    vector<vector<int>> lans;
    void generate(vector<int>&nums , int i , vector<int>&ans){
            lans.push_back(ans);
        if(i == nums.size())
            return;
    
        // lans.push_back(ans);
        for(int j = i ; j  < nums.size() ; j++){
            if(i != j and nums[j] == nums[j - 1])continue;
            ans.push_back(nums[j]);
            generate(nums , j + 1 , ans);
            ans.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>ans;
        sort(nums.begin() , nums.end());
        generate(nums , 0 , ans);
        return lans;
    }
};