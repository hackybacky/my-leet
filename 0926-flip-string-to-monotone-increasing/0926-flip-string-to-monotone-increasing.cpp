class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int cnt0 = 0;
        // int ans = 0;
        int n = s.size();
        int ans = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '0')cnt0++;
        }
        int cnt1 = 0;
        ans = INT_MAX;
        for(int i = 0 ; i < n ;i++){
            if(s[i] == '1'){
                ans = min(ans , cnt0 + cnt1);
                cnt1++;
            }
            else {
                cnt0--;
                ans = min(ans , cnt1 + cnt0);
            }
        }
        return ans;
        
    }
};