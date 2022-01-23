class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        
        int n=cost.size();
        if(n==1)return cost[0];
        else if(n==2)return cost[0]+cost[1];
        int ans=0;
        int i;
        for( i=n-1 ; i>=2 ;i-=3){
            ans+=cost[i]+cost[i-1];
        }
        while(i>=0)ans+=cost[i],i--;
        return ans;
        
    }
};