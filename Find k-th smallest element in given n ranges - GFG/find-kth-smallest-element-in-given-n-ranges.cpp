//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public :
    static bool cmp (vector<int>a , vector<int>b){
        return a[0] < b[0] or (a[0] == b[0] and a[1] > b[1]);
    }
    vector<vector<int>> merge(vector<vector<int>> range){
        sort(range.begin() , range.end() , cmp);
        vector<vector<int>> fa;
        int first = range[0][0] , end = range[0][1];
        
        for(auto it : range){
            int f = it[0];
            int s = it[1];
            if(f <= end){
                end = max(end ,s );
            }
            else{
                fa.push_back({first , end});
                first = f;
                end =s ;
            }
        }
        fa.push_back({first , end});
        return fa;
    }
    vector<int>kthSmallestNum(vector<vector<int>>&range, vector<int>queries){
        //Write your code here
        map<int , int > mp;
        
        int len = 1;
        range = merge(range);
        for(auto it : range){
            // cout << it[0] << " "<< it[1] << endl;
        }
        int first ;
        for(auto it : range){
            mp[len] = it[0];
            
            len += it[1] - it[0] + 1;
        }
        first = range[0][0];
        vector<int> ans;
        for(auto it : queries){
            int a = it;
            auto it2 = mp.lower_bound(it);
            
            if(a >= len  ){
                ans.push_back(-1);
                continue;
            }
            if(a == 1){
                ans.push_back(first);
                continue;
            }
            if(it2 != mp.begin()){
                int f = 0;
                if(it2 != mp.end())
                f = (*it2).first;
                if(it2 == mp.end() or f > a){
                    it2 = prev(it2);
                }
                f = (*it2).first;
                int s = (*it2).second;
                int cur = s + (a - f);
                ans.push_back(cur);
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
	    int n;
	    cin >> n;
	    vector<vector<int>>range(n, vector<int>(2, 0));
	    for(int i = 0 ; i < n; i++){
	        cin >> range[i][0] >> range[i][1];
	    }
	    int q;
	    cin >> q;
	    vector<int>queries;
	    for(int i = 0 ; i < q; i++){
	        int x;
            cin >> x;
	        queries.push_back(x);
	    }
	    Solution ob;
	    vector<int>ans = ob.kthSmallestNum(range, queries);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout << endl;
	}
	return 0;
}

// } Driver Code Ends