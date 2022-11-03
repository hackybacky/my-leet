class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string , int > cnt;
        
        for(auto it : words){
            cnt[it]++;
        }
        int ans = 0;
        bool flag = false;
        for(auto it : words){
            string cur = it;
            reverse(it.begin() , it.end());
            if(cur == it){
                if(cnt[cur] % 2 == 1){
                    flag = true;
                }
                
                ans += cnt[cur]/2 * 4;
                cnt[cur] = 0;
            }
            else
            ans += min(cnt[cur] , cnt[it]) * 4, cnt[cur] = 0;
        }
        // ans *= 2;
        if(flag )ans += 2;
        return ans;
    }
};