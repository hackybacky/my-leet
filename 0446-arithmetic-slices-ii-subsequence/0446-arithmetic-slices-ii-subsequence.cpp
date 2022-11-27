class Solution {
public:
    
    struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
 
        if (hash1 != hash2) {
            return hash1 ^ hash2;             
        }
         
        // If hash1 == hash2, their XOR is zero.
          return hash1;
    }
};
    int numberOfArithmeticSlices(vector<int>& nums) {
        unordered_map<pair<int ,long > , int , hash_pair> dp;
        
        int ans = 0;
        int n = nums.size();
        // for(int i = 0 ;i < n ;i++){
        //     dp[{i , 0}] = 1;
        // }
        for(int i = n - 1 ;i >= 0 ;i--){
            for(int j = n - 1 ;j > i ;j--){
                long dif = (long)nums[i] - (long)nums[j];
                dp[{i , dif}] += dp[{j , dif}] + 1;
                ans += dp[{j , dif}];
            }
        }
        return ans;
        
    }
};