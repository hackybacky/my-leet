class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int>pq;
        
        for(auto it : stones)pq.push(it);
        
        while(!pq.empty() ){
            int t = pq.top();
            pq.pop();
            if(pq.empty())return t;
            int s = pq.top();
            pq.pop();
            int d = t-s;
            if(d!=0){
                pq.push(d);
            }
        }
        return 0;
    }
};