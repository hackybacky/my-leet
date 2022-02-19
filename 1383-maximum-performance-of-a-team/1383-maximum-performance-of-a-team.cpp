class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& ef, int k) {
        priority_queue<int ,vector<int> ,greater<int>>pq;
        int i;
        int ts=0,te=0;
        vector<pair<int,int>> o;
        for(int i=0; i<n; i++){
            o.push_back({ef[i],speed[i]});
        }
        sort(o.rbegin(),o.rend());
        long long tspeed=0;
        int eff=1e9;
        const int mod=1e9+7;
        long long lans=0;
        for(auto it: o){
            if(pq.size()<k){
                eff=min(eff,it.first);
                tspeed+=it.second;
                lans=max(lans,tspeed*eff);
                pq.push(it.second);
            }
            else{
                
                    tspeed-=pq.top();
                    pq.pop();
                
                tspeed+=it.second;
                pq.push(it.second);
                eff=it.first;
                lans=max(lans,tspeed*eff);
            }
        }
        
        return lans%mod ;
    }
};