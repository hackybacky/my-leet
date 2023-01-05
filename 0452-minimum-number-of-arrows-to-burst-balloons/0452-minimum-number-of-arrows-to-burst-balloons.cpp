class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin() , points.end());
        
        int last = points[0][1];
        
        int ans = 1;
        int n = points.size();
        for(int i = 1 ; i < n ; i++){
            int start = points[i][0] , end = points[i][1];
            if(last < start){
                ans++;
                last = end;
            }
            else last = min(last , end);
        }
        return ans;
    }
};