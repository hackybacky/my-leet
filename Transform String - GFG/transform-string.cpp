// { Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    int transform (string A, string B)
    {   int n = A.size();
        //code here.
        map<int , int > mpa , mpb;
        for(auto it : A)mpa[it]++;
        for(auto it : B)mpb[it]++;
        if(mpa != mpb){
            return -1;
        }
        int ans = 0;
        int j = n - 1 ;
        int cur = 0;
        for(int i = n - 1 ;i >=0 and j >= 0  ;i--){
            if(A[i] == B[j]){
                ans+= cur;
                j--;
                cur = 0;
            }
            else{
                cur++;
            }
            
        }
        ans += cur;
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