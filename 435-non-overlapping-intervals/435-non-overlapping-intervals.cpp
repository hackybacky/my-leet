class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b) {
	return a[1]<b[1];
}
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        
        int f = intervals[0][1];
        int ans=0;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<f){
                ans++;
            }
            else{
                f=intervals[i][1];
            }
        }
        return ans;
    }
};