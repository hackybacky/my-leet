class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
        
        int n = nums.size();
         int less[n][n];
        memset(less , 0 , sizeof(less));
        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                less[i][j] += (j - 1 >= 0 ? less[i][j - 1] : 0) + (nums[j] < nums[i] );
            }
        }
        long long ans = 0;
        for(int j = 1 ; j < n - 2; j++){
            for(int k = j ; k < n - 1 ; k++){
                if(nums[k] < nums[j]){
                    long long int g =(n - k - 1  - (less[j][n - 1] - less[j][k]));
                    ans += ((long long)less[k][j - 1] * g);
                }
            }
        }
        return ans;
    }
};