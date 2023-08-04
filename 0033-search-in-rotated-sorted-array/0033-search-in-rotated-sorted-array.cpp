class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0 , r = n - 1;
        int ans = -1;
        while(l <= r){
            int mid = (l + r)/2;
            int dis = nums[mid] - nums[n - 1];
            int dis2 = target - nums[n - 1];
             if (nums[mid] == target){ans = mid; break;}
            else if(dis * dis2 > 0){
                if(nums[mid] > target)r = mid - 1;
                else l = mid + 1 ;
            }
            else{
                if(dis2 > 0)r = mid - 1;
                else l = mid + 1;
            }
            
        }
        return ans;
    }
};