class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int low = 0 , high = 1e9;
        int ans = -1;
        while(low <= high){
            int mid = (low + high) / 2;
            int cur = 0;
            int pos = 0;
            for(int i = 0 ; i < n ;i++){
                if(bloomDay[i] <= mid){
                    cur++;
                }
                else cur = 0;
                if(cur == k){
                    pos++;
                    cur = 0;
                }
            }
            if(pos >= m){
                high = mid - 1;
                ans = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};