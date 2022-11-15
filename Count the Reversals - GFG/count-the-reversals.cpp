//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends



int countRev (string s)
{
    // your code here
    if(s.size() % 2 == 1){
        return -1;
    }
    int ans = 0;
    stack<char > st;
    for(auto it : s){
        if(it == '{'){
            st.push('{');
        }
        else{
            if(st.empty()){
                ans++;
                st.push('{');
            }
            else{
                st.pop();
            }
        }
    }
    
    return ans + st.size() / 2;
    
}