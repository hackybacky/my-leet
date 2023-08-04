//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    int N ;
    vector<int> x = {1, -1, 0, 0};
vector<int> y = {0, 0, 1, -1};
vector<char > dir = {'D' , 'U' , 'R' , 'L'};
vector<string>ans;
    void recur(int r , int c , vector<vector<int>>&m , string &cur){
        if(r == N - 1 and c == N - 1){
            ans.push_back(cur);
            return;
        }
        
        for(int k = 0 ; k < 4 ; k++){
            int nx = x[k] + r;
            int ny = y[k] + c;
            if(nx < 0 or ny < 0 or nx >= N or ny >= N or m[nx][ny] == 0)continue;
            m[nx][ny] = 0;
            cur += dir[k];
            recur(nx , ny , m , cur);
            cur.pop_back();
            m[nx][ny] = 1;
        }
    
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        N = n;
        string cur = "";
        if(m[0][0] == 0)return {};
        m[0][0] = 0;
        recur(0 , 0 , m , cur);
        return ans;
        
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends