class Solution {
public:
    int dp[1<<18];
    int target;
    int recur(int mask,int k,vector<int>&a,int sum){
        //if( k==0)return 0;
        
        if(k==0)return true;
        if( dp[mask]!=-1)return dp[mask];
        if(sum==target){
            return recur(mask,k-1,a,0);
        }
        int ans=0;
        for(int i=0; i<a.size(); i++){
             int d =(1<<i);
                if( !(mask & d)){
                    if(sum+a[i]<=target){
                      ans|=  recur((mask|d),k,a , sum+a[i]);
                    }
                }
        }
          return dp[mask]=ans;               
        
        
        
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int su = accumulate(nums.begin(),nums.end(),0);
        if(su %k!=0)return false;
        target=su/k;
        memset(dp,-1,sizeof(dp));
        return recur(0,k,nums,0);
    }
};