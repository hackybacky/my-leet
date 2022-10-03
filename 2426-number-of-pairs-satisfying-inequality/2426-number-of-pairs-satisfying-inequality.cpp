#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;
//u can find count of element equal to or smaller by using pl and find_by_order({ele,1e18})
 
class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        vector<int> dif;
        ordered_set<pair<int , int>>s;
        int n = nums1.size();
        for(int i = 0 ; i < n ;i++){
            dif.push_back(nums2[i] - nums1[i]);
        }
        long long int ans = 0;
        for(int i = n - 1; i >=0 ; i--){
            int cur = dif[i] + diff;
            
            long long it = s.order_of_key({cur , INT_MAX});
            ans += it;
            s.insert({dif[i] , i});
            
        }
        return ans;
        
        
    }
};