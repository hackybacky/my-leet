//{ Driver Code Starts
//Initial template for C++ 
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function template for C++

class Solution{
  public:
    
    vector<int> KMP(string & s){
        int n = s.size();
        vector<int>pref(n  , 0);
        for(int i = 1 ; i < n ;i++){
            
            int j = (i - 1 >=0 ? pref[i - 1] : 0);
            
            while(j > 0 and s[j] != s[i]){
                j = pref[j - 1];
            }
            if(s[i] == s[j]){
                j++;
            }
            pref[i] = j;
        }
        
        return pref;
    }
	int lps(string s) {
	    // Your code goes here
	    vector<int> v = KMP(s);
	    
	   
	    return v.back();
	    
	    
	}
};

//{ Driver Code Starts.

int main() 
{
   

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}

// } Driver Code Ends