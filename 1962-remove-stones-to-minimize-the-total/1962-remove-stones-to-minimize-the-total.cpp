class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        
        priority_queue<int>pq(piles.begin() , piles.end());
        int ans = 0;
        for(auto it : piles){
            ans += it;
        }
        while(!pq.empty() and k--){
            int t = pq.top();
            pq.pop();
            int dlt = t / 2 ;
            ans -= dlt;
            pq.push(t - dlt);
        }
        
        return ans;
        
    }
};