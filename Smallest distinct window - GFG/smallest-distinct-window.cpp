// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here   
        
        map<char,int>mp;
        for(auto it:str){
            mp[it]=1;
        }
        int i=0,j=0;
        int n = str.size();
        map<char,int>m;
        int ans=INT_MAX;
        
        while(j<n){
             m[str[j]]++;
            
            if(mp.size()==m.size()){
                while(mp.size()==m.size()){
                    m[str[i]]--;
                    if(m[str[i]]==0)m.erase(str[i]);
                    i++;
                }
                ans=min(ans,j-i+2);
            }
            j++;
        }
        return ans;
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}  // } Driver Code Ends