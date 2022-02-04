class Solution {
public:
    
    int findMaxLength(vector<int>& nums) {
        
       map<int,int> mp;
       // mp[0]=0;
        int ans=0;
        int su=0;
        for(int i=0; i< nums.size(); i++){
            
            su+=(nums[i]==1?1:-1);
            
            if(mp[su]!=0){
                ans=max(ans,abs(i-mp[su])+1);
            }
            else if(su==0)ans=max(ans,i+1);
            else mp[su]=i+1;
        }
        
        return ans;
    }
};