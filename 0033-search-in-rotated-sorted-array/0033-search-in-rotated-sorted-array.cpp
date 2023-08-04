class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0 , r = n - 1;
        int rot = 0;
        while(l <= r){
            int mid = (l + r)/2;
            if(nums[mid] <= nums[n - 1]){
                rot = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        // return rot;
        l = 0 , r = n - 1;
        while(l <= r){
            int mid = (l + r)/2;
            int nmid = (mid + rot) % n;
            if(nums[nmid] < target){
                l = mid + 1;
            }
            else if(nums[nmid] == target)return nmid;
            else r = mid - 1;
        }
        return -1;
        
    }
};