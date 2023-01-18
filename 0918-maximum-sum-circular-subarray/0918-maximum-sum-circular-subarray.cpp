class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int sum = 0 , minsum = nums[0] , maxsum= nums[0];
        int curmax = 0 , curmin =0;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            int it = nums[i];
            sum += it;
            curmax = max(it , curmax + it);
            curmin = min(it , curmin + it);
            maxsum = max(maxsum , curmax);
            minsum = min(minsum , curmin);
        }
        
        return maxsum > 0 ? max(maxsum , sum - minsum) : maxsum;
    }
};