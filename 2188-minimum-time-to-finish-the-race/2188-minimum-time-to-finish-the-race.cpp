typedef long long  ll ;
class Solution {
public:
    vector<ll> pre;
    vector<ll> dp;
    ll maxlap;
    ll recur(ll lap,int changeTime){
        if(lap==0)return -changeTime;
        
        if(dp[lap]!=-1)return dp[lap];
        ll ans=INT_MAX;
        for(ll i=1; i<=maxlap; i++){
            if(i>lap)continue;
            ll k=pre[i];
            ans=min(ans,k +changeTime+ recur(lap-i,changeTime));
        }
        return dp[lap]=ans;
    }

    int minimumFinishTime(vector<vector<int>>& tire, int c, int numLaps) {
        dp.assign(1001,-1);
        pre.assign(1001,1e8);
        for(auto it : tire){
            ll first=it[0],second=it[1];
            ll cur=first;
            ll time=first;
            for(ll i=1;time<first+c and i<=numLaps; i++ ){
                maxlap=max(maxlap,i);
                pre[i]=min(pre[i],cur);
              
                time*=second;
                cur+=time;
                
            }
        }
       
        //for(int i=0; i<3; i++)cout<<pre[i]<<endl;
        return recur(numLaps,c);
    }
};