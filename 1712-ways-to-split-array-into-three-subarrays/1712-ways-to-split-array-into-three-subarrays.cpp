class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int n=nums.size();
        for(int i=1; i<n; i++){
            nums[i]+=nums[i-1];
        }
        int ans=0;
        const int mod =1e9+7;
        for(int i=0,j=0,k=0; i<n-2; i++){
            j=max(i+1,j);
            
            while(j<n-1 and nums[j]<2*nums[i]){
                j++;
            }
            k=max(j,k);
            
            while(k<n-1 and nums[k]-nums[i]<=nums[n-1]-nums[k])k++;
            ans=(ans+(k-j))%mod;
        }
        return ans;
    }
};