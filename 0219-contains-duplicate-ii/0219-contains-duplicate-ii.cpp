class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int , int > last;
        for(int i = 0 ; i < nums.size() ;  i++){
            if(last.find(nums[i]) != last.end()){
                int last_oc = last[nums[i]];
                if(i - last_oc <= k)return true;
            }
            last[nums[i]] = i;   
                // ][poiuxzuyjhnb b vjh   c'/[;.3
                  // 4    n c 
        }
        return false;
    }
};