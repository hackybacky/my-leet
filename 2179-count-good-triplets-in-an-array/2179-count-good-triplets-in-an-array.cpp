
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        ordered_set<int> s;
        
        int n=nums1.size();
        vector< int> pref(n);
        vector< int>suf(n);
        vector<int>pos(n+1);
        for(int i=0; i< n; i++){
            pos[nums2[i]]=i;
        }
        
        for(int i=0; i<n; i++){
            pref[i]=s.order_of_key(pos[nums1[i]]);
            s.insert(pos[nums1[i]]);
        }
        ordered_set<int> s2;
        for(int i=n-1; i>=0; i--){
            suf[i]=n-1-i-s2.order_of_key(pos[nums1[i]]);
            
            s2.insert(pos[nums1[i]]);
        }
       long long  int ans=0;
        for(int i=0; i<n; i++){
            //cout<<pref[i]<<" "<<suf[i]<<endl;
            ans=(ans+((long long)pref[i]*(long long)suf[i]));
        }
        return ans;
         
    }
};