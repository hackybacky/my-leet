class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        unordered_map<int,  int > mp;
        
        int pref = 0;
        int length_nums = nums.size();
        mp[0] = -1;
        for(int index = 0 ; index < length_nums ; index++ ){
            pref += nums[index];
            int cur = pref % k;
            if(mp.find(cur) != mp.end()){
                int prevIndi = mp[cur];
                if(index - prevIndi >= 2){
                    return true;
                }
            }
            else{
                mp[cur] = index;
            }
        }
        return false;
    }
};