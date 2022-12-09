//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long numOfWays(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends


//Function to find out the number of ways we can place a black and a 
//white Knight on this chessboard such that they cannot attack each other.
long long numOfWays(int N, int M)
{
    // write code here
      int moves1[] = {-2, -2, 2, 2, 1, -1, 1, -1};
        int moves2[] = {-1, 1, -1, 1, -2, -2, 2, 2};
    long long ans = 0;
    long long total = N * M;
    const long long mod = 1e9 + 7;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ;j  < M ; j++){
            int cnt = 0;
            for(int k = 0 ; k < 8 ;k++){
                int x = moves1[k];
                int y = moves2[k];
                if( i +x >= 0 and i + x < N and j + y < M and j + y >=0){
                    cnt++;
                }
            }
            ans = (ans + (total - 1 - cnt + mod)% mod)% mod;
        }
    }
    return ans;
}