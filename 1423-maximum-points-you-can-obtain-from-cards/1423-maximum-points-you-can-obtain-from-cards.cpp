class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int n= cardPoints.size();
        vector<int>pref(n,0);
        
        for(int i=0;i<n;i++){
            pref[i]+=(i-1>=0?pref[i-1]:0)+cardPoints[i];
        }
        int su=0;
        int ans=0;
        for(int i=n;i>=n-k;i--){
            int p = k-n+i;
            if(i<n)su+=cardPoints[i];
            int cur=su;
            // cout<<p<<endl;
            if(p-1>=0)cur+=pref[p-1];
            ans=max(ans,cur);
        }
        return ans;
    }
};