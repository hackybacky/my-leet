// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
        bool check(int mid , int n ){
            int cnt=0;
            int f = 5;
            while(f<=mid){
                cnt+=mid/f;
                f=f*5;
            }
            return cnt>=n;
        }
        int findNum(int n)
        {
        //complete the function here
            int l=0,r=5*n;
            
            while(l<=r){
                int mid =(l+r)/2;
                
                int cnt=0;
                if(check(mid,n))r=mid-1;
                else l=mid+1;
            }
            return l;
        }
};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}  // } Driver Code Ends