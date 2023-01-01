class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        unordered_set<int>s(nums.begin() , nums.end());
        for(int i = 0 ; i < n ;i++){
            int cur = nums[i];
            int len = 0;
            while(s.find(cur) != s.end()){
                len++;
                s.erase(cur);
                cur++;
            }
            cur = nums[i] - 1;
            while(s.find(cur) != s.end()){
                len++;
                s.erase(cur);
                cur--;
            }
            ans = max(ans , len);
        }
        return ans;
    }
};