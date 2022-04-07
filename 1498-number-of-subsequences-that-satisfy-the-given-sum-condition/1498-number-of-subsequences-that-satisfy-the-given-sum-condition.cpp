class Solution {
public:
    const int mod = 1e9+7;
    int fastpow(int a,int b){
    int res=1;
    while (b>0){
        if(b&1)res=((long long)res*(long long)a)%mod;
        a=((long long)a*(long long)a)%mod;
        b=b>>1;
    }
    return res%mod;
}

    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0,r = n-1;
        sort(nums.begin(),nums.end());
        int ans=0;
        while(l<=r){
            if(nums[r]+nums[l]>target)r--;
            else{
                int cur_len = (r-l);
                //cout<<cur_len<<endl;
                ans=(ans+fastpow(2,cur_len))%mod;
                l++;
            }
        }
        
        return ans;
        
    }
};