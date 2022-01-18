class Solution {
public:

    void dfs(vector<int> &nums , int child){
        // if(nums[child]>nums.size() and nums[child]<=0)return ;
        if(nums[child]-1<0 and nums[child-1]>=nums.size())
            
         return ;
        int &prev=nums[nums[child]-1];
        swap(prev,nums[child]);
        if(prev!=nums[child] )dfs(nums,child);
        else return ;
        
    }
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        int j=n-1;
        for(int i=0 ; i< n ; i++){
            while(nums[i]>0 and nums[i]<= n and nums[i]!=nums[nums[i]-1])
                swap(nums[i],nums[nums[i]-1]);
        }
        
        for(int i =0 ; i<n ; i++){
            
            if(nums[i]!=i+1){
                return i+1;
            }
        }
        return n+1;
    }
};