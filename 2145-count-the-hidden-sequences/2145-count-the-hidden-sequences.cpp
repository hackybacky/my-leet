class Solution {
public:
    int numberOfArrays(vector<int>& difference, int lower, int upper) {
        int n=difference.size();
        vector<long long> pref(n,0);
        pref[0]=difference[0];
        long long maxi=difference[0];
        long long mini=maxi;
        for(int i=1; i<n ; i++){
            pref[i]=pref[i-1]+difference[i];
                maxi=max(pref[i],maxi);
                mini=min(pref[i],mini);
        }
        int l=lower-mini;
        int r=upper-maxi;
        r=min(r,upper);
        l=max(l,lower);
        cout<<mini<<" "<<r;
                         
                         
        return max(0,r-l+1);
    }
};