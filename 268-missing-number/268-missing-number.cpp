class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xo =0 ;
        
        for(auto it : nums)xo^=it;
        
        for(int i=1;i<=nums.size(); i++)xo^=i;
        return xo;
    }
};