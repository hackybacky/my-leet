class Solution {
public:
    static bool cmp(vector<int>a ,vector<int> b){
        return a[0]<b[0] or (a[0]==b[0] and a[1]>b[1]);
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        map<int,bool>check;
        int ans=0;
        sort(intervals.begin(),intervals.end(),cmp);
        for(int i=0; i<intervals.size(); i++){
            int a=intervals[i][0],b=intervals[i][1];
            for(int j=i+1; j<intervals.size();j++){
                if(check[j])continue;
                int da = intervals[j][0],db=intervals[j][1];
                if(db<=b and !check[j]){
                    check[j]=true;
                    //cout<<j<<" "<<i<<" "<<db<<endl;
                    ans++;
                }
                if(da>b)break;
            }
        }
        return intervals.size()-ans;
    }
};