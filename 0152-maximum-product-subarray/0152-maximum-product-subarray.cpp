class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int maxi = 1 , mini = 1;
        int ans = INT_MIN;
        for(auto it : nums){
            if(it < 0)swap(maxi , mini);
            
            maxi = max(it , maxi * it);
            mini = min(it , mini * it);
            ans = max(maxi , ans);
            
        }
        return ans;
    }
};