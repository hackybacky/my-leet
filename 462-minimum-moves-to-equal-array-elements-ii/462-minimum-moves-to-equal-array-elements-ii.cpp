class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int lans=INT_MAX;
        for(int i=0; i<2; i++){
            int med=nums[(n-i)/2];
            int ans=0;
            
            for(auto it : nums){
                ans+=abs(it-med);
            }
            cout<<ans<<endl;
            lans=min(lans,ans);
        }
        return lans;
    }
};