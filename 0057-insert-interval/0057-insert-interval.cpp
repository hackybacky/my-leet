class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        int i = 0 ;
        vector<vector<int>>ans;
        // int i ;
        int n = intervals.size();
        for( i = 0 ; i < n ;i++){
            if(intervals[i][1] >= newInterval[0])break;
            ans.push_back(intervals[i]);
        }
        
        for( ; i < n and intervals[i][0] <= newInterval[1];i++){
            newInterval[0] = min(newInterval[0] , intervals[i][0]);
            newInterval[1] = max(intervals[i][1] , newInterval[1]);
        }
        ans.push_back(newInterval);
        for(; i < n ; i++){
            ans.push_back(intervals[i]);
        }
        return ans;
    }
};