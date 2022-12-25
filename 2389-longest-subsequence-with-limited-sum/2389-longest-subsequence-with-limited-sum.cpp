class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        for(auto it : queries){
            int su=0;
            int i=0;
            while(i<nums.size() and su+nums[i]<=it)su+=nums[i],i++;
            ans.push_back(i);
        }
        return ans;
    }
};