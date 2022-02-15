class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones=0,two=0;
        
        for(auto it : nums){
            ones =(ones ^ it)& ~two;
            two=(two^it)& ~ones;
            
        }
        
        return ones;
    }
};