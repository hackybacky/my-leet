//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         // Code here
         
         sort(intervals.begin() , intervals.end());
         
         int start = intervals[0][0];
         int finish = intervals[0][1];
         vector<vector<int>>ans;
         int n = intervals.size();
         for(int i = 0 ; i < n  ; i++){
            int cur_start = intervals[i][0];
            int cur_end = intervals[i][1];
            if(cur_start <= finish){
                finish = max(cur_end , finish);
            }
            else{
                ans.push_back({start , finish});
                start = cur_start;
                finish = cur_end;
            }
         }
         ans.push_back({start , finish});
         return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends