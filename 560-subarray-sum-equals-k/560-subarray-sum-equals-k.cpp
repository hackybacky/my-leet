class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        
        int su=0;
        
        int ans=0;
        mp[0]=1;
        
        for(auto it : nums ){
            su+=it;
            
            if(mp.find(su-k)!=mp.end() )ans+=mp[su-k];
            mp[su]++;
            
            //cout<<ans<<endl;
        }
        
        return ans;
    }
};