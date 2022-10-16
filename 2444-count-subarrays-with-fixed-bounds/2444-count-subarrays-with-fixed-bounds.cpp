class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int mn = -1;
        int mx = -1;
        int j = 0;
        long long ans = 0;
        int n = nums.size();
        for(int i = 0 ; i < n ;i++){
            if(nums[i] > maxK or nums[i] < minK)    {
                mn = -1;
                mx = -1;
                j = i + 1;
            }
            if(nums[i] == minK)mn = i;
            if(nums[i] == maxK)mx = i;
            
            ans += max(0 , min(mn , mx) - j + 1);
        }
        return ans;
    }
};