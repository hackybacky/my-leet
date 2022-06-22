class Solution {
public:
    int partition(int l,int r,vector<int>&nums){
        int pivot= nums[r];
        int j = l;
        for(int i=l;i<r;i++){
            if(nums[i]<=pivot){
                swap(nums[i],nums[j]),j++;
            }
        }
        swap(nums[j],nums[r]);
        return j;
    }
    int findKthLargest(vector<int>& nums, int k) {
        
        int n = nums.size();
        k=n-k;
        int l = 0,r=n-1;
        while(l<r){
            int cur = partition(l,r,nums);
            if(cur<k)l=cur+1;
            else if(cur>k)r=cur-1;
            else break;
        }
        return nums[k];
    }
};