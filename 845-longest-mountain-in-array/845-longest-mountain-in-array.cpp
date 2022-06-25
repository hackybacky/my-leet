class Solution {
public:
    int longestMountain(vector<int>& arr) {
        
        int n = arr.size();
        vector<int>pref(n,0);
        vector<int>suf(n+1,0);
        
        for(int i=1;i<n;i++){
            if(arr[i]>arr[i-1])pref[i]+=pref[i-1]+1;
            else pref[i]=0;
        }
        
        for(int i=n-2;i>=0;i--){
            if(arr[i+1]<arr[i])suf[i]+=suf[i+1]+1;
            else suf[i]=0;
        }
        int ans=0;
        for(int i=1;i<n-1;i++){
            if(pref[i]>0 and suf[i]>0)
            ans=max(ans,pref[i]+suf[i]+1);
        }
        return ans;
    }
};