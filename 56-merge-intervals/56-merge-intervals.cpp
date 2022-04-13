class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int last=intervals[0][1];
        int first = intervals[0][0];
        vector<vector<int>>ans;
        for(int i=1; i<intervals.size(); i++){
            if(last>=intervals[i][0]){
                last=max(intervals[i][1],last);
            }
            else{
                ans.push_back({first,last});
                first=intervals[i][0];
                last = intervals[i][1];
            }
        }
        ans.push_back({first,last});
        return ans;
    }
};