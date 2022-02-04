class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
        unordered_map<int,int> mp;
        for(auto it : nums1){
            for(auto it2 : nums2){
                mp[it+it2]++;
            }
        }
        int ans=0;
        for(auto it : nums3){
            for(auto it2 : nums4){
                if(mp.find(-(it+it2))!=mp.end()){
                    ans+=mp[-(it+it2)];
                }
            }
        }
        return ans;
    }
};