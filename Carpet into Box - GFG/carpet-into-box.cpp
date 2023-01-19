//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int move(int a , int b){
        int cnt = 0;
        while(a > b){
            a /= 2;
            cnt++;
        }
        return cnt;
    }
    int carpetBox(int A, int B, int C, int D){
        //code here
        int dif = (A - C) + (B - D);
        int dif2 = (A - D) + (B - C);
        if((A <= C and B <= D ) or (A <= D and B <= C))return 0;
        
        
        int ans = move(A , C);
        ans += move(B , D);
        int ans2 = move(A , D) + move(B , C);
        ans = min(ans , ans2);
        return ans;
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        
        Solution ob;

        int ans = ob.carpetBox(A,B,C,D);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends