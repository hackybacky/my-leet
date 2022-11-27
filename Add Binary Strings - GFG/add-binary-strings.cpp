//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	string addBinary(string A, string B)
	{
	    // your code here
	    
	    reverse(A.begin() , A.end());
	    reverse(B.begin() , B.end());
	    if(B.size() > A.size()){
	        swap(A , B);
	    }
	    int n = A.size();
	    int carry = 0;
	    string ans = "";
	    for(int i =0 ;i < n ;i++){
	        int cur = 0;
	        if(i >= B.size() )    {
	            cur = 0;
	        }
	        else{
	            cur = (B[i] - '0');
	        }
	        
	        int su = ((A[i] - '0') + carry + cur ) ;
	        int d = su % 2;
	        ans += (d + '0');
	        carry = (su > 1);
	    }
	    
	    if(carry ){
	        ans += "1";
	    }
	    string fans = "";
	    bool flag = true;
	    for(int i = ans.size() - 1 ; i >=0 ; i--){
	        if(flag and ans[i] == '0'){
	            continue;
	        }
	        flag = false;
	        fans += ans[i];
	    }
	   // reverse(ans.begin() , ans.end());
	    return fans;
	}
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string A, B; cin >> A >> B;
		Solution ob;
		cout << ob.addBinary (A, B);
		cout << "\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends