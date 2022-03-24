class Solution {
public:
    int numRescueBoats(vector<int>& a, int limit) {
        
        int n = a.size();
        
        
        sort(a.begin(),a.end());
        
        int j=n-1;
        int i = 0;
        int ans=0;
        while(i<=j){
            
            if(a[i]+a[j]<=limit){
                i++;
                
            }
            
            ans++,j--;
            
            
        }
        return ans;
    }
};