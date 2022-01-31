class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int su=accumulate(nums.begin(), nums.end(),0);
        
        
        int n=nums.size();
        vector<int > dp(su+10,0);
        
        dp[0]=1;
       
      
        for(int i=0; i<n; i++) {
            for(int s=su-nums[i]; s>=0; s--) {
                if(dp[s])
                    dp[s+nums[i]] |= (dp[s]<<1);
            }
            dp[nums[i]] |= 2;
        }
    
        for(int s=0; s<=su; s++){
            int len=dp[s];
            
            for(int j=1; j<=n-1;j++){
                if( len & (1<<j)){
                    if(j==4)cout<<"jjljadf"<<endl;
                    if( (su*j)%n==0 and (su*j)/n==s){cout<<j<<endl;return true;}
                }
            }
        }
        
        return false;
        
        
        
        
    }
};