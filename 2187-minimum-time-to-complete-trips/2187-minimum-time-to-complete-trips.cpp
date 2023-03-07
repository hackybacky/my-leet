class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long int l=0,r=1e18;
        long long int ans=1e18;
        while(l<=r){
            long long int mid =l+(r-l)/2;
            long long int cur=0;
            for(auto it : time){
                cur+=mid/it;
                if(cur>=totalTrips)break;
            }
            if(cur>=totalTrips){r=mid-1;}
            else l=mid+1;
           // else {ans=mid;break;}
            
        }
        return r+1;
    }
};