class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int>pq;
        int mn=1e9;
        for(auto it : nums){
            if(it%2==1){it*=2;}
            pq.push(it);
            mn=min(mn,it);
        }
        int res=1e9;
        
        while(1){
            res=min(res,pq.top()-mn);
            int t=pq.top();
            pq.pop();
            if(t%2==0){
                pq.push(t/2);
                mn=min(mn,t/2);
            }
            else{
                break;
            }
        }
        return res;
        
    }
};