// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool mul(long long num){
        if(num==1)return true;
        if(num%10==0)return mul(num/10);
        return false;
    }
    int n;
    long long cal(long long fir,bool odd ){
        string sn = to_string(fir);
        
        if(odd){
            auto t =sn.substr(0,n/2);
            reverse(t.begin(),t.end());
            return stol(sn+t);
        }
        auto t = sn;
        reverse(t.begin(),t.end());
        return  stol(sn+t);
    }
    
	long long int closestPalindrome(long long int num){
	    // Code here
	    
	    if(num<=9)return num;
	    if(mul(num))return num-1;
	    string sn = to_string(num);
	    n = sn.size();
	    string fir = sn.substr(0,n/2);
	    bool odd=false;
	    if(n&1){
	        fir+=sn[n/2];
	        odd=true;
	    }
	    
	    
	    long long ans =INT_MAX;
	    long long fn = stol(fir);
	    long long lans=num;
	    for(int i=-1; i<=1; i++){
	        long long cur = cal( fn+i ,odd );
	        if(abs(num-cur)<ans)lans=cur,ans=abs(num-cur);
	    }
	    return lans;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int num;
		cin >> num;
		Solution obj;
		long long int ans = obj.closestPalindrome(num);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends