// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<int> x = {1, -1, 0, 0};
	vector<int> y = {0, 0, 1, -1};
    
    int ans;
    int n ,m;
    void recur(int curx, int cury , vector<vector<int>>matrix,int xd,int yd,int curd){
        // matrix[curx][cury]=0;
        
        if(curx == xd and cury == yd){
            ans=max(ans,curd);
            //  cout<<"hello"<<endl;
            return ;
        }
        for(int i=0;i<4; i++){
            int nx = curx + x[i];
            int ny = cury + y[i];
            if(nx<0 or ny<0 or ny>=m or nx>=n or matrix[nx][ny]==0)continue;
            matrix[nx][ny]=0;
            recur(nx,ny ,matrix , xd ,yd,curd+1);
            matrix[nx][ny]=1;
            
            
        }
        
        
        
    }
    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd)
    {
        // code here
        n=matrix.size();
        m = matrix[0].size();
        ans=INT_MIN;
        
        if(matrix[xs][ys]!=0){
            matrix[xs][ys]=0;
            recur(xs,ys,matrix,xd,yd,0);
        }
        if(ans==INT_MIN)return -1;
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends