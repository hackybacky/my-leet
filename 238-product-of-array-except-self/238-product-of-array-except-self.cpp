class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>pref(n+1,1);
        auto suf = pref;
        pref[0]=nums[0];
        for(int i=1; i<n ; i++){
            pref[i]*=pref[i-1]*nums[i];
        }
        for(int i=n-1; i>=0; i--){
            suf[i]*=suf[i+1]*nums[i];
        }
        
        vector<int>ans(n);
        
        for(int i=0; i<n; i++){
            int p = (i-1>=0?pref[i-1]:1);
            int s = suf[i+1];
            
            ans[i]=s*p;
        }
        return ans;
    }
};