class Solution {
public:
    vector<vector<int>>dp;
    vector<int>start;
    int recur(int i , int k , vector<vector<int>>&events){
        if(k == 0)return 0;
        if(i == events.size())return 0;
        if(dp[i][k] != -1)return dp[i][k];
        int ntake = recur(i + 1 , k , events);
        auto it = lower_bound(start.begin(),  start.end() , events[i][1] + 1) - start.begin();
        int take = events[i][2] + recur(it , k - 1 , events);
        return dp[i][k] = max(ntake , take);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        
        int n = events.size();
        dp.assign(n , vector<int>(k + 1 , -1));
        sort(events.begin() , events.end());
        for(int i = 0 ; i < n ; i++)start.push_back(events[i][0]);
        return recur(0 , k , events);
    }
};