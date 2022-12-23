//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
    public:
    map<char , vector<char>> graph;
    map<char  , bool > vis;
    void check(char node){
        vis[node] = 1;
        for(auto it : graph[node]){
            if(vis[it])continue;
            check(it);
        }
    }
    int isCircle(int N, vector<string> A)
    {
        // code here
        // eularian cycle
        map<char , int>indeg , outdeg;
        set<char > st;
        for(auto it : A){
            char a = it[0];
            char b = it.back();
            st.insert(a);
            st.insert(b);
            graph[a].push_back(b);
            indeg[b]++;
            outdeg[a]++;
        }
        
        for(auto it : indeg){
            if(it.second != outdeg[it.first])return false;
        }
        int d = 0;
        for(auto it : st){
            if(!vis[it]){
                check(it);
                d++;
            }
        }
        
        return d <= 1;
        
        
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<string> A;
        string s;
        
        for(int i = 0;i < N; i++)
        {
            cin>>s;
            A.push_back(s);
        }
        
        Solution ob;
        cout<<ob.isCircle(N, A)<<endl;
    }
    return 0;
}
// } Driver Code Ends