class Solution {
public:
    
    int maxConsecutiveAnswers(string s, int k) {
        int n = s.size();
        vector<int>dp(n , 0);
        
        for(int i = 0 ; i < n ;i++){
            dp[i] += (i -1  >= 0 ? dp[i- 1] : 0) + (s[i] == 'F');
        }
        int ans = 0;
        int low =  1 , high = n ;
        while(low <= high){
            int mid = (low + high)/2;
            bool flag = false;
            for(int i = 0 ; i <= n - mid;i++){
                int fcnt = dp[i + mid - 1] - (i - 1 >= 0 ? dp[i - 1] : 0);
                int tcnt = mid - fcnt;
                if(fcnt <= k or tcnt <= k)flag = true;
            }
            if(flag){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return ans;
    }
};