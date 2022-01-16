typedef  long long  ll;
class Solution {
public:
    ll maxRunTime(int n, vector<int>& batteries) {
        auto check=[&](ll mid){
            ll val=0;
            for(auto it :batteries){
                val+=min(mid,(ll)it);
            }
            ll d=n*mid;
            return val>=d;
                
        };
        
        ll l=0,r=1e14;
        while(l<=r){
            ll mid=l+(r-l)/2;
            
            if(check(mid)){
                l=mid+1;
            }
            else r=mid-1;
        }
        return l-1;
    }
};