class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int>ans(n , 0);
        vector<int>lis;
        for(int i = 0 ; i < n ; i++){
            auto it = upper_bound(lis.begin() , lis.end() , obstacles[i]);
            if(it == lis.end()){
                lis.push_back(obstacles[i]);
                ans[i] = lis.size();
            }
            else{
                *it = obstacles[i];
                ans[i] = it - lis.begin() ;
                ans[i]++;
            }
        }
        return ans;
    }
};