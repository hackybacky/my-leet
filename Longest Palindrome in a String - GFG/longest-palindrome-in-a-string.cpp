//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    pair<int , int > palin(string &s , int i , int j){
        
        int len = 0;
        
        while(i >=0 and j < s.size()){
            if(s[i] == s[j]){
                len++;
                i-- , j++;
            }
            else{
                break;
            }
        }
        
        return make_pair(len , i + 1);
    }
    string longestPalin (string s) {
        // code here
        
        int n = s.size();
        int ans = 0;
        string cur = "";
        for(int i = 0 ; i < n ;i++){
            
            auto p = palin(s , i , i);
            auto p2 = palin(s , i , i + 1);
            int len = p.first;
            int len2 = p2.first;
            
            int ans2 = len * 2 - 1;
            int ans3 = len2 * 2;
            if(ans < ans2 ){
                int start = p.second;
                ans = ans2 ;
                cur = s.substr(start , ans2);
            }
            if(ans < ans3){
                int start = p2.second;
                cur = s.substr(start , ans3);
                ans = ans3;
            }
            // cout << len << " "<< len2 << endl;
        }
        return cur;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends