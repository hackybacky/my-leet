class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i=nums.size()-2;
        while(i>=0 and nums[i]>=nums[i+1])i--;
        if(i==-1){
            return reverse(nums.begin(),nums.end());
            return ;
        }
        reverse(nums.begin()+i+1,nums.end());
        
        auto it =upper_bound(nums.begin()+i+1,nums.end(),nums[i]);
        
        if(it!=nums.end()){
            swap(nums[i],*it);
        }
        
    }
};