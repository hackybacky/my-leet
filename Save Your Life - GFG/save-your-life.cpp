//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
      string maxSum(string w,char x[], int b[],int n){
          // code here        
          
          map<char , int > mp;
          for(int i = 0 ; i < n ; i++){
              mp[x[i]] = b[i];
          }
          int fans = INT_MIN , sum = 0 ;
          string fs = "";
          string ans = "";
          for(int i = 0 ; i < w.size() ; i++){
              int cur = 0;
              if(mp.find(w[i]) == mp.end()){
                  cur = int(w[i]);
              }
              else{
                  cur = mp[w[i]];
              }
              sum += cur;
              
              
              ans += w[i];
              if(fans < sum){
                  fans = sum ;
                  fs = ans;
              } 
              if(sum < 0){
                  sum = 0;
                  ans = "";
              }
              
          }
          return fs;
      }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends