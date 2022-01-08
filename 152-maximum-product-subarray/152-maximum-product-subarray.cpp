class Solution {
public:
    int maxProduct(vector<int>& a) {
        int n=a.size();
        int ans=a[0];
        int maxproduct=1;
        int minproduct=1;
        for(int i=0; i< n ;i++){
            
            if(a[i]<0)swap(maxproduct,minproduct);
            
            maxproduct=max(maxproduct*a[i],a[i]);
            minproduct=min(minproduct *a[i],a[i]);
            ans=max({ans,maxproduct,minproduct});
            
            
            
            
        }
        return ans;
    }
};