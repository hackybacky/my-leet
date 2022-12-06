//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
    vector<int> x = {1, -1, 0, 0};
vector<int> y = {0, 0, 1, -1};
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    queue<vector<int>> q;
	    
	    int n = grid.size();
	    int m = grid[0].size();
	    vector<vector<int>> dis(n , vector<int>(m, INT_MAX/2));
	    for(int i = 0 ; i < n ; i++){
	        for(int j = 0 ; j < m; j++){
	            if(grid[i][j] == 1)
	             q.push({i , j});
	        }
	    }
	    while(!q.empty()){
	        auto f = q.front();
	        q.pop();
	        int curx = f[0] , cury = f[1];
	        if(grid[curx][cury] == 1){
	            dis[curx][cury] = 0;
	        }
	        for(int i = 0 ; i < 4 ;i++){
	            int nx = curx + x[i];
	            int ny = cury + y[i];
	            if(nx < 0 or ny < 0 or nx >= n or ny >= m)continue;
	            int d = dis[curx][cury] + 1;
	            if(dis[nx][ny] > d ){
	                dis[nx][ny] = d;
	                q.push({nx , ny});
	            }
	            
	        }
	        
	    }
	    return dis;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends