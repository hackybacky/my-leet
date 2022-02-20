class Solution {
public:
    static bool cmp(vector<int>a ,vector<int> b){
        return a[0]<b[0] or (a[0]==b[0] and a[1]>b[1]);
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        
        int ans=0;
        sort(intervals.begin(),intervals.end(),cmp);
        int last=-1;
        int n=intervals.size();
        for(int i=0; i<n; i++){
            if(last>=intervals[i][1]){
                ans++;
            }
            else{
                last=max(last,intervals[i][1]);
            }
        }
        return n-ans;
    }
};