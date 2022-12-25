class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        int dp[k + 1];
        memset(dp , 0 ,sizeof(dp));
        const int mod = 1e9 + 7;
        // int n = nums.size();
        long long total = 1;
        dp[0] = 1;
        long long int sum = 0;
        for(int i = 0 ; i < n ; i++){
            
            for(int j = k - 1 ; j >= nums[i] ; j--){
                dp[j] = (dp[j] + dp[j - nums[i]]) % mod;
            }
            sum += nums[i];
            total = (total * 2)% mod;
        }
        if(2 * k > sum)return 0;
        int ano = 0;
        for(int i = 0 ;i < k; i++){
            ano = (ano + dp[i])% mod;
        }
        cout << ano ;
        
        
        return (total - (2 * ano) + mod )%mod;
        
    }
};