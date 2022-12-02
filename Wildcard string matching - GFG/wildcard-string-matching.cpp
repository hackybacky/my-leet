//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    public:
    int dp[1001][1001];
    int match(int i , int j , string & a , string & b){
        if(i == a.size() and j == b.size() ){
            return 1;
        }
        if(i == a.size()){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = 0;
        if(j == b.size()){
            if(a[i] != '*'){
                ans = 0;
            }
            else{
                ans = match(i + 1 , j , a , b);
            }
            
        }
        else{
            if(a[i] == '*' ){
                ans = match(i + 1, j +1 , a , b) or match(i , j + 1, a ,b) or match(i + 1, j , a, b);
            }
            else if(a[i] == '?' or a[i] == b[j]){
                ans = match(i + 1, j + 1, a ,b) ;
            }
        }
        return dp[i][j] = ans;
    }
    bool match(string wild, string pattern)
    {
        // code here
        memset(dp , -1 ,sizeof(dp));
        return match(0 , 0 , wild , pattern);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        if(ob.match(wild, pattern))
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends