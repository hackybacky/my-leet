class Solution {
public:
    int minSwaps(vector<int>& a) {
        int n=a.size();
        vector<int> prefix(2*n+1,0);
       
        
        int cnt=accumulate(a.begin(),a.end(),0);
        
        
        for(int i =0; i<2 * n ;i++){
            prefix[i+1]=a[i%n]+prefix[i];
            
        }
        int ans=n;
        for(int i=0; i < n ; i++){
            int cur= prefix[i+cnt]-prefix[i];
            ans=min(ans,cnt-cur);
        }
        
        
        
        return ans;
        
        
    }
};