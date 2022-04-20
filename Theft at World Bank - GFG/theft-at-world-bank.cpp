// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	long double maximumProfit(int N, long long C, vector<long long> w, vector<long long> p){
    // Code here.
          vector<pair<double,long long int >> v;   
        //loop to generate vector of profit per weight 
    for(int i=0;i<N;i++){
        int x=sqrt(w[i]);
        if(pow(x,2)==w[i])
            continue;
        else{
            v.push_back({(double)p[i]/w[i],w[i]});
        }
    }
    //sort p vector in ascending order of profit per weight ratio
    sort(v.begin(),v.end(),greater<pair<double,long long int>>());
    double profit=0;
    for(int i=0;i<=p.size();i++){
        if(v[i].second<=C){
            profit+=v[i].first*v[i].second;
            C-=v[i].second;
        }
        else if(v[i].second>C){
            profit+=C*v[i].first;
            break;
        }
    }
    return profit;
}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		long long C;
		cin >> n >> C;
		vector<long long > w(n), p(n);
		for(int i = 0; i < n; i++){
		    cin >> w[i] >> p[i];
		}
		Solution ob;
		long double ans = ob.maximumProfit(n, C, w, p);
		cout << fixed << setprecision(3) << ans << "\n";
	}  
	return 0;
}  // } Driver Code Ends