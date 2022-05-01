// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int superPrimes(int n)
	{
	    // Your code goes here
	    vector<int>prime;
	    vector<bool>primes(n+1,true);
	    for(int i=2; i*i<=n; i++){
	        if(primes[i]==true){
	            for(int j=i*i; j<=n;j+=i){
	                primes[j]=false;
	            }
	        }
	    }
	    for(int i=2; i<=n; i++)if(primes[i])prime.push_back(i);
	    int ans=0;
	   // cout<<prime.size()<<endl;
	    for(int i=2;i<prime.size(); i++){
	       if(primes[prime[i]-2])ans++;
	       // next:;
	       // cout<<prime[i]<<endl;
	    }
	    return ans;
	}
};

// { Driver Code Starts.

int main() 
{

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
   		Solution ob;
   		cout << ob.superPrimes(n) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends