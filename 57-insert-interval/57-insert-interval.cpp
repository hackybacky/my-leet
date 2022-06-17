class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& interval) {
        
        vector<vector<int>>ans;
        
        int i=0;
        int n = intervals.size();
        while(i<n and intervals[i][1]<interval[0]){
            ans.push_back(intervals[i]);
            i++;
        }
        
        while(i<n and intervals[i][0]<=interval[1]){
            interval[0]=min(interval[0],intervals[i][0]);
            interval[1]=max(interval[1],intervals[i][1]);
            i++;
        }
        ans.push_back(interval);
        
        while(i<n){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};