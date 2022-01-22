class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int su=0;
        int lans=-1e9;
        int N=nums.size();
        for(int i=0 ; i<N ; i++){
            su+=nums[i];
            lans=max(su,lans);
            if(su<0)su=0;
            
            
        }
        return lans;
            
    }
};