class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& q) {
        
        // vector<int>ans;
        int ans = 0;
        for(auto it : nums)
            if(it % 2 == 0)
                ans += it;
        vector<int>lans;
        for(auto it : q){
            int v = it[0];
            int i = it[1];
            if(abs(nums[i]) % 2 == abs(v) % 2){
                
                if(nums[i] % 2 == 0)
                    ans += v;
                else 
                    ans = ans + nums[i] + v;
                nums[i] += v;
            }
            else{
                if(nums[i] % 2 == 0)
                    ans -= nums[i];
                nums[i] += v;
            }
            lans.push_back(ans);
        }
        return lans;
    }
};