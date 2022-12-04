//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    string rearrange (string s, int N)
    {
        // your code here
        vector<int>a(26, 0) , b (26 , 0);
        int v = 0;
        for(auto it : s){
            if(it == 'a' or it == 'e' or it == 'i' or it == 'o' or it == 'u'){
                a[it - 'a']++;
                v++;
            }
            else{
                b[it - 'a']++;
            }
        }
        
        int i = 0 , j = 0;
        int n = s.size();
        if((n - v) > v ){
            swap(a , b);
        }
        if( abs(n - 2* v) > 1  ){
            return "-1";
        }
        string ans = "";
        for(int k = 0 ;k < n  ;k++){
            
            if(k % 2 == 0){
                while(i < 26 and a[i] == 0){
                    i++;
                }
                ans += char('a' + i);
                a[i]--;
            }
            else{
                while(j < 26 and b[j] == 0){
                    j++;
                }
                ans += char('a' + j);
                b[j]--;
            }
        
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		Solution ob;
		cout << ob.rearrange (s, n) << endl;
	}
}
// Contributed By: Pranay Bansal

// } Driver Code Ends