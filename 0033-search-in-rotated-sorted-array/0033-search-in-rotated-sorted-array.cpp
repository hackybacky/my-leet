class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0 , high = n - 1;
        while(low <= high){
            int mid = (low + high)/2;
            int current_value = nums[mid];
            int left_value = nums[low] ;
            int right_value = nums[high];
            if(current_value == target)return mid;
            cout << low << " "<< high << " "<< mid << endl;
            if((nums[mid]-nums[n-1])*(target-nums[n-1])>0){
                if(current_value < target)low = mid + 1;
                else high = mid - 1 ;
            }
            else if(target > nums[n - 1]){
                high = mid - 1 ;
            }
            else low = mid + 1;
        }
        
        return -1;
    }
};