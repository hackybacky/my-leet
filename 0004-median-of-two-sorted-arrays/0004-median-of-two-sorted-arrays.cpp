class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size()  , m = nums2.size();
        if(n > m)swap(n , m) , swap(nums1 , nums2);
        
        int l = 0 , r = n ; 
        
        while(l <= r){
            int mid = (l + r)/2;
            int rem = (n + m + 1)/2 - mid;
            
            int left = mid > 0 ? nums1[mid - 1] : INT_MIN;
            int left2 = rem > 0 ? nums2[rem - 1] : INT_MIN;
            int right = mid < n ? nums1[mid] : INT_MAX;
            int right2 = rem < m ? nums2[rem] : INT_MAX;
            
            if(max(left , left2) <= min(right , right2)){
                if( (n+ m ) %2 == 0){
                    return (max(left , left2) + min(right , right2))*1.0 /2;
                }
                return max(left , left2) ;
            }
            else{
                if(left > right2)r = mid - 1;
                else l = mid + 1;
            }
        }
        return -1;
    }
};