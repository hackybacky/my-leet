class Solution {
public:
    int n , m;
    int ans = 0;
    int dp[1001][1001];
    int recur(int i , int j , vector<int>&nums1 , vector<int>&nums2){
        if(i == n or j == m){
            return 0;
        }
        if(dp[i][j] != -1)return dp[i][j];
        
        recur( i + 1 , j , nums1 , nums2),recur(i , j + 1 , nums1 , nums2);
        dp[i][j] = 0;
        if(nums1[i] == nums2[j]){
            dp[i][j] = recur(i + 1 ,j + 1 , nums1 , nums2) + 1;
        }
        ans = max(dp[i][j] , ans);
        return dp[i][j];
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size() ;
        m = nums2.size();
        memset(dp , -1 , sizeof(dp));
        recur(0 , 0 ,nums1 , nums2);
        return ans;
        
    }
};