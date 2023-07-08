class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        long long ans = weights[0] + weights.back();
        int n = weights.size();
        if(n == 1){
            return 0;
        }
        if(k == 1){
            return 0;
        }
        vector<int>cur;
        for(int i = 0 ; i <= n - 2 ; i++){
            cur.push_back(weights[i] + weights[i + 1]);
        }
        sort(cur.begin() , cur.end());
        
        long long maxi = ans , mini =  ans;
        for(int i = 0 ; i < k - 1 ; i++){
            maxi += cur[cur.size() - 1 - i];
            mini += cur[i];
        }
        return maxi - mini;
    }
};