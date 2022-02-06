class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n<=2)return n;
        int left=2;
        int k=0;
        for(int i=2; i<nums.size(); i++){
            if(nums[i]==nums[left-2])continue;
            
            nums[left++]=nums[i];
        }
        return left;
    }
};