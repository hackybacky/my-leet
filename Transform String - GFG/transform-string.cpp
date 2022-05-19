// { Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    int transform (string A, string B)
    {
        //code here.
        int  j=B.size();
        string a=A;
        string b = B;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        if(a!=b)return -1;
        j--;
        int ans=0;
        for(int i=j;i>=0;i--){
            if(A[i]!=B[j])ans++;
            else j--;
        }
        return ans;
    }
};


// { Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}  // } Driver Code Ends