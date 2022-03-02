class Solution {
public:
    int dp[2][1<<22];
    int T;
    int recur(int player,int mask,int m,int score){
        if(dp[player][mask]!=-1)return dp[player][mask];
        //if(mask>T)return 0;
        bool flag=true;
        int ans=1;
        for(int i=0; i< m ; i++){
            int t =(1<<i);
            
            if( !(t&mask) ){
                if( score+i+1>=T  or recur(player^1,(mask|t),m,score+i+1)==0 )return dp[player][mask]=1;
                
            }
        }
        
       // if(flag=true)ans=1;
        
        return dp[player][mask]=0;
    }
    bool canIWin(int m, int t) {
        if((m*(m+1))/2<t)return false;
        memset(dp,-1,sizeof(dp));
        T=t;
        return recur(0,0,m,0);
    }
};