class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int maxi = 1 , mini = 1;
        int ans = INT_MIN;
        for(auto it : nums){
            
            ans = max({mini * it , maxi * it , ans , it});
            int nmaxi  = max({it , mini * it , maxi * it});
            int nmini = min({it , mini * it , maxi * it} );
            mini = nmini;
            maxi = nmaxi;
            
        }
        return ans;
    }
};