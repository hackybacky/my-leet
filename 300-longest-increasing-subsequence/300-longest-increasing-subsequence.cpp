class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int>res;
        
        for(auto it2 : nums){
            auto it = lower_bound(res.begin(),res.end(),it2);
            if(it==res.end())res.push_back(it2);
            else *it=it2;
        }
        return res.size();
    }
};