class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n  = nums.size();
        vector<long long int>pf(n,0);
        pf[0]=nums[0];
        for(int i=1 ; i<n; i++)pf[i]+=pf[i-1]+nums[i];
        long long int ans=0;
        for(int i=0;i<n;i++){
            
            int cur = i;
            int l=0,r=i+1;
            int last=-1;
            while(l<=r){
                long long mid = (l+r)/2;
                
                long long int su = pf[i]-(i-mid>=0?pf[i-mid]:0);
                // if(cur==1)cout<<su<<" "<<mid<<endl;
                long long int cur_ans = su*mid;
                if(cur_ans<k){
                    last=mid;
                    l=mid+1;
                }
                else r=mid-1;
            }
            // cout<<last<<endl;
            if(last!=-1)ans+=last;
        }
        return ans;
        
    }
};