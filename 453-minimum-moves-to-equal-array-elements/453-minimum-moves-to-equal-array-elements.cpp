class Solution {
public:
    int minMoves(vector<int>& nums) {
        if(nums.size()==1)return 0;
        int maxi=*max_element(nums.begin(),nums.end());
        int su=accumulate(nums.begin(),nums.end(),0);
        int n=nums.size();
        int e=(*min_element(nums.begin(),nums.end()));
        
        return su-e*n;
    }
};