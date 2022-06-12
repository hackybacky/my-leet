class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        
        
        vector<int>res;
        
        for(auto it :nums){
            
            auto it2=lower_bound(res.begin(),res.end(),it);
            if(it2==res.end()){
                res.push_back(it);
            }
            else *it2=it;
        }
        return res.size();
        
    }
};