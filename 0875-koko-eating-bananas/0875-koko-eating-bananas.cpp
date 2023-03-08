class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1 , r = 1e9 ;
        int ans = -1;
        while(l <= r){
            int mid = (l + r)/2;
            long long hour = 0 ;
            for(auto it : piles){
                hour += (it + mid - 1)/ mid;
            }
            if(hour <=(long long) h){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
};