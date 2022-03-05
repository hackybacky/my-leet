class Solution {
public:
    int dp[30000];
    map<int,int> cnt;
    int recur(int i ,  vector<int>&nums){
        if(i>=nums.size()  )return 0;
        
        if(dp[i]!=-1)return dp[i];
        
        //if take;
        int k =0;
        k=(nums[i]*cnt[nums[i]]);
       // cout<<k<<endl;
        int ans;
        if(i+1<nums.size() and nums[i+1]==nums[i]+1){
            ans=max(k+recur(i+2,nums),recur(i+1,nums));
        }
        else ans=max(k+recur(i+1,nums),recur(i+1,nums));
        
        
       
       //cout<<"sf"<<endl;
       
        
       
        
        return dp[i]=ans;
        
    }
    int deleteAndEarn(vector<int>& nums) {
        cnt.clear();
        for(auto it : nums)cnt[it]++;
        sort(nums.begin(),nums.end());
       nums.erase( unique( nums.begin(), nums.end() ), nums.end() );
        
       // for(auto it : cnt)cout<<it.first<<" "<<it.second<<endl;
       memset(dp,-1,sizeof(dp));
       
       int ans= recur(0,nums);
        
    //    for(int i=0; i<it.size(); i++)cout<<it[i]<<" ";
        //cout<<endl;
        return ans;
        
    }
};