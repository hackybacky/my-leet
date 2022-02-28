class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string > ans;
        nums.push_back(-1);
        int l=nums[0],r=nums[0];
        for(int i=1; i<nums.size(); i++){
            
            if(nums[i-1]==INT_MAX or nums[i]!=nums[i-1]+1){
               // string t = (char)(left)+"->"+char(right);
                if(l!=r)
                ans.push_back(to_string(l)+"->"+to_string(r));
                else ans.push_back(to_string(l));
                l=nums[i],r=nums[i];
            }
            else r=nums[i];
        }
        
        return ans;
    }
};