class Solution {
public:
    bool isPossible(vector<int>& target) {
        long long su =0;
        
        for(auto it:target)su+=it;
        
        priority_queue<int>pq(target.begin(),target.end());
        
        while(su>1  and pq.top()>su/2 and pq.top()>1){
            int t = pq.top();
            pq.pop();
            su-=t;
            if(su<=1){
                return su;
            }
            t%=su;
            su+=t;
            pq.push(t);
        }
        cout<<su<<endl;
        return su==target.size();
    }
};