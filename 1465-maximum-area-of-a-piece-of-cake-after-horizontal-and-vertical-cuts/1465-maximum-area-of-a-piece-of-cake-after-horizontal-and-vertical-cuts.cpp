class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int  maxi=INT_MIN;
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        sort(verticalCuts.begin(),verticalCuts.end());
        for(int i=1;i<verticalCuts.size() ; i++){
            
            int cur = abs(verticalCuts[i]-verticalCuts[i-1]);
            // cout<<verticalCuts[i]<<endl;
            maxi=max(cur,maxi);
        }
        // cout<<maxi<<endl;
        horizontalCuts.push_back(h);
        horizontalCuts.push_back(0);
        sort(horizontalCuts.begin(),horizontalCuts.end());
        long long ans=0;
        int mod=1e9+7;
        for(int i=1;i<horizontalCuts.size() ;i++){
            long long cur = abs(horizontalCuts[i]-horizontalCuts[i-1]);
            long long d= (long long)cur*(long long)maxi;
            
            ans=max(ans,d);
        }
        return ans%mod;
    }
};