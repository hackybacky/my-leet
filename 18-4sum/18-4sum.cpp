class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0 ; i< n-3; i++){
            if(i>0 and nums[i]==nums[i-1])continue;
            for(int j=i+1; j<n-2;j++){
                if(j>i+1 and nums[j]==nums[j-1])continue;
                int left = j+1,right=n-1;
               
            
               long long int req = (long long)target-(long long)nums[i]-(long long )nums[j];
                
                while(left<right){
                    int sum = nums[left]+nums[right];
                    if(sum<req)left++;
                    else if(sum>req)right--;
                    else{
                        ans.push_back({nums[i],nums[j],nums[left],nums[right]});
                        while(left<right and nums[left]==nums[left+1])left++;
                        left++;
                        while(left<right and nums[right-1]==nums[right])right--;
                        right--;
                    }
                }
            }
        }
        return ans;
    }
};