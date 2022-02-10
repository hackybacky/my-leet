class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
       // int ans=0;
        
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        
        int m=nums.size();
        int ans=n,j=0;
        for(int i=0; i< m ; i++){
            
            while(j<m and nums[i]+n>nums[j])j++;
          //  j--;
            ans=min(ans,n-j+i);
            
        }
        return ans;
    }
};