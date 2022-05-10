class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(),nums.end());
        int ans = 0;
        for(auto it : nums){
            if(s.find(it-1)!=s.end())continue;
            int j=1;
            while(s.find(it+j)!=s.end())j++;
            ans=max(ans,j);
        }
        return ans;
     //   for(auto it : nums)mp[it]=1;
        
        
    }
};