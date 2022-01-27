class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        
        int n=nums.size();
        n/=2;
       vector<vector<int>> a_val(n+1);
        vector<int> a, b;
        
        for(int i=0;i<n; i++){
            a.push_back(nums[i]);
            b.push_back(nums[n+i]);
        }
        //for(auto it : b)cout<<it<<endl;
        for(int mask=0; mask<(1<<n); mask++){
            int cur=0;
            int set=0;
            for(int i=0;i<n;i++){
                if((1<<i)&mask){
                      cur+=a[i];
                    set++;
                }
                else cur-=a[i];
            }
            a_val[set].push_back(cur);
            
        }
        
        for(auto &it :a_val){
            sort(it.begin(),it.end());
        }
        
        int ans=1e9;
        
        for(int mask=0 ; mask<(1<<n); mask++){
            int cur=0;
            int fd=0;
            int set=0;
            int diff=0;
            for(int i=0; i<n ;i++){
                if(mask & (1<<i)){
                    cur+=b[i];
                    set++;
                    diff+=b[i];
                }
                else fd+=b[i],
                diff-=b[i];
            }
            int key=n-set;
             auto it = lower_bound(a_val[key].begin(),a_val[key].end(), -diff); 
            if (it != a_val[key].begin()) ans = min(ans, abs(diff + *prev(it))); 
            if (it != a_val[key].end()) ans = min(ans, abs(diff + *it)); 
            
            
            
            
        }
        
        
        return ans;
        
        
    }
};