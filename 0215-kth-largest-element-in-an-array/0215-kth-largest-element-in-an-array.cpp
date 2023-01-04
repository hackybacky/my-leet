class Solution {
public:
    int partition(vector<int>&nums , int low , int high){
        
        int pivot = nums[high];
        int i = low - 1;
        for(int k = low  ;  k < high ; k++){
            if(nums[k] < pivot){
                swap(nums[k] , nums[++i]);
            }
        }
        swap(nums[high] , nums[i + 1] );
        // for(auto it : nums)cout << it << " ";
        // cout << endl;
        return i + 1;
        
    }
    int findKthLargest(vector<int>& nums, int k) {
        
        int n = nums.size();
        k = n - k;
        int low = 0 , high = n - 1;
        while(low <= high){
            int part = partition(nums , low , high);
            if(part == k ){
                return nums[k ];
            }
            else if(part < k ){
                low = part + 1;
            }
            else high = part - 1;
        }
        return -1;
        
        
    }
};