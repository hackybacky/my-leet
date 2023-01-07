class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int d=0,cur=0;
        int start =0;
        int n = gas.size();
        int tc=0,ts=0;
        for(int i=0;i<n;i++){
            
            if(gas[i]>cost[i])cur+=gas[i]-cost[i];
            else d+=cost[i]-gas[i];
            
            if(d>cur){
                start=i+1;
                d=0,cur=0;
                
            }
            tc+=cost[i];
            ts+=gas[i];
        }
        if(ts<tc)return -1;
        return start;
    }
};