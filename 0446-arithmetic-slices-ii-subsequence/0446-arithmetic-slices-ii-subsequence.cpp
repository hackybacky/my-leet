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
        unordered_map<pair<int , long long > , int , hash_pair> dp;
        
        int ans = 0;
        int n = nums.size();
        // for(int i = 0 ;i < n ;i++){
        //     dp[{i , 0}] = 1;
        // }
        for(int i = 0 ;i < n ;i++){
            int cur = nums[i];
            for(int j = 0 ; j < i  ; j++){
                
                int ncur = nums[j];
                long dif =  (long long  )cur - (long )ncur;
                dp[{i , dif}] += dp[{j , dif}] + 1;
                // if(dp[{i, dif}])
                ans += dp[{j , dif}];
                
            }
        }
        return ans;
        
    }
};