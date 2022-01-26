class Solution {
public:
    int maxScore(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<vector<int>> dp( n+2,vector<int>(1<<n) );
        
        for(int mask=0; mask < (1<<n); mask++){
            
            vector<int> v;
            for(int pre =0; pre<n ; pre++){
                if((1<<pre)&mask)continue;
                
                v.push_back(pre);

            }
            int operation_pf=__builtin_popcount(mask)/2;
            for(int i=0; i<v.size() ; i++){
                for(int j=i+1 ; j<v.size(); j++){
                    int d=mask|(1<<v[j])|(1<<v[i]);
                    dp[operation_pf+1][d]=max(dp[ operation_pf+1  ][d],dp[operation_pf][mask]+(operation_pf+1)*(__gcd(nums[v[j]],nums[v[i]])));
                }
            }
        }
        return dp[n/2][(1<<n)-1];
        
    }
};