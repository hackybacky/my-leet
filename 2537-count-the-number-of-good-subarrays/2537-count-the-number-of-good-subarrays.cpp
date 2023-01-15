class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        
        
        int curk = 0;
        map<int , int > cnt;
        int n = nums.size();
        int right = 0;
        long long ans = 0;
        for(int i = 0 ; i < n ;i++){
            
            while(right < n ){
                if(curk >= k)break;
                curk+= cnt[nums[right]];
                cnt[nums[right]]++;
                right++;
            }
            
            if(curk >= k)
            ans += (long long )(n - right + 1);
            curk -= (cnt[nums[i]] - 1);
            cnt[nums[i]]--;
        }
        return ans;
    }
};