class Solution {
public:
    int go(vector<int> &ar, int cur, int n, int k, vector<int> &vis, map<vector<int>, int> &occ){
        // Hit the last index - base case
        if(cur >= n)
            return 0;
        
        // Check if the current state is pre-computed
        if(occ.count(vis))
            return occ[vis];
        
        int mx = -1;
        
        // Try filling the slots recursively
        for(int i = 1; i <= k; i++){
            
            // An element can be filled in this 'ith' slot, as each slot can
            // have atmost 2 elements
            if(vis[i] < 2){
                
                // Increment the filled spaces in 'ith' slot
                vis[i]++;
                
                // Recur to find the best possible answer
                int res = (i & ar[cur]) + go(ar, cur+1, n, k, vis, occ);
                
                // Maximize mx
                mx = max(mx, res);
                
                // Backtrack, empty a space in 'ith' slot
                vis[i]--;
            }
        }
        
        // return
        return occ[vis] = mx;
    }
    int maximumANDSum(vector<int>& ar, int k) {
        int n = ar.size();
        map<vector<int>, int> occ;
        
        // stores the configuration of slots (left or occupied) (1...k)
        vector<int> vis(k+1, 0);
        
        return go(ar, 0, n, k, vis, occ);
    }
};