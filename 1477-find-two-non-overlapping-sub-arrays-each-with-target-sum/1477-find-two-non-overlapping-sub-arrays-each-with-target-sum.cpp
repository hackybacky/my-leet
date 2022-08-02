class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        
        int n = arr.size();
        vector<int>pref(n+1,1e7);
        unordered_map<int , int > mp;
        mp[0]=-1;
        int su=0;
        int ans = 1e6;
        for(int i=0;i<n;i++){
            
            su+=arr[i];
            
            int req = su-target;
            if(mp.find(req)!=mp.end()){
                int cur_len = i-mp[req];
                int d = i-cur_len>=0?pref[i-cur_len]:1e7;

                ans= min(ans,cur_len+d);
                pref[i]=cur_len;
            }
            mp[su]=i;
            if(i-1>=0)pref[i]=min(pref[i],pref[i-1]);
            
        }
        if(ans==1e6)return -1;
        return ans;
    }
};