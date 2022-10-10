//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
  public:
    
    void inorder(int i , vector<int>&a , vector<int>&in){
        if(i >= a.size()){
            return ;
        }
        inorder(2 * i + 1 ,a ,  in);
        in.push_back(a[i]);
        inorder(2 * i+ 2 , a , in);
    }
    template<int SZ> struct DSU {
    int parent[SZ], size[SZ];
 int i;
    DSU() {
        for(int i=0; i< SZ; i++) parent[i] = i, size[i] = 1;
    }
 
    int get(int x) {
        if (parent[x] != x) parent[x] = get(parent[x]);
        return parent[x];
    }
 
    void unify(int x, int y) {
        x = get(x); y = get(y);
        if (x == y) return;
         //remove size line for directed graph or tree means next two lines 
        if (size[x] < size[y]) swap(x, y);
            size[x]+=size[y];
        parent[y] = x;
 
    }
};
    int minSwaps(vector<int>&A, int n){
        //Write your code here
        
        vector<int>in;
        inorder(0 , A  ,in);
        vector<int>actual = in;
        // int n = in.size();
        DSU<100001 > dsu;
        sort(actual.begin() , actual.end());
        map<int , int >mp;
        for(int i = 0 ; i < actual.size() ; i++){
            mp[actual[i]] = i;
        }
        int ans = 0;
        for(int i = 0 ; i < actual.size() ; i++){
           if(actual[i] != in[i]){
               dsu.unify(i , mp[in[i]]);
           }
        }
        set<int>s;
        // int ans = 0;
        for(int i = 0 ; i < actual.size() ; i++)s.insert(dsu.get(i));
        for(auto it : s){
            ans += dsu.size[it] - 1;
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
	    vector<int>A(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> A[i];
	    }
	    Solution ob;
	    int ans = ob.minSwaps(A, n);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends