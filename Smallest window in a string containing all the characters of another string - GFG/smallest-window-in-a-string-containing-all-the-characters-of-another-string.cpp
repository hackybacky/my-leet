//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        
        unordered_map<char , int > mp;
        
        auto dp = mp;
        for(auto it : p){
            mp[it]++;
            dp[it]++;
        }
        int i = 0 , j = 0;
        
        int n = s.size();
        int ans = INT_MAX;
        int cur = 0;
        int starting = -1;
        int total = dp.size();
        while(j < n){
            
            if(dp[s[j]]){
                mp[s[j]]--;
            }
            if(dp[s[j]] and mp[s[j]] == 0){
                cur++;
            }
            // cout << cur << endl;
            while(cur == total){
                if(dp[s[i]]){
                    mp[s[i]]++;
                }
                if(dp[s[i]] and mp[s[i]] > 0){
                    cur--;
                    
                }
                // cout << "df" << endl;
                int len = j - i + 1;
                if(len < ans){
                    ans = len ;
                    starting = i;
                }
                i++;
                
            }
            j++;
                    
        }
        if(starting == -1){
            return "-1";
        }
        return s.substr(starting , ans);
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends