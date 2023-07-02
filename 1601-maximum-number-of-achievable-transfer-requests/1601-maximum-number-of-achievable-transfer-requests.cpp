class Solution {
public:
    
    int maximumRequests(int n, vector<vector<int>>& requests) {
        // int n = request.size();
        vector<int>indeg(n , 0);
        auto out = indeg;
        for(auto it : requests){
            int u = it[0] , v = it[1];
            indeg[v]++;
            out[u]++;
        }
        int ans = 0;
        int m = requests.size();
        for(int mask = 0 ; mask < ( 1 << m ) ; mask++){
            vector<int>cur(n , 0);
            vector<int>curo(n , 0);
            for(int i = 0 ; i < m ;i++){
                if(((1 << i) & mask) ){
                    cur[requests[i][1]]++;
                    curo[requests[i][0]]++;
                }
            }
            if(cur == curo){
                // cout << mask << endl;
                ans = max(ans , __builtin_popcount(mask));
            }
        }
        return ans;
    }
};