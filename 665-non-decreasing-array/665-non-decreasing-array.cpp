class Solution {
public:
    bool check(vector<int>nums,int mini,int cnt){
         
        nums[0]=mini;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1] ){
                if(i-2<0 or nums[i]>=nums[i-2])
                nums[i-1]=nums[i];
                else{
                    nums[i]=nums[i-1];
                }
                cnt++;
            }
        
        }
        return cnt<=1;
    }
    bool checkPossibility(vector<int>& nums) {
       return check(nums,nums[0],0) ;
    }
};