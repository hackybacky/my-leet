class Solution {
public:
    //     int search(int A[], int n, int target) {
    //     int lo=0,hi=n-1;
    //     // find the index of the smallest value using binary search.
    //     // Loop will terminate since mid < hi, and lo or hi will shrink by at least 1.
    //     // Proof by contradiction that mid < hi: if mid==hi, then lo==hi and loop would have been terminated.
    //     while(lo<hi){
    //         int mid=(lo+hi)/2;
    //         if(A[mid]>A[hi]) lo=mid+1;
    //         else hi=mid;
    //     }
    //     // lo==hi is the index of the smallest value and also the number of places rotated.
    //     int rot=lo;
    //     lo=0;hi=n-1;
    //     // The usual binary search and accounting for rotation.
    //     while(lo<=hi){
    //         int mid=(lo+hi)/2;
    //         int realmid=(mid+rot)%n;
    //         if(A[realmid]==target)return realmid;
    //         if(A[realmid]<target)lo=mid+1;
    //         else hi=mid-1;
    //     }
    //     return -1;
    // }
    int search(vector<int>& A, int target) {
        int n = A.size();
        int lo=0,hi=n-1;
        // find the index of the smallest value using binary search.
        // Loop will terminate since mid < hi, and lo or hi will shrink by at least 1.
        // Proof by contradiction that mid < hi: if mid==hi, then lo==hi and loop would have been terminated.
        while(lo<hi){
            int mid=(lo+hi)/2;
            if(A[mid]>A[hi]) lo=mid+1;
            else hi=mid;
        }
        // lo==hi is the index of the smallest value and also the number of places rotated.
        int rot=lo;
        lo=0;hi=n-1;
        // The usual binary search and accounting for rotation.
        while(lo<=hi){
            int mid=(lo+hi)/2;
            int realmid=(mid+rot)%n;
            if(A[realmid]==target)return realmid;
            if(A[realmid]<target)lo=mid+1;
            else hi=mid-1;
        }
        return -1;
//         int n = nums.size();
//         int l =0,r=n-1;
        
//         while(l <= r){
//             int mid = (l + r)/2;
//             if(nums[mid] > nums[r]){
//                 l = mid + 1;
//             }
//             else{
//                 r = mid - 1;
//             }
//         }
//         int k = l;
//         int ans = -1;
//         l = 0 ,r = n - 1;
//         while(l <= r){
//             int mid = (l + r)/2;
//             int nmid = ( mid + k )% n;
//             // cout << nmid << endl;
//             if(nums[nmid] == target){
//                 return ans = nmid ;
//                 break;
//             }
//             if( nums[nmid] < target){
//                 l = mid + 1;
//             }
            
//             else{
//                 r = mid - 1;
//             }
//         }
//         return ans;
    }
};