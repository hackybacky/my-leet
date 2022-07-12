class Solution {
public:
    unordered_map<int,int>dp;
    int side;
    int n;
    int recur(int i ,int mask , vector<int>&matchsticks,int cur_sum, int d){
        if(cur_sum>side)return 0;
        if(i==n){
            if(cur_sum==side){
                
                return recur(0,mask,matchsticks,0,d+1);
            }
            return 0;
        }
        if(d==3){
            // cout<<cur_sum<<endl;
            return 1;
        }
        if(dp.find(mask)!=dp.end())return dp[mask];
        
        int ans=0;
        ans|=recur(i+1,mask,matchsticks,cur_sum,d)|((mask&(1<<i))==0?recur(i+1,mask|(1<<i),matchsticks,cur_sum+matchsticks[i],d):0);
        return dp[mask]=ans;
    }
    bool makesquare(vector<int>& matchsticks) {
        int parameter=0;
        
        for(auto it : matchsticks)parameter+=it;
        sort(matchsticks.begin(),matchsticks.end());
        if(parameter%4!=0)return 0;
        n = matchsticks.size();
        // cout<<"d";
        side = parameter/4;
        
        // ans=false;
        return recur(0,0,matchsticks,0,0);
        // return ans;
        
        
    }
};