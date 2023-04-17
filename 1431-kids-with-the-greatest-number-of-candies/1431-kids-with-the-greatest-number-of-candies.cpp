class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<bool> ans(n , false);
        int maxi  = *max_element(candies.begin() , candies.end());
        for(int i = 0 ; i < n; i++){
            if(candies[i] + extraCandies >= maxi){
                ans[i] = true;
            }
        }
        return ans;
    }
};