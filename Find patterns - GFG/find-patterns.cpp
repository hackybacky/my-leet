//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int numberOfSubsequences(string s, string w){
        // code here 
        
        map<int , bool > vis;
        int ans = 0 ;
        int n = s.size();
        for(int i = 0 ; i < n ;i++){
            int k = 0;
            for(int j = 0 ;j < n ; j++){
                if(s[j] == w[k] and vis[j] == 0){
                    k++;
                    vis[j] = 1;
                }
                if(k == w.size()){
                    ans++;
                    break;
                }
                
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S,W;
        cin >> S >> W;
        Solution ob;
        cout << ob.numberOfSubsequences(S,W) << endl;
    }
    return 0; 
} 


// } Driver Code Ends