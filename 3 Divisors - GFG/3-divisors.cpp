//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> prime;
    void sieve(){
        int n = 1e6 ;
        vector<int>p(n + 1, 1);
        for(int i = 2 ; i * i <= n ;i++){
            if(p[i]){
                for(int j = i * i ; j <= n ;j += i){
                    p[j] = 0;
                }
            }
        }
        for(int i = 2 ;i <= n ;i++){
            if(p[i]){
                prime.push_back(i);
            }
        }
    }
    vector<int> threeDivisors(vector<long long> query, int q)
    {
        // Write your code here
        sieve();
        vector<int>lans;
        for(auto it : query){
            int n = it;
            int sq = sqrt(it);
            if(sq == 1){
                lans.push_back(0);
                continue;
            }
            auto it2 = upper_bound(prime.begin() , prime.end() , sq);
            int ans = it2 - prime.begin();
            lans.push_back(ans);
        }
        return lans;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while(t--){
        int q;cin>>q;
        vector<long long> query(q);
        for(int i=0;i<q;i++){
            cin>>query[i];
        }
        Solution ob;
            
        vector<int> ans = ob.threeDivisors(query,q);
        for(auto cnt : ans) {
            cout<< cnt << endl;
        }
    }
    return 0;
}
// } Driver Code Ends