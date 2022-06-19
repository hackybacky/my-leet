class Solution {
public:
    struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
 
        if (hash1 != hash2) {
            return hash1 ^ hash2;             
        }
         
        // If hash1 == hash2, their XOR is zero.
          return hash1;
    }
};
    int dp[1001][1001];
    
    int recur(int i , string & s , int k,int cur_len ,int cur,int pos){
        if(i<0)return 0;
         // cout<<cur_s<<" "<<cur<<endl;
        if(dp[i][cur_len]!=-1)return dp[i][cur_len];
        int ans=recur(i-1,s,k,cur_len,cur,pos);
        int ncur=cur;
        bool flag=true;
        if(s[i]=='1'){
            // cout<<"hleo"<<(1<<cur_len)<<" "<<cur_len<<" "<<cur_s<<endl;
            if(cur_len>30){flag=false;}
            if(flag)
            ncur|=(1<<cur_len);
            
           
        }
        int ans2=0;
        if(ncur<=k and flag){
        
            
            ans2=1+recur(i-1,s,k,cur_len+1,ncur,pos);
        }
    
        
        return dp[i][cur_len]=max(ans,ans2);
        
        
    }
    int longestSubsequence(string s, int k) {
        memset(dp,-1,sizeof(dp));
        return recur(s.size()-1,s,k,0,0,0);
    }
};