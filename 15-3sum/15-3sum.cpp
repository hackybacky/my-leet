class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int nums_length=nums.size();
        
        sort(nums.begin() , nums.end());
        vector<vector<int>> ans;
        set<vector<int >> a;
        for(int i=0 ;i < nums_length; i++){
            if ((i>0) && (nums[i]==nums[i-1]))
            continue;
            for(int j=i+1; j< nums_length ; j++){
                int su=nums[i]+nums[j];
                
                auto it=lower_bound(nums.begin()+j+1 , nums.end(),-su);
                if(it!=nums.end() and nums[i]+nums[j]+(*it)==0){
                    
                    a.insert({nums[i],nums[j],*it});
                    
                }
                
            }
        }
        for(auto it : a){
            ans.push_back(it);
        }
        return ans;
        
    }
};