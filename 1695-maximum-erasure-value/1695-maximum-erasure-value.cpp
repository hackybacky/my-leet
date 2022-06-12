class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int>pref(n,0);
        pref[0]=nums[0];
        
        for(int i=1;i<n; i++)pref[i]+=pref[i-1]+nums[i];
        
        map<int,int>mp;
        int last=-1;
        int ans = 0;
        for(int i=0;i<n;i++){
            
            if(mp.find(nums[i])!=mp.end() and last<mp[nums[i]]){
                last=mp[nums[i]];
            }
            mp[nums[i]]=i;
            int cur= pref[i]-(last>=0?pref[last]:0);
            
            
            ans=max(ans,cur);
        }
        return ans;
        
    }
};