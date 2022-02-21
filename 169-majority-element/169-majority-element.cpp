class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt =0;
        int major = nums[0];
        for(auto it : nums){
            if(it==major){
                cnt++;
            }
            else if(cnt==0){
                major=it;
                cnt++;
            }
            else{
                cnt--;
            }
        }
        return major;
            
    }
};