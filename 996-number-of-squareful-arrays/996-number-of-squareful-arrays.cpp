class Solution {
public:
    bool check(int &a ,int &b){
        int su=a+b;
        int sq=sqrt(su);
        if(sq*sq==su)return true;
        return false;
    }
    int ans,n;
    void solve(vector<int>&nums , int i ,vector<bool>&used,int an){
        if(an==n){
            ans++;
            return;
        }
        
        for(int j=0; j<n; j++){
            if(!used[j] ){
                
                used[j]=true;
                int k=j;
                
                if(an==0){
                     while(j<n and nums[j]==nums[k])j++;
                    //cout<<nums[k]<<endl;
                    solve(nums,k,used,an+1);
                }
                else if(an>0 and check(nums[j],nums[i])){
                     while(j<n and nums[j]==nums[k])j++;
                    solve(nums,k,used,an+1);
                }
                
                
                if(j!=k)j--;
                used[k]=false;
                
                
            }
        }
        
    }
    int numSquarefulPerms(vector<int>& nums) {
         n=nums.size();
        ans=0;
        sort(nums.begin(),nums.end());
        vector<bool> used(n,false);
        solve(nums,0,used,0);
        return ans;
    }
};