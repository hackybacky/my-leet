class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int , int > mp;
        int i=0;
        for(auto it: nums){
            mp[it]=i++;
        }
        
        
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(mp[target-nums[i]]>0 and i!=mp[target-nums[i]]){ans.push_back(i),ans.push_back(mp[target-nums[i]]);break;}
        }
        return ans;
    }
};