class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        int ans = 0;
        int mx = INT_MAX;
        char p = colors[0];
        priority_queue<int > pq;
        int cnt = 0;
        for(int i = 0 ; i < colors.size() ; i++){
            if(p == colors[i]){
               
                pq.push(-neededTime[i]);
            }
            else{
                if(pq.size() > 1){
                    while(pq.size() > 1){
                        ans += -pq.top();
                        pq.pop();
                    }
                }
                    pq.pop();
                pq.push(-neededTime[i]);
                p = colors[i];
                
            }
        }
        while(pq.size() > 1)
            ans += -pq.top() , pq.pop();
        return ans;
    }
};