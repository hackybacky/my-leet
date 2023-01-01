//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

typedef long long int  ll;
const int mod = 1e9 + 7;
ll modadd(ll a, ll b, ll m = mod) {
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
 
ll modsub(ll a, ll b, ll m = mod) {
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}

ll modmul(ll a, ll b, ll m = mod) {
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}

const ll N = 1e5 + 7;
 
vector<ll> fact(N);
vector<ll> invfact(N);
vector<ll> inv(N);


 
void factInverse() {
    fact[0] = 1;
    fact[1] = 1;
    invfact[0] = 1;
    invfact[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < N; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
        inv[i] = mod - (inv[mod % i] * (mod / i) % mod);
        invfact[i] = (inv[i] * invfact[i - 1]) % mod;
    }
}
 
ll nCr(ll n, ll r) {
    if (r > n) {
        return 0;
    }
    return modmul(modmul(fact[n], invfact[r]), invfact[n - r]);
}




class Solution{
	public:
	int compute_value(int n)
	{
	    // Code here
	    factInverse();
	    int ans = 0;
	    for(int i = 0 ;i <= n ; i++){
	        ans = modadd(modmul(nCr(n , i) , nCr(n ,  i)), ans);
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.compute_value(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends