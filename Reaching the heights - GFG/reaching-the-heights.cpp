// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


vector<int> reaching_height(int n, int a[]) ;

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
	    int n; 
	    cin >> n;
	    int a[n];
	    for (int i = 0; i < n; i++) 
	        cin >> a[i];
	    vector<int> v;
	    v = reaching_height(n,a);
	
	    if(v.size()==1 and v[0] == -1){
	        cout << "Not Possible\n";
	    }
	    else{
	    for(int i:v)
	        cout << i << " ";
	    cout << endl;}
	    
	}
	return 0;
}// } Driver Code Ends


//User function Template for C++

vector<int> reaching_height(int n, int a[]) {
    vector<int> v;
    if (n == 1) {
        v.push_back(a[0]);
        return v;
    }
    
    std::sort(a, a+n);
    if (a[0] == a[n-1]) {
        v.push_back(-1);
        return v;
    }
    int hi = n-1;
    int lo = 0;
    bool is_hi = true;
    while (lo <= hi) {
        if (is_hi) {
            v.push_back(a[hi]);
            hi--;
        } else {
            v.push_back(a[lo]);
            lo++;
        }
        is_hi ^= 1;
    }
    return v;
}