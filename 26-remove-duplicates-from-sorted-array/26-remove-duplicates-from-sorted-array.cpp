class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)return 0;
        int cnt=0;
        for(int i =0 ; i< nums.size()-1 ; i++){
            if(nums[i]==nums[i+1]){
                cnt++;
            }
            else nums[i+1-cnt]=nums[i+1];
        }
        return nums.size()-cnt;
    }
};