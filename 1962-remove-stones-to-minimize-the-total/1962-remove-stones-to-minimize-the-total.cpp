class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        
        priority_queue<int>pq(piles.begin() , piles.end());
        
        while(!pq.empty() and k--){
            int t = pq.top();
            pq.pop();
            int dlt = t / 2 ;
            pq.push(t - dlt);
        }
        int ans = 0;
        while(!pq.empty()){
            int t = pq.top();
            pq.pop();
            ans += t;
        }
        return ans;
        
    }
};