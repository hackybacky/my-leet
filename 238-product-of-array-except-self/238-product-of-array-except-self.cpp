class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int cnt=0;
        for(auto it : nums)product*=it,cnt+=(it==0);
        int n = nums.size();
        vector<int>ans(n);
        if(cnt==1){
            product=1;
            for(auto it : nums){
                if(it!=0)product*=it;
            }
        }
        for(int i=0; i<n; i++){
            if(nums[i]!=0){
                if(cnt)ans[i]=0;
                else ans[i]=product/nums[i];
            }
            else{
                if(cnt==2)ans[i]=0;
                else{
                    ans[i]=product;
                }
            }
            
        }
        
        return ans;
    }
};