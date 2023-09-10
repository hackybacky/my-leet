class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        int ans = 0;
        for(int i = 1 ; i <= 100; i++){
            for(auto it : nums){
                int start = it[0] , end = it[1];
                if(start <= i and end >= i){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};