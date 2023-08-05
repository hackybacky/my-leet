class Solution {
public:
    int mergeSort(vector<int>&nums , int l , int r ,int mid){
        int j = l - 1;
        for(int i = l ; i < r ; i++){
            if(nums[i] < nums[r] ){
                swap(nums[++j] , nums[i]);
            }
        }
        
        swap(nums[++j] , nums[r]);
        return j  ;
    }
    int findKthLargest(vector<int>& nums, int k) {
        
        int n = nums.size();
        if(n == 1)return nums[0];
        int l = 0 , r = n - 1;
        k = n - k ;
        cout << k << endl;
        while(l <= r){
            int mid = (l + r )/2;
            int check = mergeSort(nums , l , r , mid);
            if(check < k){
                l = check + 1;
            }
            else if(check == k)return nums[k];
            else r = check - 1;
        }
        return -1;
    }
};