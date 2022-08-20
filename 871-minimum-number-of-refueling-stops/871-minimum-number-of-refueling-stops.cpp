class Solution {
public:
//     int dp[501][501];
//     int recur( int i , int take){
//         if(i==stations.size()){
//             return 0;
//         }
//         if(dp[i][take]!=-1)return dp[i][take];
        
        
//     }
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int>pq;
        int n = stations.size();
        int ans=0;
        int curmax=startFuel;
        int i=0;
        while(curmax<target){
            while(i<n and stations[i][0]<=curmax){
                pq.push(stations[i][1]);
                i++;
            }
            if(pq.empty())return -1;
            curmax+=pq.top();
            pq.pop();
            ans++;
        }
        // if(curmax<target)retur
        return ans;
    }
};