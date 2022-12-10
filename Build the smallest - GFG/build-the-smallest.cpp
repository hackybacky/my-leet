//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string buildLowestNumber(string num, int k);
// Driver program to test above function
int main()
{
    int t,n;
    string str;
    cin>>t;
    while(t--)
    {
    cin>>n;
    cin>>str;
    cout << buildLowestNumber(str, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends


string buildLowestNumber(string num, int k)
{
    //code here.
    
    stack<char> st;
    for(auto it : num){
        char c = it;
        while(!st.empty() and st.top() > c and k ){
            st.pop();
            k--;
        }
        st.push(c);
    }
    
    while(k-- and !st.empty()){
        st.pop();
    }
    string ans = "";
    
    while(!st.empty()){
        
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin() , ans.end());
    for(int i = 0 ;i < ans.size() ;i++){
        if(ans[i] != '0'){
            return string(ans.begin() + i , ans.end());
        }
    }
    // cout << "dfsa" << endl;
    return "0";
}